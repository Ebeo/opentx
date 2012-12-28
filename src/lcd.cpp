/*
 * Authors (alphabetical order)
 * - Bertrand Songis <bsongis@gmail.com>
 * - Bryan J. Rentoul (Gruvin) <gruvin@gmail.com>
 * - Cameron Weeks <th9xer@gmail.com>
 * - Erez Raviv
 * - Jean-Pierre Parisy
 * - Karl Szmutny <shadow@privy.de>
 * - Michael Blandford
 * - Michal Hlavinka
 * - Pat Mackenzie
 * - Philip Moss
 * - Rob Thomson
 * - Romolo Manfredini <romolo.manfredini@gmail.com>
 * - Thomas Husterer
 *
 * open9x is based on code named
 * gruvin9x by Bryan J. Rentoul: http://code.google.com/p/gruvin9x/,
 * er9x by Erez Raviv: http://code.google.com/p/er9x/,
 * and the original (and ongoing) project by
 * Thomas Husterer, th9x: http://code.google.com/p/th9x/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include "open9x.h"

uint8_t displayBuf[DISPLAY_BUF_SIZE];
#define DISPLAY_END (displayBuf+sizeof(displayBuf))
#define ASSERT_IN_DISPLAY(p) assert((p) >= displayBuf && (p) < DISPLAY_END)

void lcd_clear()
{
  memset(displayBuf, 0, sizeof(displayBuf));
}

void lcd_img(xcoord_t x, uint8_t y, const pm_uchar * img, uint8_t idx, LcdFlags att)
{
  const pm_uchar *q = img;
#if defined(LCD260)
  xcoord_t w   = pgm_read_byte(q++);
  if (w == 255) w += pgm_read_byte(q++);
#else
  uint8_t w    = pgm_read_byte(q++);
#endif
  uint8_t hb   = (pgm_read_byte(q++)+7)/8;
  bool    inv  = (att & INVERS) ? true : (att & BLINK ? BLINK_ON_PHASE : false);
  q += idx*w*hb;
  for (uint8_t yb = 0; yb < hb; yb++) {
    uint8_t *p = &displayBuf[ (y / 8 + yb) * DISPLAY_W + x ];
    for (xcoord_t i=0; i<w; i++){
      uint8_t b = pgm_read_byte(q++);
      ASSERT_IN_DISPLAY(p);
#if defined(PCBX9D)
      uint8_t val = inv ? ~b : b;
      if (!(att & GREY1))
        *p = val;
      if (!(att & GREY2))
        *(p+DISPLAY_PLAN_SIZE) = val;
      p++;
#else
      *p++ = inv ? ~b : b;
#endif
    }
  }
}

uint8_t lcdLastPos;

void lcd_putcAtt(xcoord_t x, uint8_t y, const unsigned char c, LcdFlags mode)
{
  uint8_t *p = &displayBuf[ y / 8 * DISPLAY_W + x ];

#if defined(PCBX9D)
  const pm_uchar *q = (c < 0xC0) ? &font_5x7[(c-0x20)*5+4] : &font_5x7_extra[(c-0xC0)*5+4];
#else
  const pm_uchar *q = &font_5x7[(c-0x20)*5+4];
#endif

  bool inv = false;
  if (mode & BLINK) {
    if (BLINK_ON_PHASE) {
      if (mode & INVERS)
        inv = true;
      else
        return;
    }
  }
  else if (mode & INVERS) {
    inv = true;
  }

  if (mode & DBLSIZE) {
    /* each letter consists of ten top bytes followed by
     * by ten bottom bytes (20 bytes per * char) */
    q = &font_10x14[((uint16_t)c-0x20)*20];
    for (int8_t i=11; i>=0; i--) {
      if (mode & CONDENSED && i<=1) break;
      uint8_t b1=0, b2=0;
      if (i>1) {
        b1 = pgm_read_byte(q++); /*top byte*/
        b2 = pgm_read_byte(q++); /*top byte*/
      }
      if (inv) {
        b1=~b1;
        b2=~b2;
      }   
      if(&p[DISPLAY_W+1] < DISPLAY_END) {
        ASSERT_IN_DISPLAY(p);
        ASSERT_IN_DISPLAY(p+DISPLAY_W);
        p[0]=b1;
        p[DISPLAY_W] = b2;
        p++;
      }   
    }   
  }
