#include <max7219_matrix.h>

void _shiftRowLeft(unsigned int16 row){
   unsigned int16 counter = 0;
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

void clearPartialMatrix(signed int16 x0, signed int16 y0, signed int16 x1, signed int16 y1){
   unsigned int16 x = x0;
   unsigned int16 y = y0;
   for(x = x0; x <= x1; x++){
      for(y = y0; y <= y1; y++){
         unsigned int16 column = x/8 ;
         unsigned int16 subColumn = x - column * 8;
         ledMatrix[y][column] &= ~(0x80 >> subColumn);
      }
   }
}

int1 putPixel(signed int16 x, signed int16 y){   
   if(x < 0 || y < 0) return FALSE;
   
   unsigned int16 column = x >> 3 ;
   unsigned int16 subColumn = x - (column << 3);
   
   if(x >= MATRIX_SUBCOLUMNS || y >= MATRIX_ROWS) return false;
   ledMatrix[y][column] |= 0x80 >> subColumn;
   return TRUE;
}

void drawLine(signed int16 x0, signed int16 y0, signed int16 x1, signed int16 y1){
   if (abs(y1 - y0) < abs(x1 - x0)){
      if (x0 > x1){
         _drawLineLow(x1, y1, x0, y0);
      }
      else{
        _drawLineLow(x0, y0, x1, y1);
      }
   }
   else{
      if (y0 > y1) {
         _drawLineHigh(x1, y1, x0, y0);
      }
      else {
         _drawLineHigh(x0, y0, x1, y1);
      }
   }
}

void _drawLineLow(signed int16 x0, signed int16 y0, signed int16 x1, signed int16 y1){
   signed int16 dx = x1 - x0;
   signed int16 dy = y1 - y0;
   signed int16 yi = 1;
   if(dy < 0){
      yi = -1;
      dy = -dy;
   }
   signed int16 D = 2*dy - dx;
   signed int16 y = y0;
   signed int16 x = 0;
   for(x = x0; x <= x1; x++){
      putPixel(x, y);
      if(D > 0){
         y = y + yi;
         D = D - 2*dx;
      }
      D = D + 2*dy;
   }
}

void _drawLineHigh(signed int16 x0, signed int16 y0, signed int16 x1, signed int16 y1){
   signed int16 dx = x1 - x0;
   signed int16 dy = y1 - y0;
   signed int16 xi = 1;
   if(dx < 0){
      xi = -1;
      dx = -dx;
   }
   signed int16 D = 2*dx - dy;
   signed int16 y = 0;
   signed int16 x = x0;
   for(y = y0; y <= y1; y++){
      putPixel(x, y);
      if(D > 0){
         x = x + xi;
         D = D - 2*dy;
      }
      D = D + 2*dx;
   }
}

void drawRectangle(signed int16 x0, signed int16 y0, signed int16 width, signed int16 height){
   signed int16 x1 = x0 + (width - 1);
   signed int16 y1 = y0 + (height - 1);
   drawLine(x0, y0, x1, y0);
   drawLine(x0, y1, x1, y1);
   drawLine(x0, y0, x0, y1);
   drawLine(x1, y0, x1, y1);
}

void drawCircle(signed int16 xc, signed int16 yc, signed int16 radius){
   radius = radius - 1;
   signed int16 x = 0;
   signed int16 y = radius;
   signed int16 D = 3-(2*radius);
   while(x <= y){
      putPixel(y+xc, x+yc);            
      putPixel(x+xc, y+yc);            
      putPixel(-x+xc, y+yc);          
      putPixel(-y+xc, x+yc);          
      putPixel(-y+xc, -x+yc);        
      putPixel(-x+xc, -y+yc);        
      putPixel(x+xc, -y+yc);         
      putPixel(y+xc, -x+yc);
      
      if (D<0) {
         D=D+4*x+6;
         x++;
         }
      else {
         D=D+4*(x-y)+10;
         x++;
         y--;
      }
   }
}

void drawCharacter(signed int16 x, signed int16 y, char character){
   unsigned int8 fontHeightCounter = 0;
   unsigned int8 fontWidthCounter = 0;
   for(fontWidthCounter = 0; fontWidthCounter < FONT_WIDTH; fontWidthCounter++){
      for(fontHeightCounter = 0; fontHeightCounter < FONT_HEIGHT; fontHeightCounter++){
         if(font[character - FONT_OFFSET][fontWidthCounter] & (0x01 << fontHeightCounter)){
            putPixel(x+fontWidthCounter, y+fontHeightCounter);
         }
      }
   }
}

void drawString(signed int16 x, signed int16 y, char * string, unsigned int8 stringLength, unsigned int8 spacing){
   unsigned int8 counter = 0;
   for(counter = 0; counter < stringLength; counter++){
      drawCharacter(x, y, string[counter]);
      x = x + FONT_WIDTH + spacing;
   }
}

void sendMatrix( unsigned int16 * loadPinArray){
   unsigned int8 counter = 0;
   unsigned int8 pinIndex = 0;
   for(pinIndex = 0; pinIndex < MAX7219_VERTICAL_DISPLAYS_AMOUNT; pinIndex++){
      for(counter = MAX7219_D0_REG; counter <= MAX7219_D7_REG; counter++){
         unsigned int8 matrixIndex = (pinIndex*MAX7219_DIGITS_AMOUNT) + counter - 1;
         max7219_SendArray(ledMatrix[matrixIndex], counter, loadPinArray[pinIndex]);
      }
   }
}
