#ifndef MAX7219_DRIVER
   #include <max7219.c>
#endif
#ifndef MAX7219_DIGITS_AMOUNT
   #define MAX7219_DIGITS_AMOUNT 0x08
#endif
#ifndef MAX7219_DISPLAYS_AMOUNT
   #define MAX7219_DISPLAYS_AMOUNT 0x04
#endif


unsigned int8 ledMatrix[MAX7219_DIGITS_AMOUNT][MAX7219_DISPLAYS_AMOUNT];

void _shiftRowLeft(unsigned int8);
void shiftMatrixLeft();
void _shiftRowRight(unsigned int8);
void shiftMatrixRight();
void _shiftRowUp(unsigned int8);
void shiftMatrixUp();
void _shiftRowDown(unsigned int8);
void shiftMatrixDown();