#if defined(PCBX9D)
  else if (mode & MIDSIZE) {
    /* each letter consists of ten top bytes followed by
     * by ten bottom bytes (20 bytes per * char) */
    q = &font_8x10[((uint16_t)c-0x20)*16];
    for (int8_t i=9; i>=0; i--) {
      uint8_t b1=0, b2=0;
      if (mode & CONDENSED && i<=1) break;
      if (i!=0 && i!=9) {
        b1 = pgm_read_byte(q++); /*top byte*/
        b2 = pgm_read_byte(q++); /*top byte*/
      }
      if (inv) {
        b1=~b1;
        b2=~b2;
      }
      uint8_t ym8 = (y % 8);
      if (&p[DISPLAY_W+1] < DISPLAY_END) {
        ASSERT_IN_DISPLAY(p);
        ASSERT_IN_DISPLAY(p+DISPLAY_W);
        *p = (*p & (~(0xff << ym8))) + (b1 << ym8);
        uint8_t *r = p + DISPLAY_W;
        if (r<DISPLAY_END) {
          if (ym8)
            *r = (*r & (~(0xff >> (8-ym8)))) + (b1 >> (8-ym8));
          *r = (*r & (~(0x0f << ym8))) + ((b2&0x0f) << ym8);
          if (ym8) {
            r = r + DISPLAY_W;
            if (r<DISPLAY_END)
              *r = (*r & (~(0x0f >> (8-ym8)))) + ((b2&0x0f) >> (8-ym8));
          }
        }
        p++;
      }
    }
  }
  else if (mode & SMLSIZE) {
    q = &font_4x6[((uint16_t)c-0x20)*5+4];
    uint8_t ym8 = (y % 8);
    p += 4;
    for (int8_t i=4; i>=0; i--) {
      uint8_t b = pgm_read_byte(q--);
      if (inv) b = ~b & 0x7f;

      if (p<DISPLAY_END) {
        ASSERT_IN_DISPLAY(p);
        *p = (*p & (~(0x7f << ym8))) + (b << ym8);
        if (ym8) {
          uint8_t *r = p + DISPLAY_W;
          if (r<DISPLAY_END)
            *r = (*r & (~(0x7f >> (8-ym8)))) + (b >> (8-ym8));
        }
      }
      p--;
    }
  }
  else if (mode & TINSIZE) {
    q = &font_3x5[((uint16_t)c-0x2D)*3+2];
    uint8_t ym8 = (y % 8);
    p += 2;
    for (int8_t i=2; i>=0; i--) {
      uint8_t b = pgm_read_byte(q--);
      if (inv) b = ~b & 0x3f;

      if (p<DISPLAY_END) {
        ASSERT_IN_DISPLAY(p);
        *p = (*p & (~(0x3f << ym8))) + (b << ym8);
        if (ym8) {
          uint8_t *r = p + DISPLAY_W;
          if (r<DISPLAY_END)
            *r = (*r & (~(0x3f >> (8-ym8)))) + (b >> (8-ym8));
        }
      }
      p--;
    }
  }
