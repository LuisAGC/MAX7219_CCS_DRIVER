#include <max7219_matrix.h>

void _shiftRowLeft(unsigned int8 row){
   unsigned int8 counter = 0;
   for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
      if(counter == (MAX7219_DISPLAYS_AMOUNT - 1)){
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
   for(counter = 0; counter < MAX7219_DIGITS_AMOUNT; counter++){
      _shiftRowLeft(counter);
   }
}

void _shiftRowRight(unsigned int8 row){
   signed int8 counter = 0;
   for(counter = MAX7219_DISPLAYS_AMOUNT - 1; counter >= 0; counter--){
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
   for(counter = 0; counter < MAX7219_DIGITS_AMOUNT; counter++){
      _shiftRowRight(counter);
   }
}

void _shiftRowUp(unsigned int8 row){
   signed int8 counter = 0;
   for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
         ledMatrix[row][counter] = ledMatrix[row+1][counter];
   }
}

void shiftMatrixUp(){
   unsigned int8 counter = 0;
   for(counter = 0; counter < MAX7219_DIGITS_AMOUNT - 1; counter++){
         _shiftRowUp(counter);
   }
   for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
         ledMatrix[MAX7219_DIGITS_AMOUNT-1][counter] = 0x00;
   }
}

void _shiftRowDown(unsigned int8 row){
   signed int8 counter = 0;
   for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
         ledMatrix[row][counter] = ledMatrix[row-1][counter];
   }
}

void shiftMatrixDown(){
   unsigned int8 counter = 0;
   for(counter = MAX7219_DIGITS_AMOUNT - 1; counter >= 1 ; counter--){
         _shiftRowDown(counter);
   }
   for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
         ledMatrix[0][counter] = 0x00;
   }
}