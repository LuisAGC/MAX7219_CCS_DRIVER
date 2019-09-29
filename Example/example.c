#include <example.h>

unsigned char message[41] = "Hola Mundo, este es un texto muy largo!!!";
unsigned int8 messageSize = 41;



void main() {
   output_low(LOAD_PIN);
   setup_spi(SPI_MASTER | SPI_L_TO_H | SPI_CLK_DIV_4 | SPI_XMIT_L_TO_H );
   max7219_ClearAllDisplays();
   max7219_ScanAllDisplays();
   max7219_TurnOnAllDisplays();
   max7219_SetAllDisplaysIntensity(MAX7219_INTENSITY_0);
   max7219_TestAllDisplays(MAX7219_TEST);
   delay_ms(2000);
   max7219_TestAllDisplays(MAX7219_NOTEST);
   max7219_ClearAllDisplays();
   clearMatrix();
   while(TRUE){
      while(!scrollMessageLeftMatrixDisplay(message, messageSize)){
         delay_ms(35);
      }
      while(!clearMatrixDisplay()){
         delay_ms(35);
      }
   }
}