#endif
  else {
    uint8_t condense=0;

    if (mode & CONDENSED) {
      *p = inv ? ~0 : 0;
      condense=1;
    }

    uint8_t ym8 = (y % 8);
    p += 5;
    for (int8_t i=5; i>=0; i--) {
      uint8_t b = (i!=5 ? pgm_read_byte(q--) : 0);
      if (inv) b = ~b;

      if (condense && i==1) {
        /*condense the letter by skipping column 4 */
        continue;
      }

      if (p<DISPLAY_END) {
        ASSERT_IN_DISPLAY(p);
        *p = (*p & (~(0xff << ym8))) + (b << ym8);
        if (ym8) {
          uint8_t *r = p + DISPLAY_W;
          if (r<DISPLAY_END)
            *r = (*r & (~(0xff >> (8-ym8)))) + (b >> (8-ym8));
        }
#ifdef BOLD_FONT
        if (mode & BOLD) {
          ASSERT_IN_DISPLAY(p+1);
          if (inv)
            *(p+1) &= (b << ym8);
          else
            *(p+1) |= (b << ym8);
        }
#endif
      }
      p--;
    }
  }
}

void lcd_putc(xcoord_t x, uint8_t y, const unsigned char c)
{
  lcd_putcAtt(x, y, c, 0);
}

void lcd_putsiAtt(xcoord_t x, uint8_t y,const pm_char * s,uint8_t idx, LcdFlags flags)
{
  uint8_t length;
  length = pgm_read_byte(s++);
  lcd_putsnAtt(x,y,s+length*idx,length,flags & ~(BSS|ZCHAR));
}

void lcd_putsnAtt(xcoord_t x, uint8_t y, const pm_char * s, uint8_t len, LcdFlags mode)
{
  while(len!=0) {
    unsigned char c;
    switch (mode & (BSS+ZCHAR)) {
      case BSS:
        c = *s;
        break;
      case ZCHAR:
        c = idx2char(*s);
        break;
      default:
        c = pgm_read_byte(s);
        break;
    }
    if (!c || x>DISPLAY_W-6) break;
    if (c >= 0x20) {
#if defined(PCBX9D)
      if ((mode & MIDSIZE) && ((c>='a'&&c<='z')||(c>='0'&&c<='9'))) {
        lcd_putcAtt(x, y, c, mode);
        x-=1;
      }
      else
#endif
      lcd_putcAtt(x, y, c, mode);
      x += FW;
      if (mode&DBLSIZE) x += FW-1;
      else if (mode&MIDSIZE) x += FW-3;
      else if (mode&SMLSIZE) x -= 1;
    }
    else {
      x += (c*FW/2);
    }
    s++;
    len--;
  }
  lcdLastPos = x;
}

void lcd_putsn(xcoord_t x, uint8_t y, const pm_char * s, uint8_t len)
{
  lcd_putsnAtt(x, y, s, len, 0);
}

void lcd_putsAtt(xcoord_t x, uint8_t y, const pm_char * s, LcdFlags flags)
{
  lcd_putsnAtt(x, y, s, 255, flags);
}

void lcd_puts(xcoord_t x, uint8_t y, const pm_char * s)
{
  lcd_putsAtt(x, y, s, 0);
}

void lcd_putsLeft(uint8_t y, const pm_char * s)
{
  lcd_puts(0, y, s);
}

void lcd_outhex4(xcoord_t x, uint8_t y, uint16_t val)
{
  x+=FWNUM*4;
  for(int i=0; i<4; i++)
  {
    x-=FWNUM;
    char c = val & 0xf;
    c = c>9 ? c+'A'-10 : c+'0';
    lcd_putcAtt(x,y,c,c>='A'?CONDENSED:0);
    val>>=4;
  }
}

void lcd_outdez8(xcoord_t x, uint8_t y, int8_t val)
{
  lcd_outdezAtt(x, y, val);
}

void lcd_outdezAtt(xcoord_t x, uint8_t y, int16_t val, LcdFlags flags)
{
  lcd_outdezNAtt(x, y, val, flags);
}

