/************************************************************************************
 * arch/arm/include/tiva/tm4c_irq.h
 *
 *   Copyright (C) 2014 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ************************************************************************************/

#ifndef __ARCH_ARM_INCLUDE_TIVA_TM4C_IRQ_H
#define __ARCH_ARM_INCLUDE_TIVA_TM4C_IRQ_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>

/************************************************************************************
 * Definitions
 ************************************************************************************/

/* IRQ numbers.  The IRQ number corresponds vector number and hence map directly to
 * bits in the NVIC.  This does, however, waste several words of memory in the IRQ
 * to handle mapping tables.
 */

/* External interrupts (vectors >= 16) */

#define TIVA_IRQ_INTERRUPTS (16) /* Vector number of the first external interrupt */

#if defined(CONFIG_ARCH_CHIP_TM4C123GH6ZRB)
#  define TIVA_IRQ_GPIOA      (16)  /* Vector 16: GPIO Port A */
#  define TIVA_IRQ_GPIOB      (17)  /* Vector 17: GPIO Port B */
#  define TIVA_IRQ_GPIOC      (18)  /* Vector 18: GPIO Port C */
#  define TIVA_IRQ_GPIOD      (19)  /* Vector 19: GPIO Port D */

#  define TIVA_IRQ_GPIOE      (20)  /* Vector 20: GPIO Port E */
#  define TIVA_IRQ_UART0      (21)  /* Vector 21: UART 0 */
#  define TIVA_IRQ_UART1      (22)  /* Vector 22: UART 1 */
#  define TIVA_IRQ_SSI0       (23)  /* Vector 23: SSI 0 */
#  define TIVA_IRQ_I2C0       (24)  /* Vector 24: I2C 0 */
#  define TIVA_IRQ_PWM0_FAULT (25)  /* Vector 25: PWM0 Fault */
#  define TIVA_IRQ_PWM0_GEN0  (26)  /* Vector 26: PWM0 Generator 0 */
#  define TIVA_IRQ_PWM0_GEN1  (27)  /* Vector 27: PWM0 Generator 1 */
#  define TIVA_IRQ_PWM0_GEN2  (28)  /* Vector 28: PWM0 Generator 2 */
#  define TIVA_IRQ_QEI0       (29)  /* Vector 29: QEI0 */

#  define TIVA_IRQ_ADC0       (30)  /* Vector 30: ADC Sequence 0 */
#  define TIVA_IRQ_ADC1       (31)  /* Vector 31: ADC Sequence 1 */
#  define TIVA_IRQ_ADC2       (32)  /* Vector 32: ADC Sequence 2 */
#  define TIVA_IRQ_ADC3       (33)  /* Vector 33: ADC Sequence 3 */
#  define TIVA_IRQ_WDOG       (34)  /* Vector 34: Watchdog Timers 0 and 1 */
#  define TIVA_IRQ_TIMER0A    (35)  /* Vector 35: 16/32-Bit Timer 0 A */
#  define TIVA_IRQ_TIMER0B    (36)  /* Vector 36: 16/32-Bit Timer 0 B */
#  define TIVA_IRQ_TIMER1A    (37)  /* Vector 37: 16/32-Bit Timer 1 A */
#  define TIVA_IRQ_TIMER1B    (38)  /* Vector 38: 16/32-Bit Timer 1 B */
#  define TIVA_IRQ_TIMER2A    (39)  /* Vector 39: 16/32-Bit Timer 2 A */

