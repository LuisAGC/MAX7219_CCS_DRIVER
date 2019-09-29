#include <max7219_matrix.h>

void _shiftRowLeft(unsigned int8 row){
   unsigned int8 counter = 0;
   for(counter = 0; counter < MATRIX_COLUMNS; counter++){
      if(counter == (MATRIX_COLUMNS - 1)){
         ledMatrix[row][counter] <<= 1;
      }
      else{
         ledMatrix[row][counter] <<= 1;
         ledMatrix[row][counter] |= (ledMatrix[row][counter+1] >> 7) & 0x01;
      }
   }
}

void shiftMatrixLeft(){
   unsigned int8 counter = 0;
   for(counter = 0; counter < MATRIX_ROWS; counter++){
      _shiftRowLeft(counter);
   }
}

void _shiftRowRight(unsigned int8 row){
   signed int8 counter = 0;
   for(counter = MATRIX_COLUMNS - 1; counter >= 0; counter--){
      if(counter == 0){
         ledMatrix[row][counter] >>= 1;
      }
      else{
         ledMatrix[row][counter] >>= 1;
         ledMatrix[row][counter] |= (ledMatrix[row][counter-1] & 0x01) << 7;
      }
   }
}

void shiftMatrixRight(){
   unsigned int8 counter = 0;
   for(counter = 0; counter < MATRIX_ROWS; counter++){
      _shiftRowRight(counter);
   }
}

void _shiftRowUp(unsigned int8 row){
   signed int8 counter = 0;
   for(counter = 0; counter < MATRIX_COLUMNS; counter++){
         ledMatrix[row][counter] = ledMatrix[row+1][counter];
   }
}

void shiftMatrixUp(){
   unsigned int8 counter = 0;
   for(counter = 0; counter < MATRIX_ROWS - 1; counter++){
         _shiftRowUp(counter);
   }
   for(counter = 0; counter < MATRIX_COLUMNS; counter++){
         ledMatrix[MATRIX_ROWS-1][counter] = 0x00;
   }
}

void _shiftRowDown(unsigned int8 row){
   signed int8 counter = 0;
   for(counter = 0; counter < MATRIX_COLUMNS; counter++){
         ledMatrix[row][counter] = ledMatrix[row-1][counter];
   }
}

void shiftMatrixDown(){
   unsigned int8 counter = 0;
   for(counter = MATRIX_ROWS - 1; counter >= 1 ; counter--){
         _shiftRowDown(counter);
   }
   for(counter = 0; counter < MATRIX_COLUMNS; counter++){
         ledMatrix[0][counter] = 0x00;
   }
}

void clearMatrix(){
   unsigned int8 row = 0;
   unsigned int8 column = 0;
   for(row = 0; row < MATRIX_ROWS; row++){
      for(column = 0; column < MATRIX_COLUMNS; column++){
         ledMatrix[row][column] = 0x00;
      }
   }
}