void lcd_outdezNAtt(xcoord_t x, uint8_t y, int16_t val, LcdFlags flags, uint8_t len)
{
  uint8_t fw = FWNUM;
  int8_t mode = MODE(flags);
  bool dblsize = flags & DBLSIZE;
#if defined(PCBX9D)
  bool midsize = flags & MIDSIZE;
  bool tinsize = flags & TINSIZE;
#else
#define midsize 0
#define tinsize 0
#endif

  bool neg = false;
  if (flags & UNSIGN) { flags -= UNSIGN; }
  else if (val < 0) { neg=true; val=-val; }

  xcoord_t xn = 0;
  uint8_t ln = 2;

  if (mode != MODE(LEADING0)) {
    len = 1;
    uint16_t tmp = ((uint16_t)val) / 10;
    while (tmp) {
      len++;
      tmp /= 10;
    }
    if (len <= mode)
      len = mode + 1;
  }

  if (dblsize) {
    fw += FWNUM;
  }
  else if (midsize) {
    flags |= CONDENSED;
    fw += FWNUM-3;
  }
  else if (tinsize) {
    fw -= 1;
  }
  else {
    if (flags & LEFT) {
      if (mode > 0)
        x += 2;
    }
  }

  if (flags & LEFT) {
    x += len * fw;
    if (neg)
      x += ((dblsize|midsize) ? 7 : FWNUM);
  }

  lcdLastPos = x;
  x -= fw + 1;

  for (uint8_t i=1; i<=len; i++) {
    div_t qr = div((uint16_t)val, 10);
    char c = qr.rem + '0';
    LcdFlags f = flags;
    if (dblsize) {
      if (c=='1' && i==len && xn>x+10) { x+=2; f|=CONDENSED; }
      if ((uint16_t)val >= 1000) { x+=FWNUM; f&=~DBLSIZE; }
    }
    lcd_putcAtt(x, y, c, f);
    if (mode==i) {
      flags &= ~PREC2; // TODO not needed but removes 20bytes, could be improved for sure, check asm
      if (dblsize) {
        xn = x;
        if(c>='1' && c<='3') ln++;
        uint8_t tn = (qr.quot) % 10;
        if (tn==2 || tn==4) {
          if (c=='4') { xn++; }
          else { xn--; ln++; }
        }
      }
      else if (midsize) {
        x -= 3;
        xn = x+1;
      }
      else {
        x--;
        lcd_plot(x, y+6);
        if ((flags&INVERS) && ((~flags & BLINK) || BLINK_ON_PHASE))
          lcd_vline(x, y, 8);
        x--;
      }
    }
    if (dblsize && (uint16_t)val >= 1000 && (uint16_t)val < 10000) x-=2;
    val = qr.quot;
    x-=fw;
  }

  if (xn) {
    if (midsize) {
      if ((flags&INVERS) && ((~flags & BLINK) || BLINK_ON_PHASE))
        lcd_vline(xn+1, y, 12);
      lcd_hline(xn, y+9, 2);
      lcd_hline(xn, y+10, 2);
    }
    else {
      y &= ~0x07;
      lcd_hline(xn, (y & ~0x07)+2*FH-3, ln);
      lcd_hline(xn, y+2*FH-2, ln);
    }
  }

  if (neg) lcd_putcAtt(x, y, '-', flags);
}

#if defined(PCBX9D)
void lcd_mask(uint8_t *p, uint8_t mask, LcdFlags att)
{
  ASSERT_IN_DISPLAY(p);

  if (!(att & GREY1)) {
    if (att & FORCE)
      *p |= mask;
    else if (att & ERASE)
      *p &= ~mask;
    else
      *p ^= mask;
  }

  if (!(att & GREY2)) {
    p += DISPLAY_PLAN_SIZE;
    ASSERT_IN_DISPLAY(p);

    if (att & FORCE)
      *p |= mask;
    else if (att & ERASE)
      *p &= ~mask;
    else
      *p ^= mask;
  }
}
#else
void lcd_mask(uint8_t *p, uint8_t mask, LcdFlags att)
{
  ASSERT_IN_DISPLAY(p);

  if (att & FORCE)
    *p |= mask;
  else if (att & ERASE)
    *p &= ~mask;
  else
    *p ^= mask;
}
#endif

