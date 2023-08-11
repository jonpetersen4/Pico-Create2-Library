
/* ADAPTED FROM ADRUINO CREATE 2 LIBRARY:
 * Create2.cpp Library for iRobot Roomba Create2
 * Created by Duncan Lilley and Susan Tuvell
 * Last edit 5/12/2015
 */


#include "Create2.h"
#include <stdio.h>
#include "pico/stdlib.h"


#define UART_ID uart0
#define BAUD_RATE 115200 //DEFAULT ROOMBA BAUD RATE
#define UART_TX_PIN 0
#define UART_RX_PIN 1

void roombaInit(){
    uart_init(UART_ID, 115200);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    uart_set_hw_flow(UART_ID, false, false);
    uart_set_format(UART_ID, 8, 1, UART_PARITY_NONE);
    uart_set_fifo_enabled(UART_ID, false);
}

//GETTING STARTED COMMANDS

// Start OI
// Changes mode to passive
void roombaStart(){
    uart_putc_raw(UART_ID, 128); 
}

// Reset the Roomba
void roombaReset(){
  uart_putc_raw(UART_ID, 7);
}

// Stops the OI. 
void roombaStop(){
    uart_putc_raw(UART_ID, 173); 
}

//Baud opcode 129
//skipping this and just using default baud rate


//MODE COMMANDS


// Puts the OI into Safe mode, enabling user control of the Roomba.
// Turns off all LEDs.
// OI can be in any mode to accept this command.
void roombaSafe(){
    uart_putc_raw(UART_ID, 131); 
}

// Puts the OI into Full mode, giving you complete control over the Roomba.
// Turns off the cliff, wheel-drop and internal charger safety features. 
void roombaFull(){
    uart_putc_raw(UART_ID, 132); 
}

//CLEANING COMMANDS

// Starts the default cleaning mode
void roombaClean(){
    uart_putc_raw(UART_ID, 135); 
}

// Starts the Max cleaning mode
void roombaMaxClean(){
    uart_putc_raw(UART_ID, 136); 
}

// Starts the Spot cleaning mode
void roombaSpot(){
    uart_putc_raw(UART_ID, 134); 
}

// Powers down Create. The OI can be in any state.
void roombaPower(){
    uart_putc_raw(UART_ID, 133); 
}

// Sends the Roomba to the dock.
void roombaSeekDock(){
    uart_putc_raw(UART_ID, 143); 
}

// Sends Roomba a new schedule.
// This takes in a 14 slot array filled with hours and minutes for each day of the week
void roombaSchedule(uint8_t days, uint8_t* schedule){
  uart_putc_raw(UART_ID, 167);
  uart_putc_raw(UART_ID, days);
  uart_write_blocking(UART_ID, schedule, 14);
}

// Sets Roomba's clock
void roombaSetDayTime(uint8_t day, uint8_t hour, uint8_t minute){
  uart_putc_raw(UART_ID, 168);
  uart_putc_raw(UART_ID, day);
  uart_putc_raw(UART_ID, hour);
  uart_putc_raw(UART_ID, minute);
}

//ACTUATOR COMMANDS

// Controls Roomba's drive wheels
void roombaDrive(int16_t velocity, int16_t radius){
  uart_putc_raw(UART_ID, 137);
  uart_putc_raw(UART_ID, (velocity & 0xff00) >> 8);
  uart_putc_raw(UART_ID, velocity & 0xff);
  uart_putc_raw(UART_ID, (radius & 0xff00) >> 8);
  uart_putc_raw(UART_ID, radius & 0xff);
}

// Controls the forward and backward motion of the Roomba's drive wheels independently.
void roombaDriveDirect(int16_t rightVelocity, int16_t leftVelocity){
  uart_putc_raw(UART_ID, 145);
  uart_putc_raw(UART_ID, (rightVelocity & 0xff00) >> 8);
  uart_putc_raw(UART_ID, rightVelocity & 0xff);
  uart_putc_raw(UART_ID, (leftVelocity & 0xff00) >> 8);
  uart_putc_raw(UART_ID, leftVelocity & 0xff);
}