#  define TIVA_IRQ_TIMER2B    (40)  /* Vector 40: 16/32-Bit Timer 2 B */
#  define TIVA_IRQ_COMPARE0   (41)  /* Vector 41: Analog Comparator 0 */
#  define TIVA_IRQ_COMPARE1   (42)  /* Vector 42: Analog Comparator 1 */
#  define TIVA_IRQ_COMPARE2   (43)  /* Vector 43: Analog Comparator 2 */
#  define TIVA_IRQ_SYSCON     (44)  /* Vector 44: System Control */
#  define TIVA_IRQ_FLASHCON   (45)  /* Vector 45: FLASH and EEPROM Control */
#  define TIVA_IRQ_GPIOF      (46)  /* Vector 46: GPIO Port F */
#  define TIVA_IRQ_GPIOG      (47)  /* Vector 47: GPIO Port G */
#  define TIVA_IRQ_GPIOH      (48)  /* Vector 48: GPIO Port H */
#  define TIVA_IRQ_UART2      (49)  /* Vector 49: UART 2 */

#  define TIVA_IRQ_SSI1       (50)  /* Vector 50: SSI 1 */
#  define TIVA_IRQ_TIMER3A    (51)  /* Vector 51: 16/32-Bit Timer 3 A */
#  define TIVA_IRQ_TIMER3B    (52)  /* Vector 52: 16/32-Bit Timer 3 B */
#  define TIVA_IRQ_I2C1       (53)  /* Vector 53: I2C 1 */
#  define TIVA_IRQ_QEI1       (54)  /* Vector 54: QEI1 */
#  define TIVA_IRQ_CAN0       (55)  /* Vector 55: CAN 0 */
#  define TIVA_IRQ_CAN1       (56)  /* Vector 56: CAN 1 */
#  define TIVA_RESERVED_57    (57)  /* Vector 57: Reserved */
#  define TIVA_RESERVED_58    (58)  /* Vector 58: Reserved */
#  define TIVA_IRQ_HIBERNATE  (59)  /* Vector 59: Hibernation Module */

#  define TIVA_IRQ_USB        (60)  /* Vector 60: USB */
#  define TIVA_IRQ_PWM0_GEN3  (61)  /* Vector 61: PWM0 Generator 3 */
#  define TIVA_IRQ_UDMASOFT   (62)  /* Vector 62: uDMA Software */
#  define TIVA_IRQ_UDMAERROR  (63)  /* Vector 63: uDMA Error */
#  define TIVA_IRQ_ADC1_0     (64)  /* Vector 64: ADC1 Sequence 0 */
#  define TIVA_IRQ_ADC1_1     (65)  /* Vector 65: ADC1 Sequence 1 */
#  define TIVA_IRQ_ADC1_2     (66)  /* Vector 66: ADC1 Sequence 2 */
#  define TIVA_IRQ_ADC1_3     (67)  /* Vector 67: ADC1 Sequence 3 */
#  define TIVA_RESERVED_68    (68)  /* Vector 68: Reserved */
#  define TIVA_RESERVED_69    (69)  /* Vector 69: Reserved */

#  define TIVA_IRQ_GPIOJ      (70)  /* Vector 70: GPIO Port J */
#  define TIVA_IRQ_GPIOK      (71)  /* Vector 71: GPIO Port K */
#  define TIVA_IRQ_GPIOL      (72)  /* Vector 72: GPIO Port L */
#  define TIVA_IRQ_SSI2       (73)  /* Vector 73: SSI 2 */
#  define TIVA_IRQ_SSI3       (74)  /* Vector 74: SSI 3 */
#  define TIVA_IRQ_UART3      (75)  /* Vector 75: UART 3 */
#  define TIVA_IRQ_UART4      (76)  /* Vector 76: UART 4 */
#  define TIVA_IRQ_UART5      (77)  /* Vector 77: UART 5 */
#  define TIVA_IRQ_UART6      (78)  /* Vector 78: UART 6 */
#  define TIVA_IRQ_UART7      (79)  /* Vector 79: UART 7 */