void lcd_plot(xcoord_t x, uint8_t y, LcdFlags att)
{
  uint8_t *p = &displayBuf[ y / 8 * DISPLAY_W + x ];
  if (p<DISPLAY_END)
    lcd_mask(p, BITMASK(y%8), att);
}

void lcd_hlineStip(xcoord_t x, uint8_t y, xcoord_t w, uint8_t pat, LcdFlags att)
{
  if (y >= DISPLAY_H) return;
  if (x+w > DISPLAY_W) { w = DISPLAY_W - x; }

  uint8_t *p  = &displayBuf[ y / 8 * DISPLAY_W + x ];
  uint8_t msk = BITMASK(y%8);
  while(w) {
    if(pat&1) {
      lcd_mask(p, msk, att);
      pat = (pat >> 1) | 0x80;
    }
    else {
      pat = pat >> 1;
    }
    w--;
    p++;
  }
}

void lcd_hline(xcoord_t x, uint8_t y, xcoord_t w, LcdFlags att)
{
  lcd_hlineStip(x, y, w, 0xff, att);
}

#if defined(PCBSTD)
void lcd_vlineStip(xcoord_t x, int8_t y, int8_t h, uint8_t pat)
{
  if (x >= DISPLAY_W) return;
  if (h<0) { y+=h; h=-h; }
  if (y<0) { h+=y; y=0; }
  if (y+h > DISPLAY_H) { h = DISPLAY_H - y; }

  if (pat==DOTTED && !(y%2))
    pat = ~pat;

  uint8_t *p  = &displayBuf[ y / 8 * DISPLAY_W + x ];
  y = y % 8;
  if (y) {
    ASSERT_IN_DISPLAY(p);
    *p ^= ~(BITMASK(y)-1) & pat;
    p += DISPLAY_W;
    h -= 8-y;
  }
  while (h>0) {
    ASSERT_IN_DISPLAY(p);
    *p ^= pat;
    p += DISPLAY_W;
    h -= 8;
  }
  if (h < 0) h += 8;
  if (h) {
    p -= DISPLAY_W;
    ASSERT_IN_DISPLAY(p);
    *p ^= ~(BITMASK(h)-1) & pat;
  }
}
#else
// allows the att parameter...
void lcd_vlineStip(xcoord_t x, int8_t y, int8_t h, uint8_t pat, LcdFlags att)
{
  if (x >= DISPLAY_W) return;
  if (h<0) { y+=h; h=-h; }
  if (y<0) { h+=y; y=0; }
  if (y+h > DISPLAY_H) { h = DISPLAY_H - y; }

  if (pat==DOTTED && !(y%2))
    pat = ~pat;

  uint8_t *p  = &displayBuf[ y / 8 * DISPLAY_W + x ];
  y = y % 8;
  if (y) {
    ASSERT_IN_DISPLAY(p);
    uint8_t msk = ~(BITMASK(y)-1);
    h -= 8-y;
    if (h < 0)
      msk -= ~(BITMASK(8+h)-1);
    lcd_mask(p, msk & pat, att);
    p += DISPLAY_W;
  }
  while (h>=8) {
    ASSERT_IN_DISPLAY(p);
    lcd_mask(p, pat, att);
    p += DISPLAY_W;
    h -= 8;
  }
  if (h>0) {
    ASSERT_IN_DISPLAY(p);
    lcd_mask(p, (BITMASK(h)-1) & pat, att);
  }
}
#endif

void lcd_vline(xcoord_t x, int8_t y, int8_t h)
{
  lcd_vlineStip(x, y, h, 0xff);
}

void lcd_rect(xcoord_t x, uint8_t y, xcoord_t w, uint8_t h, uint8_t pat, LcdFlags att)
{
  lcd_vlineStip(x, y, h, pat);
  lcd_vlineStip(x+w-1, y, h, pat);
  if (~att & ROUND) { x+=1; w-=2; }
  lcd_hlineStip(x, y+h-1, w, pat);
  lcd_hlineStip(x, y, w, pat);
}

