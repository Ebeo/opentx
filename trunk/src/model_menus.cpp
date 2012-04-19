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

#define WCHART 32
#define X0     (128-WCHART-2)
#define Y0     32

enum EnumTabModel {
  e_ModelSelect,
  e_Model,
#ifdef HELI
  e_Heli,
#endif
#ifdef FLIGHT_PHASES
  e_PhasesAll,
#endif
  e_ExposAll,
  e_MixAll,
  e_Limits,
  e_CurvesAll,
  e_CustomSwitches,
  e_FunctionSwitches,
#ifdef FRSKY
  e_Telemetry,
#endif
#ifdef TEMPLATES
  e_Templates
#endif
};

void menuProcModelSelect(uint8_t event);
void menuProcModel(uint8_t event);
#ifdef HELI
void menuProcHeli(uint8_t event);
#endif
#ifdef FLIGHT_PHASES
void menuProcPhasesAll(uint8_t event);
#endif
void menuProcExposAll(uint8_t event);
void menuProcMixAll(uint8_t event);
void menuProcLimits(uint8_t event);
void menuProcCurvesAll(uint8_t event);
void menuProcCustomSwitches(uint8_t event);
void menuProcFunctionSwitches(uint8_t event);
#ifdef FRSKY
void menuProcTelemetry(uint8_t event);
#endif
#ifdef TEMPLATES
void menuProcTemplates(uint8_t event);
#endif
void menuProcExpoOne(uint8_t event);

const MenuFuncP_PROGMEM menuTabModel[] PROGMEM = {
  menuProcModelSelect,
  menuProcModel,
#ifdef HELI
  menuProcHeli,
#endif
#ifdef FLIGHT_PHASES
  menuProcPhasesAll,
#endif
  menuProcExposAll,
  menuProcMixAll,
  menuProcLimits,
  menuProcCurvesAll,
  menuProcCustomSwitches,
  menuProcFunctionSwitches,
#ifdef FRSKY
  menuProcTelemetry,
#endif
#ifdef TEMPLATES
  menuProcTemplates
#endif
};

#define COPY_MODE 1
#define MOVE_MODE 2
static uint8_t s_copyMode = 0;
static int8_t s_copySrcRow;
static int8_t s_copyTgtOfs;

inline int8_t eeFindEmptyModel(uint8_t id, bool down)
{
  int8_t i = id;
  for (;;) {
    i = (MAX_MODELS + (down ? i+1 : i-1)) % MAX_MODELS;
    if (!eeModelExists(i)) break;
    if (i == id) return -1; // no free space in directory left
  }
  return i;
}

#ifdef SDCARD
// TODO to be elsewhere if common to many menus
const pm_char * s_sdcard_error = NULL;

bool listSDcardModels()
{
  FILINFO fno;
  DIR dir;
  char *fn;   /* This function is assuming non-Unicode cfg. */
#if _USE_LFN
  static char lfn[_MAX_LFN + 1];
  fno.lfname = lfn;
  fno.lfsize = sizeof lfn;
#endif

  s_menu_count = 0;
  s_menu_flags = BSS;

  FRESULT res = f_opendir(&dir, MODELS_PATH);        /* Open the directory */
  if (res == FR_OK) {
    for (;;) {
      res = f_readdir(&dir, &fno);                   /* Read a directory item */
      if (res != FR_OK || fno.fname[0] == 0) break;  /* Break on error or end of dir */
      if (fno.fname[0] == '.') continue;             /* Ignore dot entry */
#if _USE_LFN
      fn = *fno.lfname ? fno.lfname : fno.fname;
#else
      fn = fno.fname;
#endif
      if (~fno.fattrib & AM_DIR) {                   /* It is a file. */
        char *menu_entry = &s_bss_menu[s_menu_count*MENU_LINE_LENGTH];
        memset(menu_entry, 0, MENU_LINE_LENGTH);
        for (uint8_t i=0; i<MENU_LINE_LENGTH-1; i++) {
          if (fn[i] == '.')
            break;
          menu_entry[i] = fn[i];
        }
        s_menu[s_menu_count++] = menu_entry;
        // TODO better handling...
        if (s_menu_count == MENU_MAX_LINES)
          break;
      }
    }
  }

  return s_menu_count;
}

#endif

void menuProcModelSelect(uint8_t event)
{
  TITLE(STR_MENUMODELSEL);

#if !defined(PCBARM)
  // flush eeprom write
  eeFlush();
#endif

  if (s_confirmation) {
    eeDeleteModel(m_posVert); // delete file
    s_confirmation = 0;
    s_copyMode = 0;
  }

#if defined(SDCARD)
  uint8_t _event = (s_warning || s_sdcard_error || s_menu_count) ? 0 : event;
#else
  uint8_t _event = s_warning ? 0 : event;
#endif
  uint8_t _event_ = (IS_RE1_EVT(_event) ? 0 : _event);

  if (s_copyMode || !eeModelExists(g_eeGeneral.currModel)) {
    if ((_event & 0x1f) == KEY_EXIT)
      _event_ -= KEY_EXIT;
  }

  int8_t oldSub = m_posVert;
  if (!check_submenu_simple(_event_, MAX_MODELS-1)) return;
#ifdef NAVIGATION_RE1
  if (m_posVert < 0) m_posVert = 0;
#endif

  int8_t sub = m_posVert;

#ifdef NAVIGATION_RE1
  if (scrollRE > 0 && s_editMode < 0) {
    chainMenu(menuProcModel);
    return;
  }
#endif

  switch(_event)
  {
      case EVT_ENTRY:
        m_posVert = sub = g_eeGeneral.currModel;
        s_copyMode = 0; // TODO only this one?
        s_copyTgtOfs = 0;
        s_copySrcRow = -1;
        s_editMode = -1;
        break;
      case EVT_KEY_LONG(KEY_EXIT):
        if (s_copyMode && s_copyTgtOfs == 0 && g_eeGeneral.currModel != sub && eeModelExists(sub)) {
          s_warning = STR_DELETEMODEL;
          killEvents(_event);
          break;
        }
        // no break
      case EVT_KEY_BREAK(KEY_EXIT):
        if (s_copyMode) {
          sub = m_posVert = (s_copyMode == MOVE_MODE || s_copySrcRow<0) ? (MAX_MODELS+sub+s_copyTgtOfs) % MAX_MODELS : s_copySrcRow; // TODO reset s_copySrcRow?
          s_copyMode = 0; // TODO only this one?
          s_copySrcRow = -1;
          s_copyTgtOfs = 0;
          killEvents(_event);
        }
        break;
#ifdef NAVIGATION_RE1
      case EVT_KEY_BREAK(BTN_REa):
        s_editMode = (s_editMode == 0 && sub == g_eeGeneral.currModel) ? -1 : 0;
        break;
      case EVT_KEY_LONG(BTN_REa):
#endif
      case EVT_KEY_LONG(KEY_MENU):
      case EVT_KEY_BREAK(KEY_MENU):
        if (s_copyMode && (s_copyTgtOfs || s_copySrcRow>=0)) {
          displayPopup(s_copyMode==COPY_MODE ? STR_COPYINGMODEL : STR_MOVINGMODEL);
          eeCheck(true); // force writing of current model data before this is changed

          uint8_t cur = (MAX_MODELS + sub + s_copyTgtOfs) % MAX_MODELS;

          if (s_copyMode == COPY_MODE) {
            if (!eeCopyModel(cur, s_copySrcRow))
              cur = sub;
          }

          s_copySrcRow = g_eeGeneral.currModel; // to update the currModel value
          while (sub != cur) {
            uint8_t src = cur;
            cur = (s_copyTgtOfs > 0 ? cur+15 : cur+1) % MAX_MODELS;
            eeSwapModels(src, cur);
            if (src == s_copySrcRow)
              s_copySrcRow = cur;
            else if (cur == s_copySrcRow)
              s_copySrcRow = src;
          }

          if (s_copySrcRow != g_eeGeneral.currModel) {
            g_eeGeneral.currModel = s_copySrcRow;
            STORE_GENERALVARS;
          }

          s_copyMode = 0; // TODO only this one?
          s_copySrcRow = -1;
          s_copyTgtOfs = 0;
          return;
        }
        else if (_event == EVT_KEY_LONG(KEY_MENU) || IS_RE1_EVT_TYPE(_event, EVT_KEY_LONG)) {
#ifdef NAVIGATION_RE1
          s_editMode = -1;
#endif
          s_copyMode = 0;
          killEvents(event);
          if (g_eeGeneral.currModel != sub) {
#if defined(SDCARD)
            if (eeModelExists(sub)) {
              s_menu[s_menu_count++] = STR_LOAD_MODEL;
              s_menu[s_menu_count++] = STR_ARCHIVE_MODEL;
              s_menu[s_menu_count++] = STR_DELETE_MODEL;;
            }
            else {
              s_menu[s_menu_count++] = STR_CREATE_MODEL;
              s_menu[s_menu_count++] = STR_RESTORE_MODEL;;
            }
#else
            displayPopup(STR_LOADINGMODEL);
            eeCheck(true); // force writing of current model data before this is changed
            g_eeGeneral.currModel = sub;
            STORE_GENERALVARS;
            eeLoadModel(sub);
            return;
#endif
          }
        }
        else if (eeModelExists(sub)) {
          s_copyMode = (s_copyMode == COPY_MODE ? MOVE_MODE : COPY_MODE);
        }
        break;
      case EVT_KEY_FIRST(KEY_LEFT):
      case EVT_KEY_FIRST(KEY_RIGHT):
        if (sub == g_eeGeneral.currModel) {
          chainMenu(_event == EVT_KEY_FIRST(KEY_RIGHT) ? menuProcModel : menuTabModel[DIM(menuTabModel)-1]);
          return;
        }
        AUDIO_WARNING2();
        break;
      case EVT_KEY_FIRST(KEY_UP):
      case EVT_KEY_FIRST(KEY_DOWN):
        if (s_copyMode) {
          int8_t next_ofs = (_event == EVT_KEY_FIRST(KEY_UP) ? s_copyTgtOfs+1 : s_copyTgtOfs-1);
          if (next_ofs == MAX_MODELS || next_ofs == -MAX_MODELS)
            next_ofs = 0;

          if (s_copySrcRow < 0 && s_copyMode==COPY_MODE) {
            s_copySrcRow = oldSub;
            // find a hole (in the first empty slot above / below)
            m_posVert = eeFindEmptyModel(s_copySrcRow, _event==EVT_KEY_FIRST(KEY_DOWN));
            if (m_posVert == (uint8_t)-1) {
              // no free room for duplicating the model
              AUDIO_ERROR();
              m_posVert = oldSub;
              s_copyMode = 0; // TODO only this one?
              s_copyTgtOfs = 0;
              s_copySrcRow = -1;
            }
            next_ofs = 0;
            sub = m_posVert;
          }
          s_copyTgtOfs = next_ofs;
        }
        break;
  }

#if !defined(PCBARM)
  lcd_puts(9*FW-(LEN_FREE-4)*FW, 0, STR_FREE);
  lcd_outdezAtt(  17*FW, 0, EeFsGetFree(),0);
#endif

  DisplayScreenIndex(e_ModelSelect, DIM(menuTabModel), (sub == g_eeGeneral.currModel) ? INVERS : 0);

  if (sub-s_pgOfs < 1) s_pgOfs = max(0, sub-1);
  else if (sub-s_pgOfs > 5)  s_pgOfs = min(MAX_MODELS-7, sub-4);

  for (uint8_t i=0; i<7; i++) {
    uint8_t y=(i+1)*FH;
    uint8_t k=i+s_pgOfs;
    lcd_outdezNAtt(3*FW+2, y, k+1, LEADING0+((!s_copyMode && sub==k) ? INVERS : 0), 2);

    if (s_copyMode == MOVE_MODE || (s_copyMode == COPY_MODE && s_copySrcRow >= 0)) {
      if (k == sub) {
        if (s_copyMode == COPY_MODE) {
          k = s_copySrcRow;
          lcd_putc(20*FW+2, y, '+');
        }
        else {
          k = sub + s_copyTgtOfs;
        }
      }
      else if (s_copyTgtOfs < 0 && ((k < sub && k >= sub+s_copyTgtOfs) || (k-MAX_MODELS < sub && k-MAX_MODELS >= sub+s_copyTgtOfs)))
        k += 1;
      else if (s_copyTgtOfs > 0 && ((k > sub && k <= sub+s_copyTgtOfs) || (k+MAX_MODELS > sub && k+MAX_MODELS <= sub+s_copyTgtOfs)))
        k += 15;
    }

    k %= MAX_MODELS;

    if (eeModelExists(k)) {
#if defined(PCBARM)
      putsModelName(4*FW, y, ModelNames[k], k, 0);
#else
      uint16_t size = eeLoadModelName(k, reusableBuffer.model_name);
      putsModelName(4*FW, y, reusableBuffer.model_name, k, 0);
      lcd_outdezAtt(20*FW, y, size, 0);
#endif
      if (k==g_eeGeneral.currModel && (s_copySrcRow<0 || i+s_pgOfs!=sub)) lcd_putc(1, y, '*');
    }

    if (s_copyMode && sub==i+s_pgOfs) {
      lcd_filled_rect(9, y, DISPLAY_W-1-9, 7);
      lcd_rect(8, y-1, DISPLAY_W-1-7, 9, s_copyMode == COPY_MODE ? SOLID : DOTTED);
    }
  }

  if (s_warning) {
#if defined(PCBARM)
    s_warning_info = ModelNames[sub];
#else
    eeLoadModelName(sub, reusableBuffer.model_name);
    s_warning_info = reusableBuffer.model_name;
#endif
    s_warning_info_len = sizeof(g_model.name);
    displayConfirmation(event);
  }

#if defined(SDCARD)
  if (s_sdcard_error) {
    s_warning = s_sdcard_error;
    displayWarning(event);
    if (s_warning)
      s_warning = NULL;
    else
      s_sdcard_error = NULL;
  }

  if (s_menu_count) {
    const char * result = displayMenu(event);
    if (result) {
      if (s_menu_flags) {
        // The user choosed a file on SD
      }
      else {
        if (result == STR_LOAD_MODEL || result == STR_CREATE_MODEL) {
          displayPopup(STR_LOADINGMODEL);
          eeCheck(true); // force writing of current model data before this is changed
          if (g_eeGeneral.currModel != sub) {
            g_eeGeneral.currModel = sub;
            STORE_GENERALVARS;
            eeLoadModel(sub);
          }
        }
        else if (result == STR_ARCHIVE_MODEL) {
          s_sdcard_error = eeArchiveModel(sub);
          /* TODO as soon as archive and restore do work! if (!s_sdcard_error)
            eeDeleteModel(sub); // delete the model, it's archived!
          */
        }
        else if (result == STR_RESTORE_MODEL) {
          if (!listSDcardModels()) {
            s_sdcard_error = PSTR("No Models on SD");
          }
        }
        else if (result == STR_DELETE_MODEL) {
          s_warning = STR_DELETEMODEL;
        }
      }
    }
  }
#endif
}

