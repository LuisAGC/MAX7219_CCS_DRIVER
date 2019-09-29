#include <max7219.h>

void max7219_TurnOnAllDisplays(){
   unsigned int8 counter = 0;
   output_low(LOAD_PIN);
   for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
      spi_write(MAX7219_SHUTDOWN_REG);
      spi_write(MAX7219_NOSHUTDOWN);
   }
   output_high(LOAD_PIN);
   output_low(LOAD_PIN);
}

void max7219_TestAllDisplays(int1 test){
   unsigned int8 counter = 0;
   output_low(LOAD_PIN);
   for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
      spi_write(MAX7219_TESTDISPLAY_REG);
      spi_write(test);
   }
   output_high(LOAD_PIN);
   output_low(LOAD_PIN);
}

int1 max7219_TestDisplay(unsigned int8 displayNumber, int1 test){
   if(displayNumber >= MAX7219_DISPLAYS_AMOUNT) return FALSE;
   unsigned int8 counter = 0;
   output_low(LOAD_PIN);
   for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
      if(counter == displayNumber){
         spi_write(MAX7219_TESTDISPLAY_REG);
         spi_write(test);
      }
      else{
         spi_write(MAX7219_NOOP);
         spi_write(MAX7219_NOOP);
      }
   }
   output_high(LOAD_PIN);
   output_low(LOAD_PIN);
   return TRUE;
}

int1 max7219_SetDigitsDecode(unsigned int8 displayNumber, unsigned int8 digitSetup){
   if(displayNumber >= MAX7219_DISPLAYS_AMOUNT) return FALSE;
   unsigned int8 counter = 0;
   output_low(LOAD_PIN);
   for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
      if(counter == displayNumber){
         spi_write(MAX7219_DECODEMODE_REG);
         spi_write(digitSetup);
      }
      else{
         spi_write(MAX7219_NOOP);
         spi_write(MAX7219_NOOP);
      }
   }
   output_high(LOAD_PIN);
   output_low(LOAD_PIN);
   return TRUE;
}

int1 max7219_SetDigitValue(unsigned int8 displayNumber, unsigned int8 digitRegister, unsigned int8 digitValue){
   if(displayNumber >= MAX7219_DISPLAYS_AMOUNT) return FALSE;
   unsigned int8 counter = 0;
   output_low(LOAD_PIN);
   for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
      if(counter == displayNumber){
         spi_write(digitRegister);
         spi_write(digitValue);
      }
      else{
         spi_write(MAX7219_NOOP);
         spi_write(MAX7219_NOOP);
      }
   }
   output_high(LOAD_PIN);
   output_low(LOAD_PIN);
   return TRUE;
}

void max7219_ClearAllDisplays(){
   unsigned int8 counter = 0;
   unsigned int8 digit = 0;
   output_low(LOAD_PIN);
   for(digit = MAX7219_D0_REG; digit <= MAX7219_D7_REG; digit++){
      for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
         spi_write(digit);
         spi_write(MAX7219_NOOP);
      }
      output_high(LOAD_PIN);
      output_low(LOAD_PIN);
   }
}

int1 max7219_ClearDisplay(unsigned int8 displayNumber){
   if(displayNumber >= MAX7219_DISPLAYS_AMOUNT) return FALSE;
   unsigned int8 counter = 0;
   unsigned int8 digit = 0;
   output_low(LOAD_PIN);
   for(digit = MAX7219_D0_REG; digit <= MAX7219_D7_REG; digit++){
      for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
         if(counter == displayNumber){
         spi_write(digit);
         spi_write(MAX7219_NOOP);
      }
      else{
         spi_write(MAX7219_NOOP);
         spi_write(MAX7219_NOOP);
      }
      }
      output_high(LOAD_PIN);
      output_low(LOAD_PIN);
   }
   return TRUE;
}

void max7219_ScanAllDisplays(){
   unsigned int8 counter = 0;
   output_low(LOAD_PIN);
   for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
      spi_write(MAX7219_SCANLIMIT_REG);
      spi_write(MAX7219_SCAN_ALL);
   }
   output_high(LOAD_PIN);
   output_low(LOAD_PIN);
}

int1 max7219_ScanDisplayDigits(unsigned int8 displayNumber, unsigned int8 scanConfiguration){
   if(displayNumber >= MAX7219_DISPLAYS_AMOUNT) return FALSE;
   unsigned int8 counter = 0;
   output_low(LOAD_PIN);
   for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
      if(counter == displayNumber){
         spi_write(MAX7219_SCANLIMIT_REG);
         spi_write(scanConfiguration);
      }
      else{
         spi_write(MAX7219_NOOP);
         spi_write(MAX7219_NOOP);
      }
   }
   output_high(LOAD_PIN);
   output_low(LOAD_PIN);
   return TRUE;
}

void max7219_SetAllDisplaysIntensity(unsigned int8 intensity){
   unsigned int8 counter = 0;
   output_low(LOAD_PIN);
   for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
      spi_write(MAX7219_INTENSITY_REG);
      spi_write(intensity);
   }
   output_high(LOAD_PIN);
   output_low(LOAD_PIN);
}

int1 max7219_SetDisplayIntensity(unsigned int8 displayNumber, unsigned int8 intensityConfiguration){
   if(displayNumber >= MAX7219_DISPLAYS_AMOUNT) return FALSE;
   unsigned int8 counter = 0;
   output_low(LOAD_PIN);
   for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
      if(counter == displayNumber){
         spi_write(MAX7219_INTENSITY_REG);
         spi_write(intensityConfiguration);
      }
      else{
         spi_write(MAX7219_NOOP);
         spi_write(MAX7219_NOOP);
      }
   }
   output_high(LOAD_PIN);
   output_low(LOAD_PIN);
   return TRUE;
}

void max7219_SendArray(unsigned int8* data, unsigned int8 digitRegister){
   unsigned int8 counter = 0;
   output_low(LOAD_PIN);
   for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
      spi_write(digitRegister);
      spi_write(data[counter]);
   }
   output_high(LOAD_PIN);
   output_low(LOAD_PIN);
}