void lcd_filled_rect(xcoord_t x, int8_t y, xcoord_t w, uint8_t h, uint8_t pat, LcdFlags att)
{
  for (int8_t i=y; i<y+h; i++) {
    if (i>=0 && i<DISPLAY_H) lcd_hlineStip(x, i, w, pat, att);
    pat = (pat >> 1) + ((pat & 1) << 7);
  }
}

void lcd_invert_line(int8_t y)
{
  uint8_t *p  = &displayBuf[y * DISPLAY_W];
  for (xcoord_t x=0; x<DISPLAY_W; x++) {
    ASSERT_IN_DISPLAY(p);
    *p++ ^= 0xff;
  }
}

void putsTime(xcoord_t x, uint8_t y, putstime_t tme, LcdFlags att, LcdFlags att2)
{
  div_t qr;

  if (tme<0) {
    lcd_putcAtt(x - ((att & DBLSIZE) ? FW+3 : ((att & MIDSIZE) ? FW+1 : FWNUM)), y, '-', att);
    tme = -tme;
  }

  qr = div(tme, 60);

#if defined(PCBX9D)
  if (att & MIDSIZE) {
    div_t qr2 = div(qr.quot, 60);
    LCD_2DOTS(x+2*8-6, y, att);
    lcd_outdezNAtt(x, y, qr2.quot, att|LEADING0|LEFT, 2);
    x += 2*8+1;
  }
#define separator ':'
#elif defined(CPUARM)
  char separator = ':';
  if (tme >= 3600 && (~att & DBLSIZE)) {
    qr = div(qr.quot, 60);
    separator = 'h';
  }
#else
#define separator ':'
#endif

  uint8_t x2, x3;
  if (att&DBLSIZE) {
    x2 = x+2*(FW+FWNUM)-3;
    x3 = x+2*(FW+FWNUM)+FW-2;
  }
  else if (att&MIDSIZE) {
    x2 = x+2*8-6;
    x3 = x+2*8+1;
  }
  else {
    x2 = x+2*FWNUM-1;
    x3 = x+2*FWNUM-1+FW;
  }

#if defined(PCBX9D)
  if (att&MIDSIZE) {
    LCD_2DOTS(x2, y, att);
  }
  else
#endif
  lcd_putcAtt(x2, y, separator, att&att2);
  lcd_outdezNAtt(x, y, qr.quot, att|LEADING0|LEFT, 2);
  lcd_outdezNAtt(x3, y, qr.rem, att2|LEADING0|LEFT, 2);
}

// TODO to be optimized with putsTelemetryValue
void putsVolts(xcoord_t x, uint8_t y, uint16_t volts, LcdFlags att)
{
  lcd_outdezAtt(x, y, (int16_t)volts, (~NO_UNIT) & (att | ((att&PREC2)==PREC2 ? 0 : PREC1)));
  if (~att & NO_UNIT) lcd_putcAtt(lcdLastPos, y, 'v', att&(~INVERS));
}

void putsVBat(xcoord_t x, uint8_t y, LcdFlags att)
{
  putsVolts(x, y, g_vbat100mV, att);
}

void putsStrIdx(xcoord_t x, uint8_t y, const pm_char *str, uint8_t idx, LcdFlags att)
{
  lcd_putsAtt(x, y, str, att);
  lcd_outdezNAtt(lcdLastPos, y, idx, att|LEFT, 2);
  lcd_putsAtt(x, y, str, att);
}