void EditName(uint8_t x, uint8_t y, char *name, uint8_t size, uint8_t event, bool active, uint8_t & cur)
{
  lcd_putsnAtt(x, y, name, size, ZCHAR | (active ? ((s_editMode>0) ? 0 : INVERS) : 0));

  if (active) {
    if (s_editMode>0) {
      uint8_t next = cur;
      char c = name[next];
      char v = c;
      if (p1valdiff || event==EVT_KEY_FIRST(KEY_DOWN) || event==EVT_KEY_FIRST(KEY_UP)
          || event==EVT_KEY_REPT(KEY_DOWN) || event==EVT_KEY_REPT(KEY_UP)) {
         v = checkIncDec(event, abs(v), 0, ZCHAR_MAX, 0);
         if (c < 0) v = -v;
         STORE_MODELVARS;
      }

      switch (event) {
        case EVT_KEY_BREAK(KEY_LEFT):
          if (next>0) next--;
          break;
        case EVT_KEY_BREAK(KEY_RIGHT):
          if (next<size-1) next++;
          break;
#ifdef NAVIGATION_RE1
        case EVT_KEY_LONG(BTN_REa):
          if (v==0) {
            s_editMode = 0;
            killEvents(BTN_REa);
            break;
          }
#endif
        case EVT_KEY_LONG(KEY_LEFT):
        case EVT_KEY_LONG(KEY_RIGHT):
          if (v>=-26 && v<=26) {
            v = -v; // toggle case
            STORE_MODELVARS; // TODO optim if (c!=v) at the end
            if (event==EVT_KEY_LONG(KEY_LEFT))
              killEvents(KEY_LEFT);
          }
          break;
      }

      name[cur] = v;
      lcd_putcAtt(x+cur*FW, y, idx2char(v), INVERS);
      cur = next;
    }
    else {
      cur = 0;
    }
  }
}

#undef PARAM_OFS
#define PARAM_OFS (9*FW+2)
void menuProcModel(uint8_t event)
{
  lcd_outdezNAtt(7*FW,0,g_eeGeneral.currModel+1,INVERS+LEADING0,2);

  uint8_t protocol = g_model.protocol;
  MENU(STR_MENUSETUP, menuTabModel, e_Model, (protocol==PROTO_PPM||protocol==PROTO_FAAST||protocol==PROTO_DSM2||protocol==PROTO_PXX ? 12 : 11), {0,ZCHAR|(sizeof(g_model.name)-1),2,2,0,0,0,0,0,NUM_STICKS+NUM_POTS+NUM_ROTARY_ENCODERS-1,2,1});

  uint8_t  sub = m_posVert;
  uint8_t y = 1*FH;

  uint8_t subN = 1;
  if(s_pgOfs<subN) {
    lcd_puts(0*FW, y, STR_NAME);
    EditName(PARAM_OFS, y, g_model.name, sizeof(g_model.name), event, sub==subN, m_posHorz);
#if defined(PCBARM)
    memcpy(ModelNames[g_eeGeneral.currModel], g_model.name, sizeof(g_model.name));
#endif
    if((y+=FH)>7*FH) return;
  } subN++;

  for (uint8_t i=0; i<2; i++) {
    TimerData *timer = &g_model.timers[i];
    if (s_pgOfs<subN) {
      putsStrIdx(0*FW, y, STR_TIMER, i+1);
      putsTmrMode(PARAM_OFS, y, timer->mode, sub==subN && m_posHorz==0 ? ((s_editMode>0) ? BLINK|INVERS : INVERS) : 0);
      putsTime(14*FW, y, timer->val,
          (sub==subN && m_posHorz==1 ? ((s_editMode>0) ? BLINK|INVERS : INVERS):0),
          (sub==subN && m_posHorz==2 ? ((s_editMode>0) ? BLINK|INVERS : INVERS):0) );
      if (sub==subN && (s_editMode>0 || p1valdiff)) {
        uint16_t timer_val = timer->val;
        switch (m_posHorz) {
         case 0:
           CHECK_INCDEC_MODELVAR(event, timer->mode, -2*(MAX_PSWITCH+NUM_CSW), TMR_VAROFS-1+2*(MAX_PSWITCH+NUM_CSW));
           break;
         case 1:
         {
           int8_t min = timer_val/60;
           CHECK_INCDEC_MODELVAR(event, min, 0, 59);
           timer_val = timer_val%60 + min*60;
           break;
         }
         case 2:
         {
           int8_t sec = timer_val%60;
           sec -= checkIncDecModel(event, sec+2, 1, 62)-2;
           timer_val -= sec ;
           if ((int16_t)timer_val < 0) timer_val=0;
           break;
         }
        }
        timer->val = timer_val;
      }
      if ((y+=FH)>7*FH) return;
    } subN++;
  }

  if(s_pgOfs<subN) {
    lcd_putsLeft(    y, STR_ELIMITS);
    menu_lcd_onoff( PARAM_OFS, y, g_model.extendedLimits, sub==subN ) ;
    if(sub==subN) CHECK_INCDEC_MODELVAR(event,g_model.extendedLimits,0,1);
    if((y+=FH)>7*FH) return;
  }subN++;

  if(s_pgOfs<subN) {
    lcd_putsLeft(    y, STR_ETRIMS);
    menu_lcd_onoff( PARAM_OFS, y, g_model.extendedTrims, sub==subN ) ;
    if(sub==subN) CHECK_INCDEC_MODELVAR(event,g_model.extendedTrims,0,1);
    if((y+=FH)>7*FH) return;
  }subN++;

  if(s_pgOfs<subN) {
    lcd_putsLeft(    y, STR_TRIMINC);
    lcd_putsiAtt(PARAM_OFS, y, STR_VTRIMINC, g_model.trimInc, (sub==subN ? INVERS:0));
    if(sub==subN) CHECK_INCDEC_MODELVAR(event,g_model.trimInc,0,4);
    if((y+=FH)>7*FH) return;
  }subN++;

  if(s_pgOfs<subN) {
    lcd_putsLeft(    y, STR_TTRACE);
    int8_t idx = 3;
    if (g_model.thrTraceSrc > NUM_POTS) idx = NUM_STICKS+NUM_ROTARY_ENCODERS+2+3+NUM_PPM+g_model.thrTraceSrc;
    else if (g_model.thrTraceSrc > 0) idx = NUM_STICKS+g_model.thrTraceSrc;
    putsChnRaw(PARAM_OFS, y, idx, (sub==subN ? INVERS:0));
    if (sub==subN) CHECK_INCDEC_MODELVAR(event, g_model.thrTraceSrc, 0, NUM_POTS+NUM_CHNOUT);
    if((y+=FH)>7*FH) return;
  }subN++;

  if(s_pgOfs<subN) {
    lcd_putsLeft(    y, STR_TTRIM);
    menu_lcd_onoff(PARAM_OFS, y, g_model.thrTrim, sub==subN && m_posHorz==0) ;
    if (sub==subN) CHECK_INCDEC_MODELVAR(event,g_model.thrTrim,0,1);
    if((y+=FH)>7*FH) return;
  }subN++;

  if(s_pgOfs<subN) {
    lcd_putsLeft(    y, STR_BEEPCTR);
    for (uint8_t i=0;i<NUM_STICKS+NUM_POTS+NUM_ROTARY_ENCODERS;i++)
      lcd_putsiAtt(PARAM_OFS+i*FW, y, STR_RETA123, i, ((m_posHorz==i) && (sub==subN)) ? BLINK|INVERS : ((g_model.beepANACenter & ((BeepANACenter)1<<i)) ? INVERS : 0 ) );
    if (sub==subN) {
      if((event==EVT_KEY_FIRST(KEY_MENU)) || p1valdiff) {
        killEvents(event);
        s_editMode = 0;
        g_model.beepANACenter ^= ((BeepANACenter)1<<m_posHorz);
        STORE_MODELVARS;
      }
    }
    if((y+=FH)>7*FH) return;
  }subN++;

  if(s_pgOfs<subN) {
    lcd_putsLeft( y, STR_PROTO);
    lcd_putsiAtt(PARAM_OFS, y, STR_VPROTOS, protocol,
                  (sub==subN && m_posHorz==0 ? (s_editMode>0 ? BLINK|INVERS : INVERS):0));
    if (protocol == PROTO_PPM || protocol == PROTO_FAAST) {
      lcd_putsiAtt(PARAM_OFS+4*FW, y, STR_NCHANNELS, g_model.ppmNCH+2, (sub==subN && m_posHorz==1) ? ((s_editMode>0) ? BLINK|INVERS : INVERS) : 0);
      lcd_puts(PARAM_OFS+11*FW, y, PSTR("u"));
      lcd_outdezAtt(PARAM_OFS+11*FW, y, (g_model.ppmDelay*50)+300, ((sub==subN && m_posHorz==2) ? ((s_editMode>0) ? BLINK|INVERS : INVERS) : 0));
    }
#ifdef DSM2
    else if (protocol == PROTO_DSM2) {
      if (m_posHorz > 1) m_posHorz = 1;
      int8_t x = limit((int8_t)0, (int8_t)g_model.ppmNCH, (int8_t)2);
      g_model.ppmNCH = x;
      lcd_putsiAtt(PARAM_OFS+5*FW, y, STR_DSM2MODE, x, (sub==subN && m_posHorz==1) ? ((s_editMode>0) ? BLINK|INVERS : INVERS) : 0);
    }
#endif
    else if (sub==subN) {
      m_posHorz = 0;
    }
    if (sub==subN && (s_editMode>0 || p1valdiff || (protocol!=PROTO_PPM && protocol!=PROTO_FAAST && protocol!=PROTO_DSM2))) { // TODO avoid DSM2 when not defined
      switch (m_posHorz) {
        case 0:
            CHECK_INCDEC_MODELVAR(event, g_model.protocol,0, PROTO_MAX-1);
            break;
        case 1:
#ifdef DSM2
            if (protocol == PROTO_DSM2)
              CHECK_INCDEC_MODELVAR(event, g_model.ppmNCH, 0, 2);
            else
#endif
              CHECK_INCDEC_MODELVAR(event, g_model.ppmNCH, -2, 4);
            break;
        case 2:
            CHECK_INCDEC_MODELVAR(event, g_model.ppmDelay, -4, 10);
            break;
      }
    }
    if((y+=FH)>7*FH) return;
  }subN++;

  if(s_pgOfs<subN) {
    if (protocol == PROTO_PPM || protocol == PROTO_FAAST) {
      lcd_putsLeft( y, STR_PPMFRAME);
      lcd_puts(PARAM_OFS+3*FW, y, STR_MS);
      lcd_outdezAtt(PARAM_OFS, y, (int16_t)g_model.ppmFrameLength*5 + 225, ((sub==subN && m_posHorz==0) ? (s_editMode>0 ? BLINK|INVERS : INVERS) : 0) | PREC1|LEFT);
      lcd_putsiAtt(PARAM_OFS+6*FW, y, STR_POSNEG, g_model.pulsePol, (sub==subN && m_posHorz==1) ? INVERS : 0);
      if(sub==subN && (s_editMode>0 || p1valdiff)) {
        switch (m_posHorz) {
          case 0:
            CHECK_INCDEC_MODELVAR(event, g_model.ppmFrameLength, -20, 20);
            break;
          case 1:
            CHECK_INCDEC_MODELVAR(event, g_model.pulsePol, 0, 1);
            break;
        }
      }
    }
    // TODO port PPM16 ppmDelay from er9x
#if defined(DSM2) || defined(PXX)
    else if (protocol == PROTO_DSM2 || protocol == PROTO_PXX) {
      lcd_putsLeft( y, STR_RXNUM);
      lcd_outdezNAtt(PARAM_OFS-(protocol==PROTO_DSM2 ? 0 : 3*FW), y, g_model.modelId, ((sub==subN && m_posHorz==0) ? (s_editMode>0 ? BLINK|INVERS : INVERS) : 0) | LEADING0|LEFT, 2);

      if (sub==subN && (s_editMode>0 || p1valdiff)) {
        switch (m_posHorz) {
          case 0:
            CHECK_INCDEC_MODELVAR(event, g_model.modelId, 0, 99);
            break;
        }
      }

#if defined(PXX)
      if (protocol == PROTO_PXX) {
        lcd_putsAtt(PARAM_OFS, y, STR_SYNCMENU, ((sub==subN && m_posHorz==1) ? INVERS : 0));
        if (sub==subN && m_posHorz==1) {
          s_editMode = false;
          if (event==EVT_KEY_LONG(KEY_MENU)) {
            // send reset code
            pxxFlag = PXX_SEND_RXNUM;
          }
        }
      }
#endif
    }
#endif
  }
}

