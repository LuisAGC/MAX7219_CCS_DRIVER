#include <max7219_textscroller.h>

int1 shiftCharacterColumnToMatrix(unsigned char character, unsigned int8 column){
   if(column > FONT_WIDTH) return FALSE;
   unsigned int8 counter = 0;
   for(counter = 0; counter < FONT_HEIGHT; counter++){
      if(column == FONT_WIDTH){
         ledMatrix[counter][MATRIX_COLUMNS - 1] |= 0x00;
      }
      else{
         ledMatrix[counter][MATRIX_COLUMNS - 1] |= (font[character-FONT_OFFSET][column] >> counter) & 0x01; 
      }
   }
   return TRUE;
}

int1 scrollMessageLeftMatrixDisplay(unsigned char * message, unsigned int8 messageSize){
   if(currentCharColumn > FONT_WIDTH) {
      currentCharIndex++;
      currentCharColumn = 0;
   }
   if(currentCharIndex >= messageSize){
      currentCharIndex = 0;
      return TRUE;
   }
   shiftMatrixLeft();
   shiftCharacterColumnToMatrix(message[currentCharIndex], currentCharColumn);
   currentCharColumn++;
   unsigned int8 counter = 0;
   for(counter = 0; counter < MATRIX_ROWS; counter++){
      max7219_SendArray(ledMatrix[counter], counter+MAX7219_D0_REG);
   }
   return FALSE;
}
