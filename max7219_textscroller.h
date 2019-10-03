#include <font.h>
#ifndef  MAX7219_DRIVER   
    #include <max7219.c>
#endif
#ifndef MAX7219_MATRIX_MIDDLEWARE
    #include <max7219_matrix.c>
#endif

#define SCROLLER_COLUMN_AMOUNT MAX7219_DIGITS_AMOUNT * MAX7219_DISPLAYS_AMOUNT


unsigned int8 currentCharIndex = 0;
unsigned int8 currentCharColumn = 0;
unsigned int8 currentScrollerColumn = 0;


int1 shiftCharacterColumnToMatrix(unsigned char, unsigned int8);
int1 scrollMessageLeftMatrixDisplay(unsigned char *, unsigned int8, unsigned int16);
int1 clearMatrixDisplay(unsigned int16);