static uint8_t s_currIdx;

#ifdef FLIGHT_PHASES

void menuProcPhaseOne(uint8_t event)
{
  PhaseData *phase = phaseaddress(s_currIdx);
  putsFlightPhase(13*FW, 0, s_currIdx+1, 0);

#define MAX_TRIM_LINE (3+NUM_ROTARY_ENCODERS)

  SUBMENU(STR_MENUFLIGHTPHASE, (s_currIdx==0 ? 3 : 5), {ZCHAR|(sizeof(phase->name)-1), 0, MAX_TRIM_LINE, 0/*, 0*/});

  int8_t sub = m_posVert;

  for (uint8_t i=0, k=0, y=2*FH; i<5; i++, k++, y+=FH) {
    if (s_currIdx == 0 && i==1) i = 3;
    uint8_t attr = sub==k ? INVERS : 0;
    switch(i) {
      case 0:
        lcd_putsLeft( y, STR_NAME);
        EditName(10*FW, y, phase->name, sizeof(phase->name), event, attr, m_posHorz);
        break;
      case 1:
        lcd_putsLeft( y, STR_SWITCH);
        putsSwitches(10*FW,  y, phase->swtch, attr);
        if(attr) CHECK_INCDEC_MODELVAR(event, phase->swtch, -MAX_DRSWITCH, MAX_DRSWITCH);
        break;
      case 2:
        lcd_putsLeft( y, STR_TRIMS);
        for (uint8_t t=0; t<NUM_STICKS; t++) {
          putsTrimMode((10+t)*FW, y, s_currIdx, t, (attr && m_posHorz==t) ? ((s_editMode>0) ? BLINK|INVERS : INVERS) : 0);
          if (attr && m_posHorz==t && ((s_editMode>0) || p1valdiff)) {
            int16_t v = getRawTrimValue(s_currIdx, t);
            if (v < TRIM_EXTENDED_MAX) v = TRIM_EXTENDED_MAX;
            v = checkIncDec(event, v, TRIM_EXTENDED_MAX, TRIM_EXTENDED_MAX+MAX_PHASES-1, EE_MODEL);
            if (checkIncDec_Ret) {
              if (v == TRIM_EXTENDED_MAX) v = 0;
              setTrimValue(s_currIdx, t, v);
            }
          }
        }
#if defined(PCBV4)
        for (uint8_t t=0; t<NUM_ROTARY_ENCODERS; t++) {
          putsRotaryEncoderMode((14+t)*FW+2, y, s_currIdx, t, (attr && m_posHorz==4+t) ? ((s_editMode>0) ? BLINK|INVERS : INVERS) : 0);
          if (attr && m_posHorz==4+t && ((s_editMode>0) || p1valdiff)) {
            int16_t v = phaseaddress(s_currIdx)->rotaryEncoders[t];
            if (v < ROTARY_ENCODER_MAX) v = ROTARY_ENCODER_MAX;
            v = checkIncDec(event, v, ROTARY_ENCODER_MAX, ROTARY_ENCODER_MAX+MAX_PHASES-1, EE_MODEL);
            if (checkIncDec_Ret) {
              if (v == ROTARY_ENCODER_MAX) v = 0;
              phaseaddress(s_currIdx)->rotaryEncoders[t] = v;
            }
          }
        }
#endif
        break;
      case 3:
        lcd_putsLeft( y, STR_FADEIN);
        lcd_outdezAtt(10*FW, y, phase->fadeIn, attr|LEFT);
        if(attr) CHECK_INCDEC_MODELVAR(event, phase->fadeIn, 0, 15);
        break;
      case 4:
        lcd_putsLeft( y, STR_FADEOUT);
        lcd_outdezAtt(10*FW, y, phase->fadeOut, attr|LEFT);
        if(attr) CHECK_INCDEC_MODELVAR(event, phase->fadeOut, 0, 15);
        break;
    }
  }
}

void menuProcPhasesAll(uint8_t event)
{
  SIMPLE_MENU(STR_MENUFLIGHTPHASES, menuTabModel, e_PhasesAll, 1+MAX_PHASES+1);

  int8_t sub = m_posVert - 1;

  switch (event) {
    case EVT_KEY_FIRST(KEY_MENU):
#ifdef NAVIGATION_RE1
    case EVT_KEY_BREAK(BTN_REa):
#endif
      if (sub == MAX_PHASES) {
        s_editMode = 0;
        trimsCheckTimer = 200; // 2 seconds
      }
      // no break
    case EVT_KEY_FIRST(KEY_RIGHT):
      if (sub >= 0 && sub < MAX_PHASES) {
        s_currIdx = sub;
        pushMenu(menuProcPhaseOne);
      }
      break;
  }

  uint8_t att;
  for (uint8_t i=0; i<MAX_PHASES; i++) {
    uint8_t y=(i+1)*FH;
    att = i==sub ? INVERS : 0;
    PhaseData *p = phaseaddress(i);
#if defined(EXTRA_ROTARY_ENCODERS)
    putsFlightPhase(0, y, i+1, att|CONDENSED);
#else //EXTRA_ROTARY_ENCODERS
    putsFlightPhase(0, y, i+1, att);
#endif //EXTRA_ROTARY_ENCODERS
#if defined PCBV4
#if defined(EXTRA_ROTARY_ENCODERS)
#define NAME_OFS (-4-12)
#define SWITCH_OFS (-FW/2-2-13)
#define TRIMS_OFS  (-FW/2-4-15)
#define ROTARY_ENC_OFS (0)
#else //!EXTRA_ROTARY_ENCODERS
#define NAME_OFS (-4)
#define SWITCH_OFS (-FW/2-2)
#define TRIMS_OFS  (-FW/2-4)
#define ROTARY_ENC_OFS (2)
#endif //EXTRA_ROTARY_ENCODERS
#else
#define NAME_OFS 0
#define SWITCH_OFS (FW/2)
#define TRIMS_OFS  (FW/2)
#endif
    lcd_putsnAtt(4*FW+NAME_OFS, y, p->name, 6, ZCHAR);
    if (i == 0) {
      lcd_puts(11*FW+SWITCH_OFS, y, STR_DEFAULT);
    }
    else {
      putsSwitches(11*FW+SWITCH_OFS, y, p->swtch, 0);
      for (uint8_t t=0; t<NUM_STICKS; t++) {
        putsTrimMode((15+t)*FW+TRIMS_OFS, y, i, t, 0);
      }
#if defined PCBV4
      for (uint8_t t=0; t<NUM_ROTARY_ENCODERS; t++) {
        putsRotaryEncoderMode((19+t)*FW+TRIMS_OFS+ROTARY_ENC_OFS, y, i, t, 0);
      }
#endif
    }
    if (p->fadeIn || p->fadeOut) 
      lcd_putc(20*FW+2, y, (p->fadeIn && p->fadeOut) ? '*' : (p->fadeIn ? 'I' : 'O'));
  }

  att = (sub==MAX_PHASES && !trimsCheckTimer) ? INVERS : 0;
  lcd_putsAtt(0, 7*FH, STR_CHECKTRIMS, att);
  putsFlightPhase(6*FW, 7*FH, getFlightPhase()+1, att);
}

#endif

#ifdef HELI

void menu_lcd_HYPHINV( uint8_t x,uint8_t y, uint8_t value, uint8_t mode )
{
  lcd_putsiAtt( x, y, STR_MMMINV, value, mode ? INVERS:0) ;
}

void menuProcHeli(uint8_t event)
{
  SIMPLE_MENU(STR_MENUHELISETUP, menuTabModel, e_Heli, 7);

  int8_t  sub    = m_posVert;
  uint8_t y = 1*FH;

  uint8_t subN = 1;
  if(s_pgOfs<subN) {
    lcd_putsLeft(    y, STR_SWASHTYPE);
    lcd_putsiAtt(  14*FW, y, STR_VSWASHTYPE, g_model.swashR.type, (sub==subN ? INVERS:0));
    if(sub==subN) CHECK_INCDEC_MODELVAR(event,g_model.swashR.type,0,SWASH_TYPE_NUM);
    if((y+=FH)>7*FH) return;
  }subN++;

  if(s_pgOfs<subN) {
    lcd_putsLeft(    y, STR_COLLECTIVE);
    putsChnRaw(14*FW, y, g_model.swashR.collectiveSource,  sub==subN ? INVERS : 0);
    if(sub==subN) CHECK_INCDEC_MODELVAR(event, g_model.swashR.collectiveSource, 0, NUM_XCHNRAW);
    if((y+=FH)>7*FH) return;
  }subN++;

  if(s_pgOfs<subN) {
    lcd_putsLeft(    y, STR_SWASHRING);
    lcd_outdezAtt(14*FW, y, g_model.swashR.value,  LEFT|(sub==subN ? INVERS : 0));
    if(sub==subN) CHECK_INCDEC_MODELVAR(event, g_model.swashR.value, 0, 100);
    if((y+=FH)>7*FH) return;
  }subN++;

  if(s_pgOfs<subN) {
    lcd_putsLeft(    y, STR_ELEDIRECTION);
    menu_lcd_HYPHINV( 14*FW, y, g_model.swashR.invertELE, sub==subN ) ;
    if(sub==subN) CHECK_INCDEC_MODELVAR(event, g_model.swashR.invertELE, 0, 1);
    if((y+=FH)>7*FH) return;
  }subN++;

  if(s_pgOfs<subN) {
    lcd_putsLeft(    y, STR_AILDIRECTION);
    menu_lcd_HYPHINV( 14*FW, y, g_model.swashR.invertAIL, sub==subN ) ;
    if(sub==subN) CHECK_INCDEC_MODELVAR(event, g_model.swashR.invertAIL, 0, 1);
    if((y+=FH)>7*FH) return;
  }subN++;

  if(s_pgOfs<subN) {
    lcd_putsLeft(    y, STR_COLDIRECTION);
    menu_lcd_HYPHINV( 14*FW, y, g_model.swashR.invertCOL, sub==subN ) ;
    if(sub==subN) CHECK_INCDEC_MODELVAR(event, g_model.swashR.invertCOL, 0, 1);
    if((y+=FH)>7*FH) return;
  }subN++;
}
#endif

