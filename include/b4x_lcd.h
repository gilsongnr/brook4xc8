/*    _____   _____    _____   _____   _   __
 *   |  _  \ |  _  \  /  _  \ /  _  \ | | / /
 *   | |_) | | |_) |  | | | | | | | | | |/ /
 *   |  _ <  |  _ <   | | | | | | | | |   (
 *   | |_) | | | \ \  | |_| | | |_| | | |\ \
 *   |_____/ |_|  \_\ \_____/ \_____/ |_| \_\ 4-XC8.
 *
 *   –– a small XC8 library for development with 8-bit PIC MCUs.
 *
 * Copyright (c) 2017 Silvio Clecio <silvioprog@gmail.com>
 *
 * This file is part of Brook4-XC8.
 *
 * Brook4-XC8 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Brook4-XC8 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Brook4-XC8.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef B4X_LCD_H
#define	B4X_LCD_H

#ifdef __cplusplus
extern "C" {
#endif

#include "b4x_macros.h"
#include "b4x_types.h"

/* Special characters */
#define B4X_RIGHT_ARROW 0x7e
#define B4X_LEFT_ARROW 0x7f
#define B4X_START_FRAME 0xa2
#define B4X_END_FRAME 0xa3
#define B4X_SEPARATOR 0xa5
#define B4X_EMPTY_BOX 0xdb
#define B4X_ALPHA 0xe0
#define B4X_BETA 0xe2
#define B4X_EPSILON 0xe3
#define B4X_MU 0xe4
#define B4X_SMALL_SIGMA 0xe5
#define B4X_RHO 0xe6
#define B4X_SQRT_SYMBOL 0xe8
#define B4X_CENT_SYMBOL 0xec
#define B4X_THETA 0xf2
#define B4X_INFINITY 0xf3
#define B4X_OMEGA 0xf4
#define B4X_BIG_SIGMA 0xf6
#define B4X_PI_SYMBOL 0xf7
#define B4X_X_BAR 0xf8
#define B4X_DIVISION 0xfd
#define B4X_BLACK_SQUARE 0xff

/**
 * Selects registers.
 */
B4X_EXTERN B4X_VBIT B4X_LCD_RS;

/**
 * Starts data read/write.
 */
B4X_EXTERN B4X_VBIT B4X_LCD_E;

/**
 * Data 4.
 */
B4X_EXTERN B4X_VBIT B4X_LCD_D4;

/**
 * Data 5.
 */
B4X_EXTERN B4X_VBIT B4X_LCD_D5;

/**
 * Data 6.
 */
B4X_EXTERN B4X_VBIT B4X_LCD_D6;

/**
 * Data 7.
 */
B4X_EXTERN B4X_VBIT B4X_LCD_D7;

/**
 * Set a LCD port.
 */
#define B4X_LCD_SET_PORT(p1, p2, n) B4X_VBIT B4X_LCD_##p1 B4X_AT((p2), (n))

/**
 * Set RS port.
 */
#define B4X_LCD_SET_RS(p, n) B4X_LCD_SET_PORT(RS, (p), (n))

/**
 * Set E port.
 */
#define B4X_LCD_SET_E(p, n) B4X_LCD_SET_PORT(E, (p), (n))

/**
 * Set D4 port.
 */
#define B4X_LCD_SET_D4(p, n) B4X_LCD_SET_PORT(D4, (p), (n))

/**
 * Set D5 port.
 */
#define B4X_LCD_SET_D5(p, n) B4X_LCD_SET_PORT(D5, (p), (n))

/**
 * Set D6 port.
 */
#define B4X_LCD_SET_D6(p, n) B4X_LCD_SET_PORT(D6, (p), (n))

/**
 * Set D7 port.
 */
#define B4X_LCD_SET_D7(p, n) B4X_LCD_SET_PORT(D7, (p), (n))

/**
 * Turn on LCD.
 */
#define B4X_LCD_ON 0x0c

/**
 * Turn off LCD.
 */
#define B4X_LCD_OFF 0x08

/**
 * Turn on cursor.
 */
