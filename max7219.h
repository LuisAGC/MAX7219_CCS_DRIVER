
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

/**
 * Sends turn on instructions to all MAX7219 and then loads the data using the
 * specified pin in the arguments.
 * 
 * @param loadPin This is the pin that will be used to load the data
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return Nothing, void method
 */
void max7219_TurnOnAllDisplays(unsigned int16);


/**
 * Sends turn on instructions to one MAX7219 and NOOP to the other devices 
 * and then loads the data using the specified pin in the argument.
 * 
 * @param displayNumber This is the number of the display that will be turned on
 * @param loadPin This is the pin that will be used to load the data
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return True if the display number is within the defined amount (define as MAX7219_DISPLAYS_AMOUNT), false otherwise
 */
int1 max7219_TurnOnDisplay(unsigned int8, unsigned int16);

/**
 * Sends instructions to either test or not test all MAX7219 and then loads the data using the
 * specified pin in the arguments.
 * 
 * @param test Value to determine if all the displays will be tested or not
 * @param loadPin This is the pin that will be used to load the data
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return Nothing, void method
 */
void max7219_TestAllDisplays(int1, unsigned int16);

/**
 * Sends instructions to either test or not test one MAX7219 and NOOP to the other devices 
 * and then loads the data using the specified pin in the argument.
 * 
 * @param displayNumber This is the number of the display that will be turned on
 * @param test Value to determine if the display will be tested or not
 * @param loadPin This is the pin that will be used to load the data
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return True if the display number is within the defined amount (define as MAX7219_DISPLAYS_AMOUNT), false otherwise
 */
int1 max7219_TestDisplay(unsigned int8, int1, unsigned int16);

/**
 * Sends instructions to use BCD decoding in the specified digits of one MAX7219 
 * and NOOP to the other devices and then loads the data using the specified pin in the argument.
 * 
 * @param displayNumber This is the number of the display that will be turned on
 * @param digitSetup Value to determine which digits will use decoding
 * @param loadPin This is the pin that will be used to load the data
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return True if the display number is within the defined amount (define as MAX7219_DISPLAYS_AMOUNT), false otherwise
 */
int1 max7219_SetDigitsDecode(unsigned int8, unsigned int8, unsigned int16);

/**
 * Sends instructions to set the value of an specific digit if one MAX7219 
 * and NOOP to the other devices and then loads the data using the specified pin in the argument.
 * 
 * @param displayNumber This is the number of the display that will be turned on
 * @param digitRegister Value to determine which digit will be set
 * @param digitValue Value to be set in the digit
 * @param loadPin This is the pin that will be used to load the data
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return True if the display number is within the defined amount (define as MAX7219_DISPLAYS_AMOUNT), false otherwise
 */
int1 max7219_SetDigitValue(unsigned int8, unsigned int8, unsigned int8, unsigned int16);

/**
 * Sends instructions to clear all the digits in all MAX7219
 * and then loads the data using the specified pin in the argument.
 * 
 * @param loadPin This is the pin that will be used to load the data
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return Nothing, void method
 */
void max7219_ClearAllDisplays(unsigned int16);

/**
 * Sends instructions to clear all the digits of an specific MAX7219 
 * and NOOP to the other devices and then loads the data using the specified pin in the argument.
 * 
 * @param displayNumber This is the number of the display that will be turned on
 * @param loadPin This is the pin that will be used to load the data
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return True if the display number is within the defined amount (define as MAX7219_DISPLAYS_AMOUNT), false otherwise
 */
int1 max7219_ClearDisplay(unsigned int8, unsigned int16);

/**
 * Sends instructions to scan (scanning means if a digit will be turned on,
 * this is particularly useful for 7-segment displays) all the digits in all MAX7219
 * and then loads the data using the specified pin in the argument.
 * 
 * @param loadPin This is the pin that will be used to load the data
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return Nothing, void method
 */
void max7219_ScanAllDisplays(unsigned int16);

/**
 * Sends instructions to scan (scanning means if a digit will be turned on,
 * this is particularly useful for 7-segment displays) the digits specified in one MAX7219
 * and then loads the data using the specified pin in the argument.
 * 
 * @param displayNumber This is the number of the display that will be turned on
 * @param scanConfiguration This is the scanning configuration to be used
 * @param loadPin This is the pin that will be used to load the data
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return True if the display number is within the defined amount (define as MAX7219_DISPLAYS_AMOUNT), false otherwise
 */
int1 max7219_ScanDisplayDigits(unsigned int8, unsigned int8, unsigned int16);

/**
 * Sends instructions to set the brightness intensity of all MAX7219
 * and then loads the data using the specified pin in the argument.
 * 
 * @param intensity Level of intensity that will be used
 * @param loadPin This is the pin that will be used to load the data
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return Nothing, void method
 */
void max7219_SetAllDisplaysIntensity(unsigned int8, unsigned int16);

/**
 * Sends  to set the brightness intensity in one MAX7219
 * and then loads the data using the specified pin in the argument.
 * 
 * @param displayNumber This is the number of the display that will be turned on
 * @param intensity Level of intensity that will be used
 * @param loadPin This is the pin that will be used to load the data
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return True if the display number is within the defined amount (define as MAX7219_DISPLAYS_AMOUNT), false otherwise
 */
int1 max7219_SetDisplayIntensity(unsigned int8, unsigned int8, unsigned int16);

/**
 * Iterates an byte array and pushes each byte along a digit register in all MAX7219
 * and then loads the data using the specified pin in the argument.
 * Used to send data in bulk and do less operations.
 * 
 * @param data The array of data that will be sent
 * @param digitRegister Digit of each MAX7219 that will be used to store the data
 * @param loadPin This is the pin that will be used to load the data
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return Nothing, void method
 */
void max7219_SendArray(unsigned int8*, unsigned int8, unsigned int16);

/**
 * Utility method to push the data into the MAX7219, can be either sent using SPI
 * or bit-banged.
 * To use SPI configure the peripheral using setup_spi() method included with the compiler,
 * MAX7219 maximum speed is 10MHz.
 * SPI configuration snippet: setup_spi(SPI_MASTER | SPI_L_TO_H | SPI_CLK_DIV_4 | SPI_XMIT_L_TO_H )
 *
 * To use bit-banging and define the pins to be used define the following in the preprocessor directives:
 * CLK_PIN, DOUT_PIN, MAX7219_NO_SPI. Note: MAX7219_NO_SPI can be any value
 *
 * Configuration snippet:
 * #define CLK_PIN PIN_B0
 * #define DOUT_PIN PIN_B1
 * #define MAX7219_NO_SPI 0xFF
 * #include <max7219.c>
 *
 * @param registerAddress The address that will be used
 * @param data The data that will be stored in the register
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return Nothing, void method
 */
void _max7219_ShiftDataOut(unsigned int8, unsigned int8);