#  define TIVA_RESERVED_80    (80)  /* Vector 80: Reserved */
#  define TIVA_RESERVED_81    (81)  /* Vector 81: Reserved */
#  define TIVA_RESERVED_82    (82)  /* Vector 82: Reserved */
#  define TIVA_RESERVED_83    (83)  /* Vector 83: Reserved */
#  define TIVA_IRQ_I2C2       (84)  /* Vector 84: I2C 2 */
#  define TIVA_IRQ_I2C3       (85)  /* Vector 85: I2C 3 */
#  define TIVA_IRQ_TIMER4A    (86)  /* Vector 86: 16/32-Bit Timer 4 A */
#  define TIVA_IRQ_TIMER4B    (87)  /* Vector 87: 16/32-Bit Timer 4 B */
#  define TIVA_RESERVED_88    (88)  /* Vector 88: Reserved */
#  define TIVA_RESERVED_89    (89)  /* Vector 89: Reserved */

#  define TIVA_RESERVED_90    (90)  /* Vector 90: Reserved */
#  define TIVA_RESERVED_91    (91)  /* Vector 91: Reserved */
#  define TIVA_RESERVED_92    (92)  /* Vector 92: Reserved */
#  define TIVA_RESERVED_93    (93)  /* Vector 93: Reserved */
#  define TIVA_RESERVED_94    (94)  /* Vector 94: Reserved */
#  define TIVA_RESERVED_95    (95)  /* Vector 95: Reserved */
#  define TIVA_RESERVED_96    (96)  /* Vector 96: Reserved */
#  define TIVA_RESERVED_97    (97)  /* Vector 97: Reserved */
#  define TIVA_RESERVED_98    (98)  /* Vector 98: Reserved */
#  define TIVA_RESERVED_99    (99)  /* Vector 99: Reserved */

#  define TIVA_RESERVED_100   (100) /* Vector 100: Reserved */
#  define TIVA_RESERVED_101   (101) /* Vector 101: Reserved */
#  define TIVA_RESERVED_102   (102) /* Vector 102: Reserved */
#  define TIVA_RESERVED_103   (103) /* Vector 103: Reserved */
#  define TIVA_RESERVED_104   (104) /* Vector 104: Reserved */
#  define TIVA_RESERVED_105   (105) /* Vector 105: Reserved */
#  define TIVA_RESERVED_106   (106) /* Vector 106: Reserved */
#  define TIVA_RESERVED_107   (107) /* Vector 107: Reserved */
#  define TIVA_IRQ_TIMER5A    (108) /* Vector 108: 16/32-Bit Timer 5 A */
#  define TIVA_IRQ_TIMER5B    (109) /* Vector 109: 16/32-Bit Timer 5 B */

#  define TIVA_IRQ_WTIMER0A   (110) /* Vector 110: 32/64-Bit Timer 0 A */
#  define TIVA_IRQ_WTIMER0B   (111) /* Vector 111: 32/64-Bit Timer 0 B */
#  define TIVA_IRQ_WTIMER1A   (112) /* Vector 112: 32/64-Bit Timer 1 A */
#  define TIVA_IRQ_WTIMER1B   (113) /* Vector 113: 32/64-Bit Timer 1 B */
#  define TIVA_IRQ_WTIMER2A   (114) /* Vector 114: 32/64-Bit Timer 2 A */
#  define TIVA_IRQ_WTIMER2B   (115) /* Vector 115: 32/64-Bit Timer 2 B */
#  define TIVA_IRQ_WTIMER3A   (116) /* Vector 116: 32/64-Bit Timer 3 A */
#  define TIVA_IRQ_WTIMER3B   (117) /* Vector 117: 32/64-Bit Timer 3 B */
#  define TIVA_IRQ_WTIMER4A   (118) /* Vector 118: 32/64-Bit Timer 4 A */
#  define TIVA_IRQ_WTIMER4B   (119) /* Vector 119: 32/64-Bit Timer 4 B */

