#include <font.h>
#ifndef MAX7219_DIGITS_AMOUNT
   #define MAX7219_DIGITS_AMOUNT 0x08
#endif
#ifndef MAX7219_DISPLAYS_AMOUNT
   #define MAX7219_DISPLAYS_AMOUNT 0x04
#endif
#ifndef MAX7219_VERTICAL_DISPLAYS_AMOUNT
   #define MAX7219_VERTICAL_DISPLAYS_AMOUNT 0x01
#endif
#define MATRIX_COLUMNS MAX7219_DISPLAYS_AMOUNT
#define MATRIX_SUBCOLUMNS MATRIX_COLUMNS*8
#define MATRIX_ROWS MAX7219_DIGITS_AMOUNT*MAX7219_VERTICAL_DISPLAYS_AMOUNT

#define MAX7219_MATRIX_MIDDLEWARE 0xFF

unsigned int8 ledMatrix[MATRIX_ROWS][MATRIX_COLUMNS];

/**
 * Shifts data to the left in the specified row of the in memory matrix
 * 
 * @param row Number of row to be shifted
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return Nothing, void method
 */
void _shiftRowLeft(unsigned int16);

/**
 * Shifts data to the left of the in memory matrix, depends on _shiftRowLeft
 * 
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return Nothing, void method
 */
void shiftMatrixLeft(void);

/**
 * Shifts data to the right in the specified row of the in memory matrix
 * 
 * @param row Number of row to be shifted
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return Nothing, void method
 */
void _shiftRowRight(unsigned int8);

/**
 * Shifts data to the left of the in memory matrix, depends on _shiftRowRight
 * 
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return Nothing, void method
 */
void shiftMatrixRight(void);

/**
 * Shifts data to the row above the specified row of the in memory matrix
 * 
 * @param row Number of row to be shifted
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return Nothing, void method
 */
void _shiftRowUp(unsigned int8);

/**
 * Shifts data of the in memory matrix upwards , depends on _shiftRowUp
 * 
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return Nothing, void method
 */
void shiftMatrixUp(void);

/**
 * Shifts data to the row below the specified row of the in memory matrix
 * 
 * @param row Number of row to be shifted
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return Nothing, void method
 */
void _shiftRowDown(unsigned int8);

/**
 * Shifts data of the in memory matrix downwards , depends on _shiftRowDown
 * 
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return Nothing, void method
 */
void shiftMatrixDown(void);

/**
 * Sets all the rows and columns values of the in memory matrix to zero 
 * 
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return Nothing, void method
 */
void clearMatrix(void);

/**
 * Sets the values of specific rows and columns of the in memory matrix to zero 
 * 
 * @param x0 The origin horizontal point of the section to be cleared
 * @param y0 The origin vertical point of the section to be cleared
 * @param x1 The last horizontal point of the section to be cleared
 * @param y1 The last vertical point of the section to be cleared
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return Nothing, void method
 */
void clearPartialMatrix(signed int16, signed int16, signed int16, signed int16);

/**
 * Sets the pixel at the given x and y coordinates as true 
 * 
 * @param x The horizontal coordinate of the pixel
 * @param y The vertical coordinate of the pixel
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return True if a valid coordinate, False otherwise (e.g. negative values will return False)
 */
int1 putPixel(signed int16, signed int16);

/**
 * Draws a line from a given coordinate to another, uses Bresenham algorithm to do the drawing.
 * Depends on _drawLineLow and _drawLineHigh to be able to draw lines in all octants
 * 
 * @param x0 The origin horizontal point of the line
 * @param y0 The origin vertical point of the line
 * @param x1 The end horizontal point of the line
 * @param y1 The end vertical point of the line
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return Nothing, void method
 */
void drawLine(signed int16, signed int16, signed int16, signed int16);

/**
 * Used to draw lines in the horizontal plane, uses Bresenham algorithm to do the drawing.
 * Depends on putPixel
 * 
 * @param x0 The origin horizontal point of the line
 * @param y0 The origin vertical point of the line
 * @param x1 The end horizontal point of the line
 * @param y1 The end vertical point of the line
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return Nothing, void method
 */
void _drawLineLow(signed int16, signed int16, signed int16, signed int16);

/**
 * Used to draw lines in the vertical plane, uses Bresenham algorithm to do the drawing.
 * Depends on putPixel
 * 
 * @param x0 The origin horizontal point of the line
 * @param y0 The origin vertical point of the line
 * @param x1 The end horizontal point of the line
 * @param y1 The end vertical point of the line
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return Nothing, void method
 */
void _drawLineHigh(signed int16, signed int16, signed int16, signed int16);

/**
 * Used to draw rectangular outlines in the matrix.
 * Depends on drawLine
 * 
 * @param x0 The origin horizontal point of the rectangle
 * @param y0 The origin vertical point of the rectangle
 * @param width The width of the rectangle in pixels
 * @param height The height of the rectangle in pixels
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return Nothing, void method
 */
void drawRectangle(signed int16, signed int16, signed int16, signed int16);

/**
 * Draws a circle with it's center on the given coordinates and radius, uses Bresenham circle algorithm to do the drawing.
 * 
 * @param xc The horizontal coordinate of the circle center
 * @param yc The vertical coordinate of the circle center
 * @param radius The circle radius
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return Nothing, void method
 */
void drawCircle(signed int16, signed int16, signed int16);

/**
 * Draws a character with it's origin on the given coordinates.
 * Depends on putPixel
 *
 * @param x The horizontal coordinate of the character origin
 * @param y The vertical coordinate of the character origin
 * @param character The character to be drawn
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return Nothing, void method
 */
void drawCharacter(signed int16, signed int16, char);

/**
 * Draws a string with it's origin on the given coordinates, also a spacing in can be given
 * to separate each character horizantally from each other.
 * Depends on drawCharacter
 *
 * @param x The horizontal coordinate of the string origin
 * @param y The vertical coordinate of the string origin
 * @param string The string to be drawn
 * @param stringLength The length of the string to be drawn
 * @param spacing The amount of horizontal pixels to be used as separation between characters
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return Nothing, void method
 */
void drawString(signed int16, signed int16, char *, unsigned int8, unsigned int8);

/**
 * Sends the data from the in memory matrix to the MAX7219 devices, this should be done
 * only after doing all the drawing and clearing operations to avoid unnecesary cycle wasting
 *
 * Depends on max7219.c so include it in your preprocessor directives like so:
 * #include <max7219.c>
 *
 * @param pinArray The array of the pins which will be used to load the data in each row of MAX7219
 * @author Luis Antonio Garcia Castañeda (LuisAGC)
 * @return Nothing, void method
 */
void sendMatrix(unsigned int16 *);