static uint8_t s_curveChan;

typedef int16_t (*FnFuncP) (int16_t x);

int16_t expoFn(int16_t x)
{
  ExpoData *ed = expoaddress(s_currIdx);
  int16_t anas[NUM_STICKS] = {0};
  anas[ed->chn] = x;
  applyExpos(anas);
  return anas[ed->chn];
}

int16_t curveFn(int16_t x)
{
  return intpol(x, s_curveChan);
}

void DrawCurve(FnFuncP fn)
{
  lcd_vlineStip(X0, 0, DISPLAY_H, 0xee);
  lcd_hlineStip(X0-WCHART, Y0, WCHART*2, 0xee);

  for (int8_t xv=-WCHART+1; xv<WCHART; xv++) {
    uint16_t yv = (RESX + fn(xv * (RESX/WCHART))) / 2;
    yv = (DISPLAY_H-1) - yv * (DISPLAY_H-1) / RESX;
    lcd_plot(X0+xv, yv, BLACK);
  }
}

void menuProcCurveOne(uint8_t event)
{
  uint8_t points;
  int8_t *crv;
  static int8_t dfltCrv;
  static uint8_t autoThrStep;

  TITLE(STR_MENUCURVE);
  lcd_outdezAtt(5*FW+1, 0, s_curveChan+1, INVERS|LEFT);
  DISPLAY_PROGRESS_BAR(20*FW+1);

  if (s_curveChan >= MAX_CURVE5) {
    points = 9;
    crv = g_model.curves9[s_curveChan-MAX_CURVE5];
  }
  else {
    points = 5;
    crv = g_model.curves5[s_curveChan];
  }

  switch(event) {
    case EVT_ENTRY:
      dfltCrv = 0;
      autoThrStep = 0;
#ifdef NAVIGATION_RE1
      s_editMode = -1;
#endif
      break;
    case EVT_KEY_FIRST(KEY_MENU):
#ifdef NAVIGATION_RE1
    case EVT_KEY_BREAK(BTN_REa):
#endif
      if (s_editMode<=0) {
        switch (m_posHorz) {
          case 0:
            s_editMode = 1;
            break;
          case 1:
            if (++dfltCrv > 4)
              dfltCrv = -4;
            for (uint8_t i=0; i<points; i++)
              crv[i] = (i-(points/2)) * dfltCrv * 50 / (points-1);
            break;
          case 2:
            crv[0] = -100; crv[points-1] = 100;
            autoThrStep = 1; // the lowest point first
            // s_autoThrValue =
            break;
        }
      }
      break;
    case EVT_KEY_FIRST(KEY_EXIT):
      killEvents(event);
      if (autoThrStep) {
        autoThrStep = 0;
      }
      else if (s_editMode>0) {
        m_posHorz = 0;
        s_editMode = 0;
      }
      else {
        popMenu();
      }
      break;
    case EVT_KEY_REPT(KEY_LEFT):
    case EVT_KEY_FIRST(KEY_LEFT):
      if (!autoThrStep && m_posHorz>0) m_posHorz--;
      break;
    case EVT_KEY_REPT(KEY_RIGHT):
    case EVT_KEY_FIRST(KEY_RIGHT):
      if (!autoThrStep && m_posHorz<((s_editMode>0) ? points-1 : ((g_menuStack[g_menuStackPtr-1] == menuProcExpoOne && expoaddress(s_currIdx)->chn == THR_STICK) ? 2 : 1))) m_posHorz++;
      break;
  }

  for (uint8_t i = 0; i < points; i++) {
    uint8_t x, y;
    if (i>4) {
      x = 8*FW; y = (i-4) * FH;
    }
    else {
      x = 4*FW; y = (i+1) * FH;
    }
    uint8_t attr = (s_editMode>0 && m_posHorz==i) ? INVERS : 0;
    lcd_outdezAtt(x, y, crv[i], attr);
  }

  lcd_puts(0*FW, 7*FH, STR_MODE);
  lcd_putsiAtt(5*FW-2, 7*FH, STR_CURVMODES, (s_editMode<=0)*m_posHorz, s_editMode>0 || autoThrStep ? 0 : INVERS);

  if (s_editMode>0 || autoThrStep) {
    for (uint8_t i=0; i<points; i++) {
      uint8_t xx = X0-1-WCHART+i*WCHART/(points/2);
      uint8_t yy = (DISPLAY_H-1) - (100 + crv[i]) * (DISPLAY_H-1) / 200;

      if (autoThrStep) {
        if (autoThrStep==i+1)
          lcd_filled_rect(xx-1, yy-2, 5, 5); // do selection square
      }
      else if (m_posHorz==i) {
        lcd_filled_rect(xx-1, yy-2, 5, 5); // do selection square
        if (p1valdiff || event==EVT_KEY_FIRST(KEY_DOWN) || event==EVT_KEY_FIRST(KEY_UP) || event==EVT_KEY_REPT(KEY_DOWN) || event==EVT_KEY_REPT(KEY_UP))
          CHECK_INCDEC_MODELVAR( event, crv[i], -100,100);  // edit on up/down
      }
      else {
        lcd_filled_rect(xx, yy-1, 3, 3); // do markup square
      }
    }
  }

  DrawCurve(curveFn);
}

uint8_t getExpoMixCount(uint8_t expo)
{
  uint8_t count = 0;
  uint8_t ch ;

  for(int8_t i=(expo ? MAX_EXPOS-1 : MAX_MIXERS-1); i>=0; i--) {
    ch = (expo ? expoaddress(i)->mode : mixaddress(i)->srcRaw);
    if (ch != 0) {
      count++;
    }
  }
  return count;
}

bool reachExpoMixCountLimit(uint8_t expo)
{
  // check mixers count limit
  if (getExpoMixCount(expo) >= (expo ? MAX_EXPOS : MAX_MIXERS)) {
    s_warning = (expo ? STR_NOFREEEXPO : STR_NOFREEMIXER);
    return true;
  }
  return false;
}

void deleteExpoMix(uint8_t expo, uint8_t idx)
{
  if (expo) {
    memmove(expoaddress(idx), expoaddress(idx+1), (MAX_EXPOS-(idx+1))*sizeof(ExpoData));
    memset(expoaddress(MAX_EXPOS-1), 0, sizeof(ExpoData));
  }
  else {
    memmove(mixaddress(idx), mixaddress(idx+1), (MAX_MIXERS-(idx+1))*sizeof(MixData));
    memset(mixaddress(MAX_MIXERS-1), 0, sizeof(MixData));
  }
  STORE_MODELVARS;
}

static int8_t s_currCh;
void insertExpoMix(uint8_t expo, uint8_t idx)
{
  if (expo) {
    ExpoData *expo = expoaddress(idx);
    memmove(expo+1, expo, (MAX_EXPOS-(idx+1))*sizeof(ExpoData));
    memset(expo,0,sizeof(ExpoData));
    expo->mode = 3; // pos&neg
    expo->chn = s_currCh - 1;
    expo->weight = 100;
  }
  else {
    MixData *mix = mixaddress(idx);
    memmove(mix+1, mix, (MAX_MIXERS-(idx+1))*sizeof(MixData));
    memset(mix,0,sizeof(MixData));
    mix->destCh = s_currCh-1;
    mix->srcRaw = (s_currCh > 4 ? s_currCh : channel_order(s_currCh));
    mix->weight = 100;
  }
  STORE_MODELVARS;
}

void copyExpoMix(uint8_t expo, uint8_t idx)
{
  if (expo) {
    ExpoData *expo = expoaddress(idx);
    memmove(expo+1, expo, (MAX_EXPOS-(idx+1))*sizeof(ExpoData));
  }
  else {
    MixData *mix = mixaddress(idx);
    memmove(mix+1, mix, (MAX_MIXERS-(idx+1))*sizeof(MixData));
  }
  STORE_MODELVARS;
}

void memswap(void *a, void *b, uint8_t size)
{
  uint8_t *x = (uint8_t*)a;
  uint8_t *y = (uint8_t*)b;
  uint8_t temp ;

  while (size--) {
    temp = *x;
    *x++ = *y;
    *y++ = temp;
  }
}

bool swapExpo(uint8_t &idx, uint8_t up)
{
  ExpoData *x = expoaddress(idx);
  int8_t tgt_idx = (up ? idx-1 : idx+1);

  if (tgt_idx < 0) {
    if (x->chn == 0)
      return false;
    x->chn--;
    return true;
  }

  if (tgt_idx == MAX_EXPOS) {
    if (x->chn == NUM_STICKS-1)
      return false;
    x->chn++;
    return true;
  }

  ExpoData *y = expoaddress(tgt_idx);
  if(x->chn != y->chn || !y->mode) {
    if (up) {
      if (x->chn>0) x->chn--;
      else return false;
    }
    else {
      if (x->chn<NUM_STICKS-1) x->chn++;
      else return false;
    }
    return true;
  }

  memswap(x, y, sizeof(ExpoData));
  idx = tgt_idx;
  return true;
}

bool swapMix(uint8_t &idx, uint8_t up)
{
  MixData *x = mixaddress(idx);
  int8_t tgt_idx = (up ? idx-1 : idx+1);

  if (tgt_idx < 0) {
    if (x->destCh == 0)
      return false;
    x->destCh--;
    return true;
  }

  if (tgt_idx == MAX_MIXERS) {
    if (x->destCh == NUM_CHNOUT-1)
      return false;
    x->destCh++;
    return true;
  }

  MixData *y = mixaddress(tgt_idx);
  if(x->destCh != y->destCh) {
    if (up) {
      if (x->destCh>0) x->destCh--;
      else return false;
    }
    else {
      if (x->destCh<NUM_CHNOUT-1) x->destCh++;
      else return false;
    }
    return true;
  }

  memswap(x, y, sizeof(MixData));
  idx = tgt_idx;
  return true;
}

bool swapExpoMix(uint8_t expo, uint8_t &idx, uint8_t up)
{
  bool result = (expo ? swapExpo(idx, up) : swapMix(idx, up));
  if (result)
    STORE_MODELVARS;
  return result;
}

enum ExposFields {
  EXPO_FIELD_WIDTH,
  EXPO_FIELD_EXPO,
  EXPO_FIELD_CURVE,
#ifdef FLIGHT_PHASES
  EXPO_FIELD_FLIGHT_PHASE,
#endif
  EXPO_FIELD_SWITCH,
  EXPO_FIELD_WHEN
};