//Controls the raw forward and backward motion of Roomba's drive wheels indepentently.
void roombaDrivePWM(int16_t rightPWM, int16_t leftPWM){
  uart_putc_raw(UART_ID, 146);
  uart_putc_raw(UART_ID, (rightPWM & 0xff00) >> 8);
  uart_putc_raw(UART_ID, rightPWM & 0xff);
  uart_putc_raw(UART_ID, (leftPWM & 0xff00) >> 8);
  uart_putc_raw(UART_ID, leftPWM & 0xff);
}

// Controls the forward and backward motion of 
//Roomba's main brush, side brush, and vacuum independently.

void roombaMotors(int8_t motorBits){
  uart_putc_raw(UART_ID, 138);
  uart_putc_raw(UART_ID, motorBits);
}

// Lets you control the speed of the Roomba's main brush, 
//side brush and vacuum independently. 
void roombaPWMMotors(int8_t mainBrush, int8_t sideBrush, int8_t vacuum){
  uart_putc_raw(UART_ID, 144);
  uart_putc_raw(UART_ID, mainBrush);
  uart_putc_raw(UART_ID, sideBrush);
  uart_putc_raw(UART_ID, vacuum);
}

// Controls LEDs common to all models of Roomba 600
void roombaLEDs(uint8_t leds, uint8_t powerColor, uint8_t powerIntensity){
  uart_putc_raw(UART_ID, 139);
  uart_putc_raw(UART_ID, leds);
  uart_putc_raw(UART_ID, powerColor);
  uart_putc_raw(UART_ID, powerIntensity);
}

// Controls the state of the scheduling LEDs present on the Roomba 560 and 570.
void roombaScheduleLEDs(uint8_t weekdayBits, uint8_t schedulingBits){
  uart_putc_raw(UART_ID, 162);
  uart_putc_raw(UART_ID, weekdayBits);
  uart_putc_raw(UART_ID, schedulingBits);
}

// Controls the four 7 segment displays on the Rommba 560 and 570.}
void roombaDigitLEDsRaw(uint8_t digit3, uint8_t digit2, uint8_t digit1, uint8_t digit0){
  uart_putc_raw(UART_ID, 163);
  uart_putc_raw(UART_ID, digit3);
  uart_putc_raw(UART_ID, digit2);
  uart_putc_raw(UART_ID, digit1);
  uart_putc_raw(UART_ID, digit0);
}

// Lets you push the Roomba's buttons electronically.
void roombaButtons(uint8_t buttons){
  uart_putc_raw(UART_ID, 165);
  uart_putc_raw(UART_ID, buttons);
}

// Controls the four 7 segment displays on the Roomba 560 and 570 usign ASCII character codes.
void roombaDigitLEDsASCII(uint8_t digit3, uint8_t digit2, uint8_t digit1, uint8_t digit0){
  uart_putc_raw(UART_ID, 164);
  uart_putc_raw(UART_ID, digit3);
  uart_putc_raw(UART_ID, digit2);
  uart_putc_raw(UART_ID, digit1);
  uart_putc_raw(UART_ID, digit0);
}

// Lets you specify up to four songs to the OI that you can play at a later time.
void roombaSong(uint8_t songNumber, const uint8_t* data, int length){
  uart_putc_raw(UART_ID, 140);
  uart_putc_raw(UART_ID, songNumber);
  uart_putc_raw(UART_ID, length); //length here is number of notes for roomba
  uart_write_blocking(UART_ID,data,length << 1); //data includes notes and rests, so shifting by 1 to double the length
}

// Selects a song from the songs added to the Roomba using the Song command.
void roombaPlaySong(uint8_t songNumber){
  uart_putc_raw(UART_ID, 141);
  uart_putc_raw(UART_ID, songNumber);
}
