#ifndef MAX7219_DIGITS_AMOUNT
   #define MAX7219_DIGITS_AMOUNT 0x08
#endif
#ifndef MAX7219_DISPLAYS_AMOUNT
   #define MAX7219_DISPLAYS_AMOUNT 0x04
#endif

#define MATRIX_COLUMNS MAX7219_DISPLAYS_AMOUNT
#define MATRIX_ROWS MAX7219_DIGITS_AMOUNT

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
