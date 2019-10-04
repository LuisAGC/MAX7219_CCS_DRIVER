#include <font.h>
#ifndef MAX7219_DIGITS_AMOUNT
   #define MAX7219_DIGITS_AMOUNT 0x08
#endif
#ifndef MAX7219_DISPLAYS_AMOUNT
   #define MAX7219_DISPLAYS_AMOUNT 0x04
#endif
#ifndef MAX7219_VERTICAL_DISPLAYS_AMOUNT
   #define MAX7219_VERTICAL_DISPLAYS_AMOUNT 0x01
#endif
#define MATRIX_COLUMNS MAX7219_DISPLAYS_AMOUNT
#define MATRIX_SUBCOLUMNS MATRIX_COLUMNS*8
#define MATRIX_ROWS MAX7219_DIGITS_AMOUNT*MAX7219_VERTICAL_DISPLAYS_AMOUNT

#define MAX7219_MATRIX_MIDDLEWARE 0xFF

unsigned int8 ledMatrix[MATRIX_ROWS][MATRIX_COLUMNS];

void _shiftRowLeft(unsigned int8);
void shiftMatrixLeft(void);
void _shiftRowRight(unsigned int8);
void shiftMatrixRight(void);
void _shiftRowUp(unsigned int8);
void shiftMatrixUp(void);
void _shiftRowDown(unsigned int8);
void shiftMatrixDown(void);
void clearMatrix(void);
int1 putPixel(signed int16, signed int16);
void drawLine(signed int16, signed int16, signed int16, signed int16);
void _drawLineLow(signed int16, signed int16, signed int16, signed int16);
void _drawLineHigh(signed int16, signed int16, signed int16, signed int16);
void drawRectangle(signed int16, signed int16, signed int16, signed int16);
void drawCircle(signed int16, signed int16, signed int16);
void sendMatrix(unsigned int16 *);
void drawCharacter(signed int16, signed int16, char);
void drawString(signed int16, signed int16, char *, unsigned int8, unsigned int8);
void clearPartialMatrix(signed int16, signed int16, signed int16, signed int16);