inline void editExpoVals(uint8_t event, uint8_t which, bool edit, uint8_t y, uint8_t idt)
{
  uint8_t invBlk = edit ? INVERS : 0;

  ExpoData *ed = expoaddress(idt); // TODO volatile

  switch(which)
  {
    case EXPO_FIELD_WIDTH:
      {
        PREPARE_INFLIGHT_BITFIELD(&ed->expo - 1);
        lcd_outdezAtt(9*FW+5, y, ed->weight, invBlk|INFLIGHT(*bitfield));
        if (edit) CHECK_INFLIGHT_INCDEC_MODELVAR_BITFIELD(event, ed->weight, 0, 100, 0, STR_DRWEIGHT, 1);
      }
      break;
    case EXPO_FIELD_EXPO:
      lcd_outdezAtt(9*FW+5, y, ed->expo, invBlk|INFLIGHT(ed->expo));
      if (edit) CHECK_INFLIGHT_INCDEC_MODELVAR(event, ed->expo, -100, 100, 0, STR_DREXPO);
      break;
    case EXPO_FIELD_CURVE:
      putsCurve(6*FW+5, y, ed->curve+(ed->curve >= CURVE_BASE+4 ? 4 : 0), invBlk);
      if (invBlk) CHECK_INCDEC_MODELVAR(event, ed->curve, 0, 15);
      if (invBlk && ed->curve>=CURVE_BASE && event==EVT_KEY_FIRST(KEY_MENU)) {
        s_curveChan = ed->curve - (ed->curve >= CURVE_BASE+4 ? CURVE_BASE-4 : CURVE_BASE);
        pushMenu(menuProcCurveOne);
      }
      break;
#ifdef FLIGHT_PHASES
    case EXPO_FIELD_FLIGHT_PHASE:
      {
        int8_t phase = ed->negPhase ? -ed->phase : +ed->phase;
        putsFlightPhase(6*FW+5, y, phase, invBlk);
        if(edit) { phase = checkIncDecModel(event, phase, -MAX_PHASES, MAX_PHASES); ed->negPhase = (phase < 0); ed->phase = abs(phase); }
      }
      break;
#endif
    case EXPO_FIELD_SWITCH:
      putsSwitches(6*FW+5, y, ed->swtch, invBlk);
      if(edit) CHECK_INCDEC_MODELVAR(event, ed->swtch, -MAX_DRSWITCH, MAX_DRSWITCH);
      break;
    case EXPO_FIELD_WHEN:
      lcd_putsiAtt(6*FW+5, y, STR_VWHEN, 3-ed->mode, invBlk);
      if(edit) ed->mode = 4 - checkIncDecModel(event, 4-ed->mode, 1, 3);
      break;
  }
}

#ifdef FLIGHT_PHASES
#define EXPO_ONE_LINES_COUNT 6
#else
#define EXPO_ONE_LINES_COUNT 5
#endif

void menuProcExpoOne(uint8_t event)
{
  ExpoData *ed = expoaddress(s_currIdx);
  putsChnRaw(7*FW+FW/2,0,ed->chn+1,0);

  SIMPLE_SUBMENU(STR_MENUDREXPO, EXPO_ONE_LINES_COUNT);

  int8_t sub = m_posVert;

  uint8_t y = FH;

  for (uint8_t i=0; i<EXPO_ONE_LINES_COUNT+1; i++) {
    lcd_putsiAtt(0, y, STR_EXPLABELS, i, 0);
    editExpoVals(event, i, sub==i, y, s_currIdx);
    y+=FH;
  }

  DrawCurve(expoFn);

  int16_t x512 = calibratedStick[ed->chn];
  int16_t y512 = expoFn(x512);

  lcd_outdezAtt(20*FW, 6*FH, x512*25/256, 0);
  lcd_outdezAtt(14*FW, 1*FH, y512*25/256, 0);

  x512 = X0+x512/(RESXu/WCHART);
  y512 = (DISPLAY_H-1) - (uint16_t)((y512+RESX)/2) * (DISPLAY_H-1) / RESX;

  lcd_vline(x512, y512-3,3*2+1);
  lcd_hline(x512-3, y512,3*2+1);
}

enum MixFields {
  MIX_FIELD_SOURCE,
  MIX_FIELD_WEIGHT,
  MIX_FIELD_DIFFERENTIAL,
  MIX_FIELD_OFFSET,
  MIX_FIELD_TRIM,
  MIX_FIELD_CURVE,
  MIX_FIELD_SWITCH,
#ifdef FLIGHT_PHASES
  MIX_FIELD_FLIGHT_PHASE,
#endif
  MIX_FIELD_WARNING,
  MIX_FIELD_MLTPX,
  MIX_FIELD_DELAY_UP,
  MIX_FIELD_DELAY_DOWN,
  MIX_FIELD_SLOW_UP,
  MIX_FIELD_SLOW_DOWN,
  MIX_FIELD_COUNT
};

void menuProcMixOne(uint8_t event)
{
  TITLEP(s_currCh ? STR_INSERTMIX : STR_EDITMIX);
  MixData *md2 = mixaddress(s_currIdx) ;
  putsChn(lcd_lastPos+1*FW,0,md2->destCh+1,0);
  SIMPLE_SUBMENU_NOTITLE(MIX_FIELD_COUNT);

  int8_t  sub = m_posVert;

  for (uint8_t k=0; k<7; k++) {
    uint8_t y = (k+1) * FH;
    uint8_t i = k + s_pgOfs;
    uint8_t attr = sub==i ? INVERS : 0;
    switch(i) {
      case MIX_FIELD_SOURCE:
        lcd_puts(2*FW, y, STR_SOURCE);
        putsMixerSource(FW*10, y, md2->srcRaw, attr);
        if(attr) CHECK_INCDEC_MODELVAR(event, md2->srcRaw, 1, NUM_XCHNMIX);
        break;
      case MIX_FIELD_WEIGHT:
        lcd_puts(2*FW, y, STR_WEIGHT);
        lcd_outdezAtt(FW*10, y, md2->weight, attr|LEFT|INFLIGHT(md2->weight));
        if (attr) CHECK_INFLIGHT_INCDEC_MODELVAR(event, md2->weight, -125, 125, 0, STR_MIXERWEIGHT);
        break;
      case MIX_FIELD_DIFFERENTIAL:
        // TODO INFLIGHT
        lcd_puts(2*FW, y, STR_DIFFERENTIAL);
        lcd_outdezAtt(FW*10, y, md2->differential*2, attr|LEFT);
        if (attr) CHECK_INCDEC_MODELVAR(event, md2->differential, -50, 50);
        break;
      case MIX_FIELD_OFFSET:
        lcd_puts(2*FW, y, STR_OFFSET);
        lcd_outdezAtt(FW*10, y, md2->sOffset, attr|LEFT|INFLIGHT(md2->sOffset));
        if (attr) CHECK_INFLIGHT_INCDEC_MODELVAR(event, md2->sOffset, -125, 125, 0, STR_MIXEROFFSET);
        break;
      case MIX_FIELD_TRIM:
        lcd_puts(2*FW, y, STR_TRIM);
        lcd_putsiAtt(FW*10, y, STR_VMIXTRIMS, (md2->srcRaw <= 4) ? md2->carryTrim : 1, attr);
        if (attr) CHECK_INCDEC_MODELVAR( event, md2->carryTrim, TRIM_ON, TRIM_OFFSET);
        break;
      case MIX_FIELD_CURVE:
        lcd_puts(2*FW, y, STR_CURVES);
        putsCurve(FW*10, y, md2->curve, attr);
        if(attr) CHECK_INCDEC_MODELVAR( event, md2->curve, -MAX_CURVE5-MAX_CURVE9, MAX_CURVE5+MAX_CURVE9+7-1);
        if(attr && event==EVT_KEY_FIRST(KEY_MENU) && (md2->curve<0 || md2->curve>=CURVE_BASE)){
          s_curveChan = (md2->curve<0 ? -md2->curve-1 : md2->curve-CURVE_BASE);
          pushMenu(menuProcCurveOne);
        }
        break;
      case MIX_FIELD_SWITCH:
        lcd_puts(  2*FW,y,STR_SWITCH);
        putsSwitches(10*FW,  y,md2->swtch,attr);
        if(attr) CHECK_INCDEC_MODELVAR( event, md2->swtch, -MAX_SWITCH, MAX_SWITCH);
        break;
#ifdef FLIGHT_PHASES
      case MIX_FIELD_FLIGHT_PHASE:
        lcd_puts(  2*FW,y,STR_FPHASE);
        putsFlightPhase(10*FW, y, md2->phase, attr);
        if(attr) CHECK_INCDEC_MODELVAR( event, md2->phase, -MAX_PHASES, MAX_PHASES);
        break;
#endif
      case MIX_FIELD_WARNING:
        lcd_puts(  2*FW,y,STR_WARNING);
        if(md2->mixWarn)
          lcd_outdezAtt(FW*10,y,md2->mixWarn,attr|LEFT);
        else
          lcd_putsAtt(FW*10, y, STR_OFF, attr);
        if(attr) CHECK_INCDEC_MODELVAR( event, md2->mixWarn, 0,3);
        break;
      case MIX_FIELD_MLTPX:
        lcd_puts(  2*FW,y,STR_MULTPX);
        lcd_putsiAtt(10*FW, y, STR_VMLTPX, md2->mltpx, attr);
        if(attr) CHECK_INCDEC_MODELVAR( event, md2->mltpx, 0, 2);
        break;
      case MIX_FIELD_DELAY_UP:
        lcd_puts(  2*FW,y,STR_DELAYUP);
        lcd_outdezAtt(FW*16,y,md2->delayUp,attr);
        if(attr)  CHECK_INCDEC_MODELVAR( event, md2->delayUp, 0,15);
        break;
      case MIX_FIELD_DELAY_DOWN:
        lcd_puts(  2*FW,y,STR_DELAYDOWN);
        lcd_outdezAtt(FW*16,y,md2->delayDown,attr);
        if(attr)  CHECK_INCDEC_MODELVAR( event, md2->delayDown, 0,15);
        break;
      case MIX_FIELD_SLOW_UP:
        lcd_puts(  2*FW,y,STR_SLOWUP);
        lcd_outdezAtt(FW*16,y,md2->speedUp,attr);
        if(attr)  CHECK_INCDEC_MODELVAR( event, md2->speedUp, 0,15);
        break;
      case MIX_FIELD_SLOW_DOWN:
        lcd_puts(  2*FW,y,STR_SLOWDOWN);
        lcd_outdezAtt(FW*16,y,md2->speedDown,attr);
        if(attr)  CHECK_INCDEC_MODELVAR( event, md2->speedDown, 0,15);
        break;
    }
  }
}

static uint8_t s_maxLines = 8;
static uint8_t s_copySrcIdx;
static uint8_t s_copySrcCh;

inline void displayMixerLine(uint8_t row, uint8_t mix, uint8_t ch, uint8_t idx, uint8_t cur, uint8_t event)
{
  uint8_t y = (row-s_pgOfs)*FH;
  MixData *md = mixaddress(mix);
  if (idx > 0)
    lcd_putsiAtt(1*FW+0, y, STR_VMLTPX2, md->mltpx, 0);

  putsMixerSource(4*FW+0, y, md->srcRaw, 0);

  uint8_t attr = ((s_copyMode || cur != row) ? 0 : INVERS);
  lcd_outdezAtt(11*FW+3, y, md->weight, attr);
  if (attr != 0)
    CHECK_INCDEC_MODELVAR(event, md->weight, -125, 125);

  if (md->curve) putsCurve(12*FW+2, y, md->curve);
  if (md->swtch) putsSwitches(15*FW+5, y, md->swtch);

  char cs = ' ';
  if (md->speedDown || md->speedUp)
    cs = 'S';
  if ((md->delayUp || md->delayDown))
    cs = (cs =='S' ? '*' : 'D');
  lcd_putcAtt(18*FW+7, y, cs, 0);
  
#ifdef FLIGHT_PHASES
  if (md->phase)
    putsFlightPhase(20*FW+2, y, md->phase, CONDENSED);
#endif
  
  if (s_copyMode) {
    if ((s_copyMode==COPY_MODE || s_copyTgtOfs == 0) && s_copySrcCh == ch && mix == (s_copySrcIdx + (s_copyTgtOfs<0))) {
      /* draw a border around the raw on selection mode (copy/move) */
      lcd_rect(22, y-1, DISPLAY_W-1-21, 9, s_copyMode == COPY_MODE ? SOLID : DOTTED);
    }

    if (row == cur) {
      /* invert the raw when it's the current one */
      lcd_filled_rect(22, y-1, DISPLAY_W-1-21, 9);
    }
  }
}

