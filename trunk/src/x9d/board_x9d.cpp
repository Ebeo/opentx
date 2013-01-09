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

#include "../open9x.h"

// TODO needed?
uint8_t temperature = 0;          // Raw temp reading
uint8_t maxTemperature = 0 ;       // Raw temp reading
volatile uint32_t Tenms ; // TODO to remove everywhere / use a #define

uint32_t Peri1_frequency = 30000000;
uint32_t Peri2_frequency = 30000000;
uint32_t Timer_mult = 2;

#define PIN_MODE_MASK           0x0003
#define PIN_INPUT               0x0000
#define PIN_OUTPUT              0x0001
#define PIN_PERIPHERAL          0x0002
#define PIN_ANALOG              0x0003
#define PIN_PULL_MASK           0x000C
#define PIN_PULLUP              0x0004
#define PIN_NO_PULLUP           0x0000
#define PIN_PULLDOWN            0x0008
#define PIN_NO_PULLDOWN         0x0000
#define PIN_PERI_MASK           0x00F0
#define PIN_PUSHPULL            0x0000
#define PIN_ODRAIN              0x8000
#define PIN_PORT_MASK           0x0700
#define PIN_SPEED_MASK          0x6000

void configure_pins( uint32_t pins, uint16_t config )
{
  uint32_t address ;
  GPIO_TypeDef *pgpio ;
  uint32_t thispin ;
  uint32_t pos ;

  address = ( config & PIN_PORT_MASK ) >> 8 ;
  address *= (GPIOB_BASE-GPIOA_BASE) ;
  address += GPIOA_BASE ;
  pgpio = (GPIO_TypeDef* ) address ;

  /* -------------------------Configure the port pins---------------- */
  /*-- GPIO Mode Configuration --*/
  for (thispin = 0x0001, pos = 0; thispin < 0x10000; thispin <<= 1, pos +=1 )
  {
    if ( pins & thispin)
    {
      pgpio->MODER  &= ~(GPIO_MODER_MODER0 << (pos * 2)) ;
      pgpio->MODER |= (config & PIN_MODE_MASK) << (pos * 2) ;

      if ( ( (config & PIN_MODE_MASK ) == PIN_OUTPUT) || ( (config & PIN_MODE_MASK) == PIN_PERIPHERAL) )
      {
        /* Speed mode configuration */
        pgpio->OSPEEDR &= ~GPIO_OSPEEDER_OSPEEDR0 << (pos * 2) ;
        pgpio->OSPEEDR |= ((config & PIN_SPEED_MASK) >> 13 ) << (pos * 2) ;

        /* Output mode configuration*/
        pgpio->OTYPER  &= ~((GPIO_OTYPER_OT_0) << ((uint16_t)pos)) ;
        if ( config & PIN_ODRAIN )
        {
          pgpio->OTYPER |= (GPIO_OTYPER_OT_0) << pos ;
        }
      }
      /* Pull-up Pull down resistor configuration*/
      pgpio->PUPDR &= ~(GPIO_PUPDR_PUPDR0 << ((uint16_t)pos * 2));
      pgpio->PUPDR |= ((config & PIN_PULL_MASK) >> 2) << (pos * 2) ;

      pgpio->AFR[pos >> 3] &= ~(0x000F << (pos & 7)) ;
      pgpio->AFR[pos >> 3] |= ((config & PIN_PERI_MASK) >> 4) << (pos & 7) ;
    }
  }
}

uint8_t getTemperature()
{
  return temperature + g_eeGeneral.temperatureCalib;
}

void start_ppm_capture()
{
}

void usbBootloader()
{
}

void usbMassStorage()
{
}

// Starts TIMER at 200Hz, 5mS period
void init5msTimer()
{
  // Timer14
  RCC->APB1ENR |= RCC_APB1ENR_TIM14EN ;           // Enable clock
  TIM14->ARR = 4999 ;     // 5mS
  TIM14->PSC = (Peri1_frequency * Timer_mult) / 1000000 - 1 ;                // 1uS from 30MHz
  TIM14->CCER = 0 ;
  TIM14->CCMR1 = 0 ;
  TIM14->EGR = 0 ;
  TIM14->CR1 = 5 ;
  TIM14->DIER |= 1 ;
  NVIC_EnableIRQ(TIM8_TRG_COM_TIM14_IRQn) ;
}

void stop5msTimer( void )
{
  TIM14->CR1 = 0 ;        // stop timer
  NVIC_DisableIRQ(TIM8_TRG_COM_TIM14_IRQn) ;
  RCC->APB1ENR &= ~RCC_APB1ENR_TIM14EN ;          // Disable clock
}

// TODO use the same than board_sky9x.cpp
void interrupt5ms()
{
  static uint32_t pre_scale ;       // Used to get 10 Hz counter

  // HAPTIC_HEARTBEAT();
  // AUDIO_HEARTBEAT();

  if ( ++pre_scale >= 2 ) {
    /* if ( Buzzer_count ) {
      if ( --Buzzer_count == 0 )
        buzzer_off() ;
    } */
    pre_scale = 0 ;
    per10ms();
  }
}

extern "C" void TIM8_TRG_COM_TIM14_IRQHandler()
{
  TIM14->SR &= ~TIM_SR_UIF ;
  interrupt5ms() ;
}

#if !defined(SIMU)
void boardInit()
{
  pwrInit();
  keysInit();
  adcInit();
  delaysInit();

  init5msTimer();

  __enable_irq() ;

  eepromInit();
}
#endif