#  define TIVA_IRQ_WTIMER5A   (120) /* Vector 120: 32/64-Bit Timer 5 A */
#  define TIVA_IRQ_WTIMER5B   (121) /* Vector 121: 32/64-Bit Timer 5 B */
#  define TIVA_IRQ_SYSTEM     (122) /* Vector 122: System Exception (imprecise) */
#  define TIVA_RESERVED_123   (123) /* Vector 123: Reserved */
#  define TIVA_RESERVED_124   (124) /* Vector 124: Reserved */
#  define TIVA_IRQ_I2C4       (125) /* Vector 125: I2C4 */
#  define TIVA_IRQ_I2C5       (126) /* Vector 126: I2C5 */
#  define TIVA_IRQ_GPIOM      (127) /* Vector 127: GPIO Port M */
#  define TIVA_IRQ_GPION      (128) /* Vector 128: GPIO Port N */
#  define TIVA_RESERVED_129   (129) /* Vector 129: Reserved */

#  define TIVA_RESERVED_130   (130) /* Vector 130: Reserved */
#  define TIVA_RESERVED_131   (131) /* Vector 131: Reserved */
#  define TIVA_IRQ_GPIOP      (132) /* Vector 132: GPIO Port P (Summary or P0) */
#  define TIVA_IRQ_GPIOP1     (133) /* Vector 133: GPIO Port P1 */
#  define TIVA_IRQ_GPIOP2     (134) /* Vector 134: GPIO Port P2 */
#  define TIVA_IRQ_GPIOP3     (135) /* Vector 135: GPIO Port P3 */
#  define TIVA_IRQ_GPIOP4     (136) /* Vector 136: GPIO Port P4 */
#  define TIVA_IRQ_GPIOP5     (137) /* Vector 137: GPIO Port P5 */
#  define TIVA_IRQ_GPIOP6     (138) /* Vector 138: GPIO Port P6 */
#  define TIVA_IRQ_GPIOP7     (139) /* Vector 139: GPIO Port P7 */

#  define TIVA_IRQ_GPIOQ      (140) /* Vector 140: GPIO Port Q (Summary or Q0) */
#  define TIVA_IRQ_GPIOQ1     (141) /* Vector 141: GPIO Port Q1 */
#  define TIVA_IRQ_GPIOQ2     (142) /* Vector 142: GPIO Port Q2 */
#  define TIVA_IRQ_GPIOQ3     (143) /* Vector 143: GPIO Port Q3 */
#  define TIVA_IRQ_GPIOQ4     (144) /* Vector 144: GPIO Port Q4 */
#  define TIVA_IRQ_GPIOQ5     (145) /* Vector 145: GPIO Port Q5 */
#  define TIVA_IRQ_GPIOQ6     (146) /* Vector 146: GPIO Port Q6 */
#  define TIVA_IRQ_GPIOQ7     (147) /* Vector 147: GPIO Port Q7 */
#  define TIVA_RESERVED_148   (148) /* Vector 148: Reserved */
#  define TIVA_RESERVED_149   (149) /* Vector 149: Reserved */

#  define TIVA_IRQ_PWM1_GEN0  (150)  /* Vector 150: PWM1 Generator 0 */
#  define TIVA_IRQ_PWM1_GEN1  (151)  /* Vector 151: PWM1 Generator 1 */
#  define TIVA_IRQ_PWM1_GEN2  (152)  /* Vector 152: PWM1 Generator 2 */
#  define TIVA_IRQ_PWM1_GEN3  (153)  /* Vector 153: PWM1 Generator 3 */
#  define TIVA_IRQ_PWM1_FAULT (154)  /* Vector 154: PWM1 Fault */

#  define NR_VECTORS          (155)
#  define NR_IRQS             (123) /* (Really fewer because of reserved vectors) */

#else
#  error "IRQ Numbers not known for this Tiva chip"
#endif

/************************************************************************************
 * Public Types
 ************************************************************************************/

/************************************************************************************
 * Public Data
 ************************************************************************************/

#ifndef __ASSEMBLY__
#ifdef __cplusplus
extern "C"
{
#endif

/************************************************************************************
 * Public Functions
 ************************************************************************************/

#ifdef __cplusplus
}
#endif
#endif

#endif /* __ARCH_ARM_INCLUDE_TIVA_TM4C_IRQ_H */

