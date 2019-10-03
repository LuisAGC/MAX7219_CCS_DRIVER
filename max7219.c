#include <max7219.h>

void max7219_TurnOnAllDisplays(unsigned int16 loadPin){
   unsigned int8 counter = 0;
   output_low(loadPin);
   for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){                                                        
      _max7219_ShiftDataOut(MAX7219_SHUTDOWN_REG, MAX7219_NOSHUTDOWN);
   }
   output_high(loadPin);
   output_low(loadPin);
}

void max7219_TestAllDisplays(int1 test, unsigned int16 loadPin){
   unsigned int8 counter = 0;
   output_low(loadPin);
   for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
      _max7219_ShiftDataOut(MAX7219_TESTDISPLAY_REG, test);
   }
   output_high(loadPin);
   output_low(loadPin);
}

int1 max7219_TestDisplay(unsigned int8 displayNumber, int1 test, unsigned int16 loadPin){
   if(displayNumber >= MAX7219_DISPLAYS_AMOUNT) return FALSE;
   unsigned int8 counter = 0;
   output_low(loadPin);
   for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
      if(counter == displayNumber){
         _max7219_ShiftDataOut(MAX7219_TESTDISPLAY_REG, test);
      }
      else{
         _max7219_ShiftDataOut(MAX7219_NOOP, MAX7219_NOOP);
      }
   }
   output_high(loadPin);
   output_low(loadPin);
   return TRUE;
}

int1 max7219_SetDigitsDecode(unsigned int8 displayNumber, unsigned int8 digitSetup, unsigned int16 loadPin){
   if(displayNumber >= MAX7219_DISPLAYS_AMOUNT) return FALSE;
   unsigned int8 counter = 0;
   output_low(loadPin);
   for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
      if(counter == displayNumber){
         _max7219_ShiftDataOut(MAX7219_DECODEMODE_REG, digitSetup);
      }
      else{
         _max7219_ShiftDataOut(MAX7219_NOOP, MAX7219_NOOP);
      }
   }
   output_high(loadPin);
   output_low(loadPin);
   return TRUE;
}

int1 max7219_SetDigitValue(unsigned int8 displayNumber, unsigned int8 digitRegister, unsigned int8 digitValue, unsigned int16 loadPin){
   if(displayNumber >= MAX7219_DISPLAYS_AMOUNT) return FALSE;
   unsigned int8 counter = 0;
   output_low(loadPin);
   for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
      if(counter == displayNumber){
         _max7219_ShiftDataOut(digitRegister, digitValue);
      }
      else{
         _max7219_ShiftDataOut(MAX7219_NOOP, MAX7219_NOOP);
      }
   }
   output_high(loadPin);
   output_low(loadPin);
   return TRUE;
}

void max7219_ClearAllDisplays(unsigned int16 loadPin){
   unsigned int8 counter = 0;
   unsigned int8 digit = 0;
   output_low(loadPin);
   for(digit = MAX7219_D0_REG; digit <= MAX7219_D7_REG; digit++){
      for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
         _max7219_ShiftDataOut(digit, MAX7219_NOOP);
      }
      output_high(loadPin);
      output_low(loadPin);
   }
}

int1 max7219_ClearDisplay(unsigned int8 displayNumber, unsigned int16 loadPin){
   if(displayNumber >= MAX7219_DISPLAYS_AMOUNT) return FALSE;
   unsigned int8 counter = 0;
   unsigned int8 digit = 0;
   output_low(loadPin);
   for(digit = MAX7219_D0_REG; digit <= MAX7219_D7_REG; digit++){
      for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
         if(counter == displayNumber){
            _max7219_ShiftDataOut(digit, MAX7219_NOOP);
         }
         else{
            _max7219_ShiftDataOut(MAX7219_NOOP, MAX7219_NOOP);
         }
      }
      output_high(loadPin);
      output_low(loadPin);
   }
   return TRUE;
}

void max7219_ScanAllDisplays(unsigned int16 loadPin){
   unsigned int8 counter = 0;
   output_low(loadPin);
   for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
      _max7219_ShiftDataOut(MAX7219_SCANLIMIT_REG, MAX7219_SCAN_ALL);
   }
   output_high(loadPin);
   output_low(loadPin);
}

int1 max7219_ScanDisplayDigits(unsigned int8 displayNumber, unsigned int8 scanConfiguration, unsigned int16 loadPin){
   if(displayNumber >= MAX7219_DISPLAYS_AMOUNT) return FALSE;
   unsigned int8 counter = 0;
   output_low(loadPin);
   for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
      if(counter == displayNumber){
         _max7219_ShiftDataOut(MAX7219_SCANLIMIT_REG, scanConfiguration);
      }
      else{
         _max7219_ShiftDataOut(MAX7219_NOOP, MAX7219_NOOP);
      }
   }
   output_high(loadPin);
   output_low(loadPin);
   return TRUE;
}

void max7219_SetAllDisplaysIntensity(unsigned int8 intensity, unsigned int16 loadPin){
   unsigned int8 counter = 0;
   output_low(loadPin);
   for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
      _max7219_ShiftDataOut(MAX7219_INTENSITY_REG, intensity);
   }
   output_high(loadPin);
   output_low(loadPin);
}

int1 max7219_SetDisplayIntensity(unsigned int8 displayNumber, unsigned int8 intensityConfiguration, unsigned int16 loadPin){
   if(displayNumber >= MAX7219_DISPLAYS_AMOUNT) return FALSE;
   unsigned int8 counter = 0;
   output_low(loadPin);
   for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
      if(counter == displayNumber){
         _max7219_ShiftDataOut(MAX7219_INTENSITY_REG, intensityConfiguration);
      }
      else{
         _max7219_ShiftDataOut(MAX7219_NOOP, MAX7219_NOOP);
      }
   }
   output_high(loadPin);
   output_low(loadPin);
   return TRUE;
}

void max7219_SendArray(unsigned int8* data, unsigned int8 digitRegister, unsigned int16 loadPin){
   unsigned int8 counter = 0;
   output_low(loadPin);
   for(counter = 0; counter < MAX7219_DISPLAYS_AMOUNT; counter++){
      _max7219_ShiftDataOut(digitRegister, data[counter]);
   }
   output_high(loadPin);
   output_low(loadPin);
}

#ifdef MAX7219_NO_SPI
void _max7219_ShiftDataOut(unsigned int8 registerAddress, unsigned int8 data){
   unsigned int8 counter = 0;
   for(counter = 0; counter < 8; counter++){
      output_bit(DOUT_PIN, (registerAddress >> (7 - counter)) & 0x01);
      output_high(CLK_PIN);
      output_low(CLK_PIN);
   }
   for(counter = 0; counter < 8; counter++){
      output_bit(DOUT_PIN, (data >> (7 - counter)) & 0x01);
      output_high(CLK_PIN);
      output_low(CLK_PIN);
   }
}
#else
void _max7219_ShiftDataOut(unsigned int8 registerAddress, unsigned int8 data){
   spi_write(registerAddress);
   spi_write(data);
}
#endif