inline void displayExpoLine(uint8_t row, uint8_t expo, uint8_t ch, uint8_t idx, uint8_t cur, uint8_t event)
{
  uint8_t y = (row-s_pgOfs)*FH;
  ExpoData *ed = expoaddress(expo);

  uint8_t attr = ((s_copyMode || cur != row) ? 0 : INVERS);
  lcd_outdezAtt(6*FW-2, y, ed->weight, attr);
  if (attr != 0)
    CHECK_INCDEC_MODELVAR(event, ed->weight, 0, 100);
  lcd_outdezAtt(9*FW+1, y, ed->expo, 0);
#ifdef FLIGHT_PHASES
  putsFlightPhase(10*FW, y, ed->negPhase ? -ed->phase : +ed->phase);
#endif
  putsSwitches(13*FW+4, y, ed->swtch, 0); // normal switches
  if (ed->mode!=3) lcd_putc(17*FW, y, ed->mode == 2 ? 126 : 127);//'|' : (stkVal[i] ? '<' : '>'),0);*/
  if (ed->curve) putsCurve(18*FW+2, y, ed->curve+(ed->curve >= CURVE_BASE+4 ? 4 : 0));

  if (s_copyMode) {
    if ((s_copyMode==COPY_MODE || s_copyTgtOfs == 0) && s_copySrcCh == ch && expo == (s_copySrcIdx + (s_copyTgtOfs<0))) {
      /* draw a border around the raw on selection mode (copy/move) */
      lcd_rect(18, y-1, DISPLAY_W-18, 9, s_copyMode == COPY_MODE ? SOLID : DOTTED);
    }
    if (row == cur) {
      /* invert the raw when it's the current one */
      lcd_filled_rect(19, y, DISPLAY_W-20, 7);
    }
  }
}

void menuProcExpoMix(uint8_t expo, uint8_t _event_)
{
  uint8_t _event = (s_warning ? 0 : _event_);
  uint8_t event = _event;
  uint8_t key = (event & 0x1f);

  if (s_copyMode) {
    if (key == KEY_EXIT)
      event -= KEY_EXIT;
  }

  TITLEP(expo ? STR_MENUDREXPO : STR_MIXER);
  lcd_outdezAtt(lcd_lastPos+2*FW+FW/2, 0, getExpoMixCount(expo));
  lcd_puts(lcd_lastPos, 0, expo ? PSTR("/14") : PSTR("/32"));
  SIMPLE_MENU_NOTITLE(menuTabModel, expo ? e_ExposAll : e_MixAll, s_maxLines);

#ifdef NAVIGATION_RE1
  int8_t sub = m_posVert;
#else
  uint8_t sub = m_posVert;
#endif

  switch(_event)
  {
    case EVT_ENTRY:
    case EVT_ENTRY_UP:
      s_copyMode = 0;
      s_copyTgtOfs = 0;
      break;
    case EVT_KEY_LONG(KEY_EXIT):
      if (s_copyMode && s_copyTgtOfs == 0) {
        deleteExpoMix(expo, s_currIdx);
      }
      killEvents(_event);
      // no break
    case EVT_KEY_BREAK(KEY_EXIT):
      if (s_copyTgtOfs) {
        // cancel the current copy / move operation
        if (s_copyMode == COPY_MODE) {
          deleteExpoMix(expo, s_currIdx);
        }
        else {
          do {
            swapExpoMix(expo, s_currIdx, s_copyTgtOfs > 0);
            if (s_copyTgtOfs < 0)
              s_copyTgtOfs++;
            else
              s_copyTgtOfs--;
          } while (s_copyTgtOfs != 0);
        }
        sub = m_posVert = s_copySrcRow;
      }
      s_copyMode = 0;
      s_copyTgtOfs = 0;
      break;
    case EVT_KEY_BREAK(KEY_MENU):
      if (!s_currCh || (s_copyMode && !s_copyTgtOfs)) {
        s_copyMode = (s_copyMode == COPY_MODE ? MOVE_MODE : COPY_MODE);
        s_copySrcIdx = s_currIdx;
        s_copySrcCh = expo ? expoaddress(s_currIdx)->chn+1 : mixaddress(s_currIdx)->destCh+1;
        s_copySrcRow = sub;
        break;
      }
      // no break
#ifdef NAVIGATION_RE1
    case EVT_KEY_BREAK(BTN_REa):
    case EVT_KEY_LONG(BTN_REa):
      if (sub == 0)
        break;
#endif
    case EVT_KEY_LONG(KEY_MENU):
      killEvents(_event);
      if (s_copyTgtOfs) {
        s_copyMode = 0;
        s_copyTgtOfs = 0;
      }
      else {
        if (s_copyMode) s_currCh = 0;
        if (s_currCh) {
          if (reachExpoMixCountLimit(expo)) break;
          insertExpoMix(expo, s_currIdx);
        }
        pushMenu(expo ? menuProcExpoOne : menuProcMixOne);
        s_copyMode = 0;
        return;
      }
      break;
    case EVT_KEY_LONG(KEY_LEFT):
    case EVT_KEY_LONG(KEY_RIGHT):
      if (s_copyMode && !s_copyTgtOfs) {
        if (reachExpoMixCountLimit(expo)) break;
        s_currCh = (expo ? expoaddress(s_currIdx)->chn+1 : mixaddress(s_currIdx)->destCh+1);
        if (_event == EVT_KEY_LONG(KEY_RIGHT)) s_currIdx++;
        insertExpoMix(expo, s_currIdx);
        pushMenu(expo ? menuProcExpoOne : menuProcMixOne);
        s_copyMode = 0;
        killEvents(_event);
        return;
      }
      break;
    case EVT_KEY_REPT(KEY_UP):
    case EVT_KEY_FIRST(KEY_UP):
    case EVT_KEY_REPT(KEY_DOWN):
    case EVT_KEY_FIRST(KEY_DOWN):
      if (s_copyMode) {
        uint8_t next_ofs = (key == KEY_UP ? s_copyTgtOfs - 1 : s_copyTgtOfs + 1);

        if (s_copyTgtOfs==0 && s_copyMode==COPY_MODE) {
          // insert a mix on the same channel (just above / just below)
          if (reachExpoMixCountLimit(expo)) break;
          copyExpoMix(expo, s_currIdx);
          if (key==KEY_DOWN) s_currIdx++;
          else if (sub-s_pgOfs >= 6) s_pgOfs++;
        }
        else if (next_ofs==0 && s_copyMode==COPY_MODE) {
          // delete the mix
          deleteExpoMix(expo, s_currIdx);
          if (key==KEY_UP) s_currIdx--;
        }
        else {
          // only swap the mix with its neighbor
          if (!swapExpoMix(expo, s_currIdx, key==KEY_UP)) break;
        }

        s_copyTgtOfs = next_ofs;
      }
      break;
  }

  s_currCh = 0;
  uint8_t cur = 1;
  uint8_t i = 0;

  for (uint8_t ch=1; ch<=(expo ? NUM_STICKS : NUM_CHNOUT); ch++) {
    MixData *md=NULL; ExpoData *ed=NULL;
    if (expo ? (i<MAX_EXPOS && (ed=expoaddress(i))->chn+1 == ch && ed->mode) : (i<MAX_MIXERS && (md=mixaddress(i))->srcRaw && md->destCh+1 == ch)) {
      if (s_pgOfs < cur && cur-s_pgOfs < 8) {
        if (expo)
          putsChnRaw(0, (cur-s_pgOfs)*FH, ch, 0);
        else
          putsChn(0, (cur-s_pgOfs)*FH, ch, 0); // show CHx
      }
      uint8_t mixCnt = 0;
      do {
        if (s_copyMode) {
          if (s_copyMode == MOVE_MODE && s_pgOfs < cur && cur-s_pgOfs < 8 && s_copySrcCh == ch && s_copyTgtOfs != 0 && i == (s_copySrcIdx + (s_copyTgtOfs<0))) {
            uint8_t y = (cur-s_pgOfs)*FH;
            lcd_rect(22, y-1, DISPLAY_W-1-21, 9, DOTTED);
            cur++;
          }
          if (s_currIdx == i) {
            sub = m_posVert = cur;
            s_currCh = ch;
          }
        }
        else if (sub == cur) {
          s_currIdx = i;
        }
        if (s_pgOfs < cur && cur-s_pgOfs < 8) {
          if (expo)
            displayExpoLine(cur, i, ch, mixCnt, sub, _event);
          else
            displayMixerLine(cur, i, ch, mixCnt, sub, _event);
        }
        cur++; mixCnt++; i++; md++; ed++;
      } while (expo ? (i<MAX_EXPOS && ed->chn+1 == ch && ed->mode) : (i<MAX_MIXERS && md->srcRaw && md->destCh+1 == ch));
      if (s_copyMode == MOVE_MODE && s_pgOfs < cur && cur-s_pgOfs < 8 && s_copySrcCh == ch && i == (s_copySrcIdx + (s_copyTgtOfs<0))) {
        uint8_t y = (cur-s_pgOfs)*FH;
        lcd_rect(22, y-1, DISPLAY_W-1-21, 9, DOTTED);
        cur++;
      }
    }
    else {
      uint8_t attr = 0;
      if (sub == cur) {
        s_currIdx = i;
        s_currCh = ch;
        if (!s_copyMode) {
          attr = INVERS;
        }
      }
      if (s_pgOfs < cur && cur-s_pgOfs < 8) {
        if (expo)
          putsChnRaw(0, (cur-s_pgOfs)*FH, ch, attr);
        else
          putsChn(0, (cur-s_pgOfs)*FH, ch, attr); // show CHx
        if (s_copyMode == MOVE_MODE && s_copySrcCh == ch) {
          uint8_t y = (cur-s_pgOfs)*FH;
          lcd_rect(22, y-1, DISPLAY_W-1-21, 9, DOTTED);
        }
      }
      cur++;
    }
  }
  s_maxLines = cur;
  if (sub >= s_maxLines-1) m_posVert = s_maxLines-1;
  displayWarning(_event_);
}

void menuProcExposAll(uint8_t event)
{
  return menuProcExpoMix(1, event);
}

void menuProcMixAll(uint8_t event)
{
  return menuProcExpoMix(0, event);
}

