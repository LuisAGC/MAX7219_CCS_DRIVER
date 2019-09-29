#include <16F877A.h> //This example was made with the PIC16F877A in mind, modify to match yours
#device ADC=10

#FUSES PUT                      //Power Up Timer

#use delay(crystal=20000000) 
#define MAX7219_DISPLAYS_AMOUNT 0x04 //Be sure to change this to the amount of MAX7219 devices you have otherwise you might see some weird functionality
#define LOAD_PIN PIN_C0 // Override this if you need to use another pin to load the data into the devices
#include <max7219_textscroller.c>

