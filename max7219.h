
/***************************************
The following section is to define the
MAX7219 register addresses
*****************************************/
#define MAX7219_NOOP                0x00
#define MAX7219_D0_REG              0x01
#define MAX7219_D1_REG              0x02
#define MAX7219_D2_REG              0x03
#define MAX7219_D3_REG              0x04
#define MAX7219_D4_REG              0x05
#define MAX7219_D5_REG              0x06
#define MAX7219_D6_REG              0x07
#define MAX7219_D7_REG              0x08
#define MAX7219_DECODEMODE_REG      0x09
#define MAX7219_INTENSITY_REG       0x0A
#define MAX7219_SCANLIMIT_REG       0x0B
#define MAX7219_SHUTDOWN_REG        0x0C
#define MAX7219_TESTDISPLAY_REG     0x0F

/****************************************
The following section is to define the
MAX7219 shutdown register operations
available
*****************************************/
#define MAX7219_SHUTDOWN            0x00
#define MAX7219_NOSHUTDOWN          0x01

/****************************************
The following section is to define the
MAX7219 decode values for each
individual digits. Decoding is BCD format
*****************************************/
#define MAX7219_D0_DECODE           0x01
#define MAX7219_D1_DECODE           0x02
#define MAX7219_D2_DECODE           0x04
#define MAX7219_D3_DECODE           0x08
#define MAX7219_D4_DECODE           0x10
#define MAX7219_D5_DECODE           0x20
#define MAX7219_D6_DECODE           0x40
#define MAX7219_D7_DECODE           0x80
#define MAX7219_ALL_DECODE          0xFF

/****************************************
The following section is to define the
MAX7219 decode character values. 
Decoding is BCD format
*****************************************/
#define MAX7219_BCD_0               0x00
#define MAX7219_BCD_1               0x01
#define MAX7219_BCD_2               0x02
#define MAX7219_BCD_3               0x03
#define MAX7219_BCD_4               0x04
#define MAX7219_BCD_5               0x05
#define MAX7219_BCD_6               0x06
#define MAX7219_BCD_7               0x07
#define MAX7219_BCD_8               0x08
#define MAX7219_BCD_9               0x09
#define MAX7219_BCD_MINUS           0x0A
#define MAX7219_BCD_E               0x0B
#define MAX7219_BCD_H               0x0C
#define MAX7219_BCD_L               0x0D
#define MAX7219_BCD_P               0x0E
#define MAX7219_BCD_BLANK           0x0F
#define MAX7219_BCD_DOT             0x80

/****************************************
The following section is to define the
MAX7219 shutdown register operations
available
*****************************************/
#define MAX7219_NOTEST              0x00
#define MAX7219_TEST                0x01

/****************************************
The following section is to define the
MAX7219 scan digit register operations
available
*****************************************/
#define MAX7219_SCAN_0              0x00
#define MAX7219_SCAN_0_1            0x01
#define MAX7219_SCAN_0_1_2          0x02
#define MAX7219_SCAN_0_1_2_3        0x03
#define MAX7219_SCAN_0_1_2_3_4      0x04
#define MAX7219_SCAN_0_1_2_3_4_5    0x05
#define MAX7219_SCAN_0_1_2_3_4_5_6  0x06
#define MAX7219_SCAN_ALL            0x07

/****************************************
The following section is to define the
MAX7219 intensity register operations
available
*****************************************/
#define MAX7219_INTENSITY_0         0x00
#define MAX7219_INTENSITY_1         0x01
#define MAX7219_INTENSITY_2         0x02
#define MAX7219_INTENSITY_3         0x03
#define MAX7219_INTENSITY_4         0x04
#define MAX7219_INTENSITY_5         0x05
#define MAX7219_INTENSITY_6         0x06
#define MAX7219_INTENSITY_7         0x07
#define MAX7219_INTENSITY_8         0x08
#define MAX7219_INTENSITY_9         0x09
#define MAX7219_INTENSITY_A         0x0A
#define MAX7219_INTENSITY_B         0x0B
#define MAX7219_INTENSITY_C         0x0C
#define MAX7219_INTENSITY_D         0x0D
#define MAX7219_INTENSITY_E         0x0E
#define MAX7219_INTENSITY_F         0x0F

#define MAX7219_DIGITS_AMOUNT       0x08

#define MAX7219_DRIVER              0xFF

#ifndef CLK_PIN
   #define CLK_PIN PIN_C3
#endif

#ifndef DOUT_PIN
   #define DOUT_PIN PIN_C5
#endif

#ifndef MAX7219_DISPLAYS_AMOUNT
   #define MAX7219_DISPLAYS_AMOUNT 0x04
#endif


void max7219_TurnOnAllDisplays(unsigned int16);
int1 max7219_TurnOnDisplay(unsigned int8, unsigned int16);
void max7219_TestAllDisplays(int1, unsigned int16);
int1 max7219_TestDisplay(unsigned int8, int1, unsigned int16);
int1 max7219_SetDigitsDecode(unsigned int8, unsigned int8, unsigned int16);
int1 max7219_SetDigitValue(unsigned int8, unsigned int8, unsigned int8, unsigned int16);
void max7219_ClearAllDisplays(unsigned int16);
int1 max7219_ClearDisplay(unsigned int8, unsigned int16);
void max7219_ScanAllDisplays(unsigned int16);
int1 max7219_ScanDisplayDigits(unsigned int8, unsigned int8, unsigned int16);
void max7219_SetAllDisplaysIntensity(unsigned int8, unsigned int16);
int1 max7219_SetDisplayIntensity(unsigned int8, unsigned int8, unsigned int16);
void max7219_SendArray(unsigned int8*, unsigned int8, unsigned int16);
void _max7219_ShiftDataOut(unsigned int8, unsigned int8);