void menuProcLimits(uint8_t event)
{
#ifdef PPM_CENTER_ADJUSTABLE
#define LIMITS_ITEMS_COUNT 4
#else
#define LIMITS_ITEMS_COUNT 3
#endif

  MENU(STR_MENULIMITS, menuTabModel, e_Limits, 1+NUM_CHNOUT+1, {0, LIMITS_ITEMS_COUNT, LIMITS_ITEMS_COUNT, LIMITS_ITEMS_COUNT, LIMITS_ITEMS_COUNT, LIMITS_ITEMS_COUNT, LIMITS_ITEMS_COUNT, LIMITS_ITEMS_COUNT, LIMITS_ITEMS_COUNT, LIMITS_ITEMS_COUNT, LIMITS_ITEMS_COUNT, LIMITS_ITEMS_COUNT, LIMITS_ITEMS_COUNT, LIMITS_ITEMS_COUNT, LIMITS_ITEMS_COUNT, LIMITS_ITEMS_COUNT, LIMITS_ITEMS_COUNT, 0});

  int8_t sub = m_posVert - 1;

#ifdef PPM_CENTER_ADJUSTABLE
  if (sub >= 0) {
    lcd_outdezAtt(12*FW, 0, PPM_CENTER+g_model.servoCenter[sub]+g_chans512[sub]/2, 0);
    lcd_puts(12*FW, 0, STR_US);
  }
#endif

  for (uint8_t i=0; i<7; i++) {
    uint8_t y = (i+1)*FH;
    uint8_t k = i+s_pgOfs;

    if (k==NUM_CHNOUT) {
      // last line available - add the "copy trim menu" line
      uint8_t attr = (sub==NUM_CHNOUT) ? INVERS : 0;
      lcd_putsAtt(3*FW, y, STR_TRIMS2OFFSETS, s_noHi ? 0 : attr);
      if (attr && event==EVT_KEY_LONG(KEY_MENU)) {
        s_noHi = NO_HI_LEN;
        killEvents(event);
        moveTrimsToOffsets(); // if highlighted and menu pressed - move trims to offsets
      }
      return;
    }

    LimitData *ld = limitaddress(k) ;

#ifdef PPM_CENTER_ADJUSTABLE
#define LIMITS_MAX_POS 16*FW
    int8_t limit = ((g_model.extendedLimits && !g_model.servoCenter[k]) ? 125 : 100);
#else
#define LIMITS_MAX_POS 17*FW
    int16_t v = (ld->revert) ? -ld->offset : ld->offset;

    char swVal = '-';  // '-', '<', '>'
    if((g_chans512[k] - v) > 50) swVal = (ld->revert ? 127 : 126); // Switch to raw inputs?  - remove trim!
    if((g_chans512[k] - v) < -50) swVal = (ld->revert ? 126 : 127);
    putsChn(0, y, k+1, 0);
    lcd_putcAtt(12*FW+5, y, swVal, 0);

    int8_t limit = (g_model.extendedLimits ? 125 : 100);
#endif

    putsChn(0, y, k+1, 0);

    for (uint8_t j=0; j<=LIMITS_ITEMS_COUNT; j++) {
      uint8_t attr = ((sub==k && m_posHorz==j) ? ((s_editMode>0) ? BLINK|INVERS : INVERS) : 0);
      uint8_t active = (attr && (s_editMode>0 || p1valdiff)) ;
      switch(j)
      {
        case 0:
#ifdef PPM_LIMITS_UNIT_US
          lcd_outdezAtt(  8*FW, y,  ((int32_t)ld->offset*128) / 25, attr|PREC1);
#else
          lcd_outdezAtt(  8*FW, y,  ld->offset, attr|PREC1);
#endif
          if (active) {
            ld->offset = checkIncDec(event, ld->offset, -1000, 1000, EE_MODEL|NO_INCDEC_MARKS);
          }
          else if (attr && event==EVT_KEY_LONG(KEY_MENU)) {
            int16_t zero = g_chans512[k];
            ld->offset = (ld->revert) ? -zero : zero;
            s_editMode = 0;
            STORE_MODELVARS;
          }
          break;
        case 1:
#ifdef PPM_LIMITS_UNIT_US
          lcd_outdezAtt(12*FW+1, y, (((int16_t)ld->min-100)*128) / 25, attr | INFLIGHT(ld->min));
#else
          lcd_outdezAtt(12*FW, y, (int8_t)(ld->min-100), attr | INFLIGHT(ld->min));
#endif
          if (active) {
            CHECK_INFLIGHT_INCDEC_MODELVAR(event, ld->min, -limit, 25, +100, STR_MINLIMIT);
          }
          break;
        case 2:
#ifdef PPM_LIMITS_UNIT_US
          lcd_outdezAtt(16*FW, y, (((int16_t)ld->max+100)*128) / 25, attr | INFLIGHT(ld->max));
#else
          lcd_outdezAtt(LIMITS_MAX_POS, y, (int8_t)(ld->max+100), attr | INFLIGHT(ld->max));
#endif
          if (active) {
            CHECK_INFLIGHT_INCDEC_MODELVAR(event, ld->max, -25, limit, -100, STR_MAXLIMIT);
          }
          break;
        case 3:
#ifdef PPM_CENTER_ADJUSTABLE
          lcd_putcAtt(17*FW-2, y, ld->revert ? 127 : 126, attr);
#else
          lcd_putsiAtt(18*FW, y, STR_MMMINV, ld->revert, attr);
#endif
          if (active) {
            CHECK_INCDEC_MODELVAR(event, ld->revert, 0, 1);
          }
          break;
#ifdef PPM_CENTER_ADJUSTABLE
        case 4:
          lcd_outdezAtt(21*FW+2, y, PPM_CENTER+g_model.servoCenter[k], attr);
          if (active && ld->max <= 0 && ld->min >= 0) {
            CHECK_INCDEC_MODELVAR(event, g_model.servoCenter[k], -125, +125);
          }
          break;
#endif
      }
    }
  }
}

void menuProcCurvesAll(uint8_t event)
{
  SIMPLE_MENU(STR_MENUCURVES, menuTabModel, e_CurvesAll, 1+MAX_CURVE5+MAX_CURVE9);

  int8_t  sub    = m_posVert - 1;

  switch (event) {
    case EVT_KEY_FIRST(KEY_RIGHT):
    case EVT_KEY_FIRST(KEY_MENU):
#ifdef NAVIGATION_RE1
    case EVT_KEY_BREAK(BTN_REa):
#endif
      if (sub >= 0) {
        s_curveChan = sub;
        pushMenu(menuProcCurveOne);
      }
      break;
  }

  uint8_t y    = 1*FH;
  uint8_t yd   = 1;
  uint8_t m    = 0;
  for (uint8_t i = 0; i < 7; i++) {
    uint8_t k = i + s_pgOfs;
    uint8_t attr = sub == k ? INVERS : 0;
    bool    cv9 = k >= MAX_CURVE5;

    if(cv9 && (yd>6)) break;
    if(yd>7) break;
    if(!m) m = attr;
    putsStrIdx(0, y, STR_CV, k+1, attr);
    int8_t *crv = cv9 ? g_model.curves9[k-MAX_CURVE5] : g_model.curves5[k];
    for (uint8_t j = 0; j < (5); j++) {
      lcd_outdezAtt( j*(3*FW+3) + 7*FW + 2, y, crv[j], 0);
    }
    y += FH;yd++;
    if(cv9){
      for (uint8_t j = 0; j < 4; j++) {
        lcd_outdezAtt( j*(3*FW+3) + 7*FW + 2, y, crv[j+5], 0);
      }
      y += FH;yd++;
    }
  }

  if(!m) s_pgOfs++;
}

void menuProcCustomSwitches(uint8_t event)
{
  MENU(STR_MENUCUSTOMSWITCHES, menuTabModel, e_CustomSwitches, NUM_CSW+1, {0, 2/*repeated...*/});

  uint8_t y = 0;
  uint8_t k = 0;
  int8_t  sub    = m_posVert - 1;

  for(uint8_t i=0; i<7; i++) {
    y=(i+1)*FH;
    k=i+s_pgOfs;
    if(k==NUM_CSW) break;
    uint8_t attr = (sub==k ? ((s_editMode>0) ? BLINK|INVERS : INVERS)  : 0);
    CustomSwData &cs = g_model.customSw[k];

    //write SW names here
    lcd_puts(0*FW, y, STR_SW);
    lcd_putc(2*FW, y, k + (k>8 ? 'A'-9: '1'));
    lcd_putsiAtt(4*FW - 1, y, STR_VCSWFUNC, cs.func, m_posHorz==0 ? attr : 0);

    uint8_t cstate = CS_STATE(cs.func);
    int8_t v1_min=0, v1_max=NUM_XCHNCSW, v2_min=0, v2_max=NUM_XCHNCSW;

    if (cstate == CS_VOFS)
    {
        putsChnRaw(12*FW-2, y, cs.v1, (m_posHorz==1 ? attr : 0));

#if defined(FRSKY)
        if (cs.v1 > NUM_XCHNCSW-NUM_TELEMETRY) {
          putsTelemetryChannel(20*FW, y, cs.v1 - (NUM_XCHNCSW-NUM_TELEMETRY+1), convertTelemValue(cs.v1 - (NUM_XCHNCSW-NUM_TELEMETRY), 128+cs.v2), m_posHorz==2 ? attr : 0);
          v2_min = -128; v2_max = maxTelemValue(cs.v1 - (NUM_XCHNCSW-NUM_TELEMETRY)) - 128;
          if (cs.v2 > v2_max) {
            cs.v2 = v2_max;
            eeDirty(EE_MODEL);
          }
        }
        else
#endif
        {
          lcd_outdezAtt(20*FW, y, cs.v2, m_posHorz==2 ? attr : 0);
          v2_min = -125; v2_max = 125;
        }
    }
    else if (cstate == CS_VBOOL)
    {
        putsSwitches(12*FW-2, y, cs.v1, m_posHorz==1 ? attr : 0);
        putsSwitches(17*FW, y, cs.v2, m_posHorz==2 ? attr : 0);
        v1_min = SWITCH_OFF; v1_max = SWITCH_ON;
        v2_min = SWITCH_OFF; v2_max = SWITCH_ON;
    }
    else // cstate == CS_COMP
    {
        putsChnRaw(12*FW-2, y, cs.v1, m_posHorz==1 ? attr : 0);
        putsChnRaw(17*FW, y, cs.v2, m_posHorz==2 ? attr : 0);
    }

    if ((s_editMode>0 || p1valdiff) && attr) {
      switch (m_posHorz) {
        case 0:
          CHECK_INCDEC_MODELVAR(event, cs.func, 0,CS_MAXF);
          if (cstate != CS_STATE(cs.func)) {
            cs.v1 = 0;
            cs.v2 = 0;
          }
          break;
        case 1:
        {
          CHECK_INCDEC_MODELVAR(event, cs.v1, v1_min, v1_max);
          break;
        }
        case 2:
          CHECK_INCDEC_MODELVAR(event, cs.v2, v2_min, v2_max);
          break;
      }
    }
  }
}

void menuProcFunctionSwitches(uint8_t event)
{
  MENU(STR_MENUFUNCSWITCHES, menuTabModel, e_FunctionSwitches, NUM_FSW+1, {0, 2/*repeated*/});

  uint8_t y = 0;
  uint8_t k = 0;
  int8_t  sub    = m_posVert - 1;

  for (uint8_t i=0; i<7; i++) {
    y=(i+1)*FH;
    k=i+s_pgOfs;
    if(k==NUM_CHNOUT) break;
    FuncSwData *sd = &g_model.funcSw[k];
    for (uint8_t j=0; j<3; j++) {
      uint8_t attr = ((sub==k && m_posHorz==j) ? ((s_editMode>0) ? BLINK|INVERS : INVERS) : 0);
      uint8_t active = (attr && (s_editMode>0 || p1valdiff));
      switch (j) {
        case 0:
          putsSwitches(3, y, sd->swtch, attr);
          if (active) {
            CHECK_INCDEC_MODELVAR( event, sd->swtch, SWITCH_OFF-MAX_SWITCH, SWITCH_ON+MAX_SWITCH);
          }
          break;
        case 1:
          if (sd->swtch) {
            uint8_t func_displayed;
            if (sd->func < NUM_CHNOUT) {
              func_displayed = 0;
              putsChnRaw(14*FW-2, y, NUM_STICKS+NUM_POTS+NUM_ROTARY_ENCODERS+2+3+NUM_PPM+sd->func+1, attr);
            }
            else if (sd->func < NUM_CHNOUT + NUM_STICKS + 1) {
              func_displayed = 1;
              if (sd->func != FUNC_TRAINER)
                putsChnRaw(13*FW-2, y, sd->func-FUNC_TRAINER, attr);
            }
            else
              func_displayed = 2 + sd->func - NUM_CHNOUT - NUM_STICKS - 1;
            lcd_putsiAtt(5*FW-2, y, STR_VFSWFUNC, func_displayed, attr);
            if (active) {
              CHECK_INCDEC_MODELVAR( event, sd->func, 0, FUNC_MAX-1);
            }
          }
          else if (attr) {
            m_posHorz = 0;
          }
          break;
        case 2:
          if (sd->swtch) {
            int16_t val_displayed = sd->param;
            int16_t val_min = 0;
            int16_t val_max = 255;
            if (sd->func == FUNC_PLAY_SOUND) {
#if defined(AUDIO)
              val_max = AU_FRSKY_LAST-AU_FRSKY_FIRST-1;
              lcd_putsiAtt(15*FW, y, STR_FUNCSOUNDS, val_displayed, attr);
#else
              break;
#endif
            }
#if defined(SOMO)
            else if (sd->func == FUNC_PLAY_SOMO) {
              lcd_outdezAtt(21*FW, y, val_displayed, attr);
            }
#endif
            else if (sd->func == FUNC_RESET) {
              val_max = 3;
              lcd_putsiAtt(15*FW, y, STR_VFSWRESET, sd->param, attr);
            }
            else if (sd->func <= FUNC_SAFETY_CH16) {
              val_displayed = (int16_t)(int8_t)sd->param;
              val_min = -125;
              val_max = 125;
              lcd_outdezAtt(21*FW, y, val_displayed, attr);
            }
            else {
              break;
            }

            if (active) {
              sd->param = checkIncDec(event, val_displayed, val_min, val_max, EE_MODEL);
            }
          }
          else if (attr) {
            m_posHorz = 0;
          }
          break;
      }
    }
  }
}