#define B4X_LCD_CUR_ON 0x0e

/**
 * Blink cursor.
 */
#define B4X_LCD_CUR_BLINK 0x0d

/**
 * Clear display.
 */
#define B4X_LCD_CLEAR 0x01

/**
 * Return cursor to home.
 */
#define B4X_LCD_HOME 0x80

/**
 * Return cursor to home in new line.
 */
#define B4X_LCD_RETURN 0xc0

/**
 * Increments cursor.
 */
#define B4X_LCD_INC_CUR 0x14

/**
 * Decrements cursor.
 */
#define B4X_LCD_DEC_CUR 0x10

/**
 * Entire text to left.
 */
#define B4X_LCD_TEXT_LEFT 0x1c

/**
 * Entire text to right.
 */
#define B4X_LCD_TEXT_RIGHT 0x18

/**
 * Initializes LCD module.
 */
B4X_EXTERN void b4x_lcd_init();

/**
 * Sends command to LCD.
 * @param cmd Command line.
 */
B4X_EXTERN void b4x_lcd_cmd(unsigned char cmd);

/**
 * Set cursor position.
 * @param x X.
 * @param y Y.
 */
B4X_EXTERN void b4x_lcd_pos(unsigned char x, unsigned char y);

/**
 * Writes a character on the LCD.
 * @param c Character.
 */
B4X_EXTERN void b4x_lcd_putc(char c);

/**
 * Writes a string on the LCD that is allocated on the RAM.
 * @param s String on the RAM.
 */
B4X_EXTERN void b4x_lcd_puts(char *s);

/**
 * Writes a string on the LCD that is allocated on the program memory.
 * @param s String on the program memory.
 */
B4X_EXTERN void b4x_lcd_putrs(const char *s);

/**
 * Set cursor position and writes a character on the LCD.
 * @param x X.
 * @param y Y.
 */
B4X_EXTERN void b4x_lcd_write_chr(unsigned char x, unsigned char y, char c);

/**
 * Set cursor position and writes a string on the LCD that is allocated on
 * the RAM.
 * @param x X.
 * @param y Y.
 */
B4X_EXTERN void b4x_lcd_write_str(unsigned char x, unsigned char y, char *s);

/**
 * Set cursor position and writes a string on the LCD that is allocated on
 * the program memory.
 * @param x X.
 * @param y Y.
 */
B4X_EXTERN void b4x_lcd_write(unsigned char x, unsigned char y, const char *s);

/**
 * Set cursor position and the content length to be erased from the LCD.
 * @param x X.
 * @param y Y.
 * @param l Content length.
 */
B4X_EXTERN void b4x_lcd_erase(unsigned char x, unsigned char y, unsigned char l);

/**
 * Set cursor position and writes a character on the LCD.
 * @param x X.
 * @param y Y.
 */
#define B4X_LCD_WRITE_CHR(x, y, c) do { \
    b4x_lcd_pos((x), (y)); \
    b4x_lcd_putc((c)); \
} while (0)

/**
 * Set cursor position and writes a string on the LCD that is allocated on
 * the RAM.
 * @param x X.
 * @param y Y.
 */
#define B4X_LCD_WRITE_STR(x, y, s) do { \
    b4x_lcd_pos((x), (y)); \
    b4x_lcd_puts((s)); \
} while (0)

/**
 * Set cursor position and writes a string on the LCD that is allocated on
 * the program memory.
 * @param x X.
 * @param y Y.
 */
#define B4X_LCD_WRITE(x, y, s) do { \
    b4x_lcd_pos((x), (y)); \
    b4x_lcd_putrs((s)); \
} while (0)

/**
 * Set cursor position and the content length to be erased from the LCD.
 * @param x X.
 * @param y Y.
 * @param l Content length.
 */
#define B4X_LCD_ERASE(x, y, l) do { \
    b4x_lcd_pos((x), (y)); \
    for (unsigned char i = 0; i < (l); i++) \
        b4x_lcd_putc(0x20); \
} while (0)

#ifdef __cplusplus
}
#endif

#endif