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


#ifndef audio_h
#define audio_h

#define AUDIO_QUEUE_LENGTH (20) 
#define BEEP_DEFAULT_FREQ  (70)
#define BEEP_OFFSET        (10)
#define BEEP_KEY_UP_FREQ   (BEEP_DEFAULT_FREQ+5)
#define BEEP_KEY_DOWN_FREQ (BEEP_DEFAULT_FREQ-5)

class audioQueue
{
  public:

    audioQueue();


    void play(uint8_t tFreq, uint8_t tLen, uint8_t tPause, uint8_t tFlags=0, int8_t tFreqIncr=0);

    inline bool busy() {
      return (toneTimeLeft > 0);
    }

    void event(uint8_t e, uint8_t f=BEEP_DEFAULT_FREQ);

    // heartbeat is responsibile for issueing the audio tones and general square waves
    // it is essentially the life of the class.
    void heartbeat();

    // bool freeslots(uint8_t slots);

    inline bool empty() {
      return (t_queueRidx == t_queueWidx);
    }

  protected:
    inline uint8_t getToneLength(uint8_t tLen);

  private:
    uint8_t t_queueRidx;
    uint8_t t_queueWidx;

    uint8_t toneFreq;
    int8_t toneFreqIncr;
    uint8_t toneTimeLeft;
    uint8_t tonePause;

    // vario
    uint8_t tone2Freq;
    uint8_t tone2TimeLeft;
    uint8_t tone2Pause;

    // queue arrays
    uint8_t queueToneFreq[AUDIO_QUEUE_LENGTH];
    int8_t queueToneFreqIncr[AUDIO_QUEUE_LENGTH];
    uint8_t queueToneLength[AUDIO_QUEUE_LENGTH];
    uint8_t queueTonePause[AUDIO_QUEUE_LENGTH];
    uint8_t queueToneRepeat[AUDIO_QUEUE_LENGTH];

};

//wrapper function - dirty but results in a space saving!!!
extern audioQueue audio;

void audioDefevent(uint8_t e);

#define AUDIO_KEYPAD_UP()   audioDefevent(AU_KEYPAD_UP)
#define AUDIO_KEYPAD_DOWN() audioDefevent(AU_KEYPAD_DOWN)
#define AUDIO_MENUS()       audioDefevent(AU_MENUS)
#define AUDIO_WARNING1()    audioDefevent(AU_WARNING1)
#define AUDIO_WARNING2()    audioDefevent(AU_WARNING2)
#define AUDIO_ERROR()       audioDefevent(AU_ERROR)


#define IS_AUDIO_BUSY()     audio.busy()

#define AUDIO_TIMER_30()    audioDefevent(AU_TIMER_30)
#define AUDIO_TIMER_20()    audioDefevent(AU_TIMER_20)
#define AUDIO_TIMER_10()    audioDefevent(AU_TIMER_10)
#define AUDIO_TIMER_LT3()   audioDefevent(AU_TIMER_LT3)
#define AUDIO_MINUTE_BEEP() audioDefevent(AU_WARNING1)
#define AUDIO_INACTIVITY()  audioDefevent(AU_INACTIVITY)
#define AUDIO_MIX_WARNING_1() audioDefevent(AU_MIX_WARNING_1)
#define AUDIO_MIX_WARNING_2() audioDefevent(AU_MIX_WARNING_2)
#define AUDIO_MIX_WARNING_3() audioDefevent(AU_MIX_WARNING_3)
#define AUDIO_POT_STICK_MIDDLE() audioDefevent(AU_POT_STICK_MIDDLE)
#define AUDIO_VARIO_UP()    audioDefevent(AU_KEYPAD_UP)
#define AUDIO_VARIO_DOWN()  audioDefevent(AU_KEYPAD_DOWN)
#define AUDIO_TRIM_MIDDLE() audioDefevent(AU_TRIM_MIDDLE)
#define AUDIO_TELEMETRY_ALARM() audioDefevent(AU_WARNING1)

#define AUDIO_HEARTBEAT()   audio.heartbeat()

#endif