void putsChnRaw(xcoord_t x, uint8_t y, uint8_t idx, LcdFlags att)
{
  if (idx==0)
    lcd_putsiAtt(x, y, STR_MMMINV, 0, att);
  else if (idx<=NUM_STICKS+NUM_POTS+NUM_ROTARY_ENCODERS+NUM_STICKS+1+NUM_SW_SRCRAW+NUM_CYC)
    lcd_putsiAtt(x, y, STR_VSRCRAW, idx-1, att);
  else if (idx<=NUM_STICKS+NUM_POTS+NUM_ROTARY_ENCODERS+NUM_STICKS+1+NUM_SW_SRCRAW+NUM_CYC+NUM_PPM)
    putsStrIdx(x, y, STR_PPM, idx - (NUM_STICKS+NUM_POTS+NUM_ROTARY_ENCODERS+NUM_STICKS+1+NUM_SW_SRCRAW+NUM_CYC), att);
  else if (idx<=NUM_STICKS+NUM_POTS+NUM_ROTARY_ENCODERS+NUM_STICKS+1+NUM_SW_SRCRAW+NUM_CYC+NUM_PPM+NUM_CHNOUT)
    putsStrIdx(x, y, STR_CH, idx - (NUM_STICKS+NUM_POTS+NUM_ROTARY_ENCODERS+NUM_STICKS+1+NUM_SW_SRCRAW+NUM_CYC+NUM_PPM), att);
  else
    lcd_putsiAtt(x, y, STR_VTELEMCHNS, idx-(NUM_STICKS+NUM_POTS+NUM_ROTARY_ENCODERS+NUM_STICKS+1+NUM_SW_SRCRAW+NUM_CYC+NUM_PPM+NUM_CHNOUT), att);
}

void putsMixerSource(xcoord_t x, uint8_t y, uint8_t idx, LcdFlags att)
{
#if defined(PCBX9D)
  if (idx<=NUM_STICKS+NUM_POTS+NUM_ROTARY_ENCODERS+NUM_STICKS+1+NUM_SW_SRCRAW)
    putsChnRaw(x, y, idx, att);
  else if (idx<=NUM_STICKS+NUM_POTS+NUM_ROTARY_ENCODERS+NUM_STICKS+1+NUM_SW_SRCRAW+NUM_CSW)
    putsSwitches(x, y, MAX_PSWITCH + idx-(NUM_STICKS+NUM_POTS+NUM_ROTARY_ENCODERS+NUM_STICKS+1+NUM_SW_SRCRAW), att);
  else
    putsChnRaw(x, y, idx-NUM_CSW, att);
#else
  if (idx<=NUM_STICKS+NUM_POTS+NUM_ROTARY_ENCODERS+NUM_STICKS+1+NUM_SW_SRCRAW)
    putsChnRaw(x, y, idx, att);
  else if (idx<=NUM_STICKS+NUM_POTS+NUM_ROTARY_ENCODERS+NUM_STICKS+1+NUM_SW_SRCRAW+MAX_SWITCH)
    putsSwitches(x, y, idx-(NUM_STICKS+NUM_POTS+NUM_ROTARY_ENCODERS+NUM_STICKS+1+NUM_SW_SRCRAW), att);
  else
    putsChnRaw(x, y, idx-MAX_SWITCH, att);
#endif
}

void putsChnLetter(xcoord_t x, uint8_t y, uint8_t idx, LcdFlags attr)
{
  lcd_putsiAtt(x, y, STR_RETA123, idx-1, attr);
}

void putsModelName(xcoord_t x, uint8_t y, char *name, uint8_t id, LcdFlags att)
{
  uint8_t len = sizeof(g_model.name);
  while (len>0 && !name[len-1]) --len;
  if (len==0) {
    putsStrIdx(x, y, STR_MODEL, id+1, att|LEADING0);
  }
  else {
    lcd_putsnAtt(x, y, name, sizeof(g_model.name), ZCHAR|att);
  }
}

void putsSwitches(xcoord_t x, uint8_t y, int8_t idx, LcdFlags att)
{
  if (idx == 0)
    return lcd_putsiAtt(x, y, STR_MMMINV, 0, att);
  if (att & SWONOFF) {
    if (idx == SWITCH_ON)
      return lcd_putsiAtt(x, y, STR_OFFON, 1, att);
    if (idx == SWITCH_OFF)
      return lcd_putsiAtt(x, y, STR_OFFON, 0, att);
  }
  if (idx < 0) {
    lcd_vlineStip(x-2, y, 8, 0x5E/*'!'*/);
    idx = -idx;
  }
  if (idx > MAX_SWITCH) {
    idx -= ((att & SWONOFF) ? MAX_SWITCH+1 : MAX_SWITCH);
    char suffix = 'm';
#if defined(CPUARM)
    if (idx > MAX_SWITCH+1) {
      suffix = 's';
      idx -= MAX_SWITCH+1;
      if (idx > MAX_PSWITCH) {
        suffix = 'l';
        idx -= MAX_PSWITCH;
      }
    }
#endif
    if (~att & SWCONDENSED) lcd_putcAtt(x+3*FW, y, suffix, att);
  }
  lcd_putsiAtt(x, y, STR_VSWITCHES, idx-1, att);
}

#ifdef FLIGHT_PHASES
void putsFlightPhase(xcoord_t x, uint8_t y, int8_t idx, LcdFlags att)
{
  if (idx==0) { lcd_putsiAtt(x, y, STR_MMMINV, 0, att); return; }
  if (idx < 0) { lcd_vlineStip(x-2, y, 8, 0x5E/*'!'*/); idx = -idx; }
  if (att & CONDENSED)
    lcd_outdezNAtt(x+FW*1, y, idx-1, (att & ~CONDENSED), 1);
  else
    putsStrIdx(x, y, STR_FP, idx-1, att);
}
#endif

void putsCurve(xcoord_t x, uint8_t y, int8_t idx, LcdFlags att)
{
  if (idx < 0) {
    lcd_putcAtt(x-1*FW, y, '!', att);
    idx = -idx + 6;
  }
  if (idx < CURVE_BASE)
    lcd_putsiAtt(x, y, STR_VCURVEFUNC, idx, att);
  else
    putsStrIdx(x, y, PSTR("c"), idx-CURVE_BASE+1, att);
}

void putsTmrMode(xcoord_t x, uint8_t y, int8_t mode, LcdFlags att)
{
  if (mode < 0) {
    mode = TMR_VAROFS - mode - 1;
    lcd_putcAtt(x-1*FW, y, '!', att);
  }
  else if (mode < TMR_VAROFS) {
    lcd_putsiAtt(x, y, STR_VTMRMODES, mode, att);
    return;
  }

  putsSwitches(x, y, mode-(TMR_VAROFS-1), att);
}

void putsTrimMode(xcoord_t x, uint8_t y, uint8_t phase, uint8_t idx, LcdFlags att)
{
  int16_t v = getRawTrimValue(phase, idx);

  if (v > TRIM_EXTENDED_MAX) {
    uint8_t p = v - TRIM_EXTENDED_MAX - 1;
    if (p >= phase) p++;
    lcd_putcAtt(x, y, '0'+p, att);
  }
  else {
    putsChnLetter(x, y, idx+1, att);
  }
}

#if defined(ROTARY_ENCODERS)
void putsRotaryEncoderMode(xcoord_t x, uint8_t y, uint8_t phase, uint8_t idx, LcdFlags att)
{
#if defined(EXTRA_ROTARY_ENCODERS)
  int16_t v;
  if(idx < (NUM_ROTARY_ENCODERS - NUM_ROTARY_ENCODERS_EXTRA))
    v = phaseaddress(phase)->rotaryEncoders[idx];
  else
    v = g_model.rotaryEncodersExtra[phase][idx - (NUM_ROTARY_ENCODERS - NUM_ROTARY_ENCODERS_EXTRA)];
#else
  int16_t v = phaseaddress(phase)->rotaryEncoders[idx];
#endif

  if (v > ROTARY_ENCODER_MAX) {
    uint8_t p = v - ROTARY_ENCODER_MAX - 1;
    if (p >= phase) p++;
    lcd_putcAtt(x, y, '0'+p, att);
  }
  else {
    lcd_putcAtt(x, y, 'a'+idx, att);
  }
}
#endif

void lcdSetContrast()
{
  lcdSetRefVolt(g_eeGeneral.contrast);
}