#ifdef FRSKY
#define TELEM_COL2 (9*FW+2)
void menuProcTelemetry(uint8_t event)
{
#if defined(FRSKY_HUB) || defined(WS_HOW_HIGH)
  MENU(STR_MENUTELEMETRY, menuTabModel, e_Telemetry, 27, {0, (uint8_t)-1, 1, 0, 2, 2, (uint8_t)-1, 1, 0, 2, 2, (uint8_t)-1, 1, 1, (uint8_t)-1, 0, 0, (uint8_t)-1, 1, 1, 1, 1, (uint8_t)-1, 2, 2, 2, 2});
#else
  MENU(STR_MENUTELEMETRY, menuTabModel, e_Telemetry, 24, {0, (uint8_t)-1, 1, 0, 2, 2, (uint8_t)-1, 1, 0, 2, 2, (uint8_t)-1, 1, 1, (uint8_t)-1, 1, 1, 1, 1, (uint8_t)-1, 2, 2, 2, 2});
#endif

  int8_t  sub = m_posVert;
  uint8_t blink;
  uint8_t y;

  switch (event) {
    case EVT_KEY_BREAK(KEY_DOWN):
    case EVT_KEY_BREAK(KEY_UP):
    case EVT_KEY_BREAK(KEY_LEFT):
    case EVT_KEY_BREAK(KEY_RIGHT):
      if (s_editMode>0 && sub<=13)
        FRSKY_setModelAlarms(); // update Fr-Sky module when edit mode exited
      break;
  }

  blink = (s_editMode>0) ? BLINK|INVERS : INVERS ;
  uint8_t subN = 1;
  uint8_t t;

  for (int i=0; i<2; i++) {
    if(s_pgOfs<subN) {
      y=(subN-s_pgOfs)*FH;
      lcd_putsLeft(y, STR_ACHANNEL);
      lcd_outdezAtt(2*FW, y, 1+i, 0);
    }
    subN++;

    if(s_pgOfs<subN) {
      y=(subN-s_pgOfs)*FH;
      lcd_puts(4, y, STR_RANGE);
      putsTelemetryChannel(TELEM_COL2, y, i+MAX_TIMERS, 255-g_model.frsky.channels[i].offset, (sub==subN && m_posHorz==0 ? blink:0)|NO_UNIT|LEFT);
      lcd_putsiAtt(lcd_lastPos, y, STR_VTELEMUNIT, g_model.frsky.channels[i].type, (sub==subN && m_posHorz==1 ? blink:0));
      if (sub==subN && (s_editMode>0 || p1valdiff)) {
        if (m_posHorz == 0) {
          uint16_t ratio = checkIncDec(event, g_model.frsky.channels[i].ratio, 0, 256, EE_MODEL);
          if (checkIncDec_Ret) {
            if (ratio == 127 && g_model.frsky.channels[i].multiplier > 0) {
              g_model.frsky.channels[i].multiplier--; g_model.frsky.channels[i].ratio = 255;
            }
            else if (ratio == 256) {
              if (g_model.frsky.channels[i].multiplier < 3) { g_model.frsky.channels[i].multiplier++; g_model.frsky.channels[i].ratio = 128; }
            }
            else {
              g_model.frsky.channels[i].ratio = ratio;
            }
          }
        }
        else {
          CHECK_INCDEC_MODELVAR(event, g_model.frsky.channels[i].type, 0, UNIT_MAX-1);
        }
      }
    }
    subN++;

    if(s_pgOfs<subN) {
      y=(subN-s_pgOfs)*FH;
      lcd_puts(4, y, STR_OFFSET);
      putsTelemetryChannel(TELEM_COL2, y, i+MAX_TIMERS, 0, (sub==subN ? blink:0)|LEFT);
      if(sub==subN) CHECK_INCDEC_MODELVAR(event, g_model.frsky.channels[i].offset, -128, 127);
    }
    subN++;

    for (int j=0; j<2; j++) {
      if(s_pgOfs<subN) {
        y=(subN-s_pgOfs)*FH;
        lcd_puts(4, y, STR_ALARM);
        lcd_putsiAtt(TELEM_COL2, y, STR_VALARM, ALARM_LEVEL(i, j), (sub==subN && m_posHorz==0) ? blink : 0);
        lcd_putsiAtt(TELEM_COL2+4*FW, y, STR_VALARMFN, ALARM_GREATER(i, j), (sub==subN && m_posHorz==1) ? blink : 0);
        putsTelemetryChannel(TELEM_COL2+6*FW, y, i+MAX_TIMERS, g_model.frsky.channels[i].alarms_value[j], (sub==subN && m_posHorz==2 ? blink:0) | LEFT);

        if(sub==subN && (s_editMode>0 || p1valdiff)) {
          switch (m_posHorz) {
           case 0:
             t = ALARM_LEVEL(i, j);
             g_model.frsky.channels[i].alarms_level = (g_model.frsky.channels[i].alarms_level & ~(3<<(2*j))) + (checkIncDec(event, t, 0, 3, EE_MODEL) << (2*j));
             break;
           case 1:
             t = ALARM_GREATER(i, j);
             g_model.frsky.channels[i].alarms_greater = (g_model.frsky.channels[i].alarms_greater & ~(1<<j)) + (checkIncDec(event, t, 0, 1, EE_MODEL) << j);
             if(checkIncDec_Ret)
               FRSKY_setModelAlarms();
             break;
           case 2:
             g_model.frsky.channels[i].alarms_value[j] = checkIncDec(event, g_model.frsky.channels[i].alarms_value[j], 0, 255, EE_MODEL);
             break;
          }
        }
      }
      subN++;
    }
  }
  
  if(s_pgOfs<subN) {
    y = (subN-s_pgOfs)*FH;
    lcd_putsLeft(y, PSTR("RSSI"));
  }
  subN++;

  for (int j=0; j<2; j++) {
    if(s_pgOfs<subN) {
      y = (subN-s_pgOfs)*FH;
      lcd_puts(4, y, STR_ALARM);
      lcd_putsiAtt(TELEM_COL2, y, STR_VALARM, ((2+j+g_model.frsky.rssiAlarms[j].level)%4), (sub==subN && m_posHorz==0) ? blink : 0);
      lcd_putc(TELEM_COL2+4*FW, y, '<');
      lcd_outdezNAtt(TELEM_COL2+6*FW, y, getRssiAlarmValue(j), LEFT|((sub==subN && m_posHorz==1) ? blink : 0), 3);

      if (sub==subN && (s_editMode>0 || p1valdiff)) {
        switch (m_posHorz) {
          case 0:
            CHECK_INCDEC_MODELVAR(event, g_model.frsky.rssiAlarms[j].level, -3, 2); // circular (saves flash)
            break;
          case 1:
            CHECK_INCDEC_MODELVAR(event, g_model.frsky.rssiAlarms[j].value, -30, 30);
            break;
        }
      }
    }
    subN++;
  }

#if defined(FRSKY_HUB) || defined(WS_HOW_HIGH)
  if(s_pgOfs<subN) {
    y = (subN-s_pgOfs)*FH;
    lcd_putsLeft(y, STR_USRDATA);
  }
  subN++;

  if(s_pgOfs<subN) {
    y = (subN-s_pgOfs)*FH;
    lcd_puts(4, y, STR_PROTO);
    lcd_putsiAtt(TELEM_COL2, y, STR_VTELPROTO, g_model.frsky.usrProto, sub==subN ? INVERS:0);
    if (sub==subN)
      CHECK_INCDEC_MODELVAR(event, g_model.frsky.usrProto, 0, 2);
  }
  subN++;

  if(s_pgOfs<subN) {
    y = (subN-s_pgOfs)*FH;
    lcd_puts(4, y, STR_BLADES);
    lcd_outdezAtt(TELEM_COL2+FWNUM, y, 2+g_model.frsky.blades, sub==subN ? INVERS : 0);
    if (sub==subN)
      CHECK_INCDEC_MODELVAR(event, g_model.frsky.blades, 0, 2);
  }
  subN++;
#endif

  // Display
  if(s_pgOfs<subN) {
    y = (subN-s_pgOfs)*FH;
    lcd_putsLeft(y, STR_DISPLAY);
  }
  subN++;

  for (uint8_t j=0; j<4; j++) {
    if (s_pgOfs<subN) {
      y = (subN-s_pgOfs)*FH;
      for (uint8_t k=0; k<2; k++) {
        uint8_t value = getTelemCustomField(j, k);
        lcd_putsiAtt(k==0?4:TELEM_COL2, y, STR_VTELEMCHNS, value, (sub==subN && m_posHorz==k) ? blink : 0);
        if (sub==subN && m_posHorz==k && (s_editMode>0 || p1valdiff)) {
          CHECK_INCDEC_MODELVAR(event, value, 0, (j==3 && k==0) ? TELEM_STATUS_MAX : TELEM_DISPLAY_MAX);
          if (checkIncDec_Ret) {
            g_model.frskyLines[j] = (k==0 ? ((g_model.frskyLines[j] & 0xf0) + (value & 0x0f)) : (g_model.frskyLines[j] & 0x0f) + ((value & 0x0f) << 4));
            uint16_t mask = 0x3 << (4*j+2*k);
            g_model.frskyLinesXtra &= ~mask;
            mask = (value / 16) << (4*j+2*k);
            g_model.frskyLinesXtra |= mask;
          }
        }
      }
    }
    subN++;
  }

  // Bars
  if(s_pgOfs<subN) {
    y = (subN-s_pgOfs)*FH;
    lcd_putsLeft(y, STR_BARS);
  }
  subN++;

  for (uint8_t j=0; j<4; j++) {
    uint8_t barSource = g_model.frsky.bars[j].source;
    if (s_pgOfs<subN) {
      y = (subN-s_pgOfs)*FH;
      lcd_putsiAtt(4, y, STR_VTELEMCHNS, barSource, (sub==subN && m_posHorz==0) ? blink : 0);
      if (barSource) {
        putsTelemetryChannel(TELEM_COL2-3*FW, y, barSource-1, convertTelemValue(barSource, g_model.frsky.bars[j].barMin*5), (sub==subN && m_posHorz==1 ? blink : 0) | LEFT);
        putsTelemetryChannel(14*FW-3, y, barSource-1, convertTelemValue(barSource, (51-g_model.frsky.bars[j].barMax)*5), (sub==subN && m_posHorz==2 ? blink : 0) | LEFT);
      }
      else {
        if (sub == subN) m_posHorz = 0;
      }
      if (sub==subN && (s_editMode>0 || p1valdiff)) {
        switch (m_posHorz) {
          case 0:
            CHECK_INCDEC_MODELVAR(event, barSource, 0, g_model.frsky.usrProto ? TELEM_BAR_MAX : TELEM_NOUSR_BAR_MAX);
            if (checkIncDec_Ret) {
              g_model.frsky.bars[j].source = barSource;
              g_model.frsky.bars[j].barMin = 0;
              g_model.frsky.bars[j].barMax = 51 - (maxTelemValue(barSource) / 5);
            }
            break;
          case 1:
            CHECK_INCDEC_MODELVAR(event, g_model.frsky.bars[j].barMin, 0, 50-g_model.frsky.bars[j].barMax);
            break;
          case 2:
            g_model.frsky.bars[j].barMax = 51 - checkIncDec(event, 51 - g_model.frsky.bars[j].barMax, g_model.frsky.bars[j].barMin+1, maxTelemValue(barSource) / 5, EE_MODEL);
            break;
        }
      }
    }
    subN++;
  }
}
#endif

#ifdef TEMPLATES
// TODO s_noHi needed?
void menuProcTemplates(uint8_t _event)
{
  uint8_t event = (s_warning ? 0 : _event);

  SIMPLE_MENU(STR_MENUTEMPLATES, menuTabModel, e_Templates, 1+TMPL_COUNT);

  uint8_t sub = m_posVert - 1;

  if (s_confirmation) {
    if (sub<TMPL_COUNT)
      applyTemplate(sub);
    s_confirmation = 0;
    AUDIO_WARNING2();
  }

  switch(event)
  {
    case EVT_KEY_FIRST(KEY_MENU):
      s_warning = STR_VTEMPLATES+1 + (sub * LEN2_VTEMPLATES);
      killEvents(event);
      _event = 0;
      break;
  }

  uint8_t y = 1*FH;
  uint8_t k = 0;
  for (uint8_t i=0; i<7 && k<TMPL_COUNT; i++) {
    k=i+s_pgOfs;
    lcd_outdezNAtt(3*FW, y, k, (sub==k ? INVERS : 0)|LEADING0, 2);
    lcd_putsiAtt(4*FW, y, STR_VTEMPLATES, k, (sub==k ? INVERS  : 0));
    y+=FH;
  }

  if (s_warning) {
    displayConfirmation(_event);
  }
}
#endif

