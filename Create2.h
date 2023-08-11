// Create2.h
//
/// CODE WAS FORKED AND ADAPTED FROM THE ARDUINO ROOBA LIBRARY BY THE FOLLOWING AUTHORS:

/// \par Revision History
/// \version 1.0 Initial Release

/// \author Susan Tuvell (susan.tuvell@hws.edu) 
/// \author Duncan Lilley (duncan.lilley@hws.edu)
/// \author Thanks to Mike McCauley (mikem@airspayce.com)
// Copyright (C) 2015 Susan Tuvell and Duncan Lilley

/// ORIGINAL COPYRIGHT NOTICE:

/// This software is Copyright (C) 2015 Susan Tuvell and Duncan Lilley.
/// Adaptation from Roomba.h Arduino Library Copyright (C) 2010 Mike McCauley (mikem@airspayce.com)
/// Use is subject to license conditions. The main licensing options available are GPL V2 or Commercial:
///
/// \par Open Source Licensing GPL V2
/// This is the appropriate option if you want to share the source code of your
/// application with everyone you distribute it to, and you also want to give them
/// the right to share who uses it. If you wish to use this software under Open
/// Source Licensing, you must contribute all your source code to the open source
/// community in accordance with the GPL Version 2 when your application is
/// distributed. See http://www.gnu.org/copyleft/gpl.html
/// 
/// \par Commercial Licensing
/// This is the appropriate option if you are creating proprietary applications
/// and you are not prepared to distribute and share the source code of your
/// application. Contact info@airspayce.com for details.

#ifndef Create2_h
#define Create2_h


/// Masks for LEDs in leds()
#define CREATE2_MASK_LED_NONE 		0x0
#define CREATE2_MASK_LED_DEBRIS 	    	0x1
#define CREATE2_MASK_LED_SPOT 		0x2
#define CREATE2_MASK_LED_DOCK 		0x4
#define CREATE2_MASK_LED_CHECKROBOT 	0x8

/// Mask for Roomba only motors:
#define CREATE2_MASK_MOTOR_SIDE 	 	0x1
#define CREATE2_MASK_MOTOR_VACUUM 	0x2
#define CREATE2_MASK_MOTOR_MAIN 		0x4
#define CREATE2_MASK_MOTOR_SIDE_DIR 	0x8
#define CREATE2_MASK_MOTOR_MAIN_DIR 	0x10

/// Masks for bumps and wheedrops sensor packet ID 7
#define CREATE2_MASK_BUMP_RIGHT 		0x1
#define CREATE2_MASK_BUMP_LEFT 		0x2
#define CREATE2_MASK_WHEELDROP_RIGHT 	0x4
#define CREATE2_MASK_WHEELDROP_LEFT 	0x8

/// Masks for driver overcurrents Packet ID 14
#define CREATE2_MASK_SIDE_BRUSH 		0x1
#define CREATE2_MASK_MAIN_BRUSH 		0x4
#define CREATE2_MASK_RIGHT_WHEEL 		0x8
#define CREATE2_MASK_LEFT_WHEEL 		0x10
// Roomba, use CREATE2_MASK_SIDE_BRUSH,  CREATE2_MASK_VACUUM, CREATE2_MASK_MAIN_BRUSH

/// Masks for buttons sensor packet ID 18
#define CREATE2_MASK_BUTTON_CLEAN 	0x1
#define CREATE2_MASK_BUTTON_SPOT 		0x2
#define CREATE2_MASK_BUTTON_DOCK 		0x4
#define CREATE2_MASK_BUTTON_MIN 		0x8
#define CREATE2_MASK_BUTTON_HOUR 		0x10
#define CREATE2_MASK_BUTTON_DAY 		0x20
#define CREATE2_MASK_BUTTON_SCHEDULE 	0x40
#define CREATE2_MASK_BUTTON_CLOCK 	0x80 

// Masks for charging sources sensor packet ID 34
#define CREATE2_MASK_INTERNAL_CHARGER 	0x1
#define CREATE2_MASK_HOME_BASE         0x2

/// \def CREATE2_READ_TIMEOUT
/// Read timeout in milliseconds.
/// If we have to wait more than this to read a char when we are expecting one, then something is wrong.
#define CREATE2_READ_TIMEOUT 		200





/// \enum Baud
/// Demo types to pass to Create2::baud()
typedef enum{
  Baud300 				= 0,
  Baud600 				= 1,
  Baud1200 				= 2,
  Baud2400 				= 3,
  Baud4800 				= 4,
  Baud9600 				= 5,
  Baud14400 				= 6,
  Baud19200 				= 7,
  Baud28800 				= 8,
  Baud38400 				= 9,
  Baud57600 				= 10,
  Baud115200 			= 11,
} Baud;

/// \enum Drive
/// Special values for radius in Create2::drive()
  typedef enum{
    DriveStraight 				= 0x8000,
    DriveInPlaceClockwise 		= 0xFFFF,
    DriveInPlaceCounterClockwise 	= 0x0001,
} Drive;

/// \enum StreamCommand 
/// Values to pass to Create2::streamCommand()
typedef enum{
  StreamCommandPause 			= 0,
  StreamCommandResume 			= 1,
} StreamCommand;

/// \enum IRCommand
/// Values for sensor packet ID 27
typedef enum{
  //IR Remote Control
  IRCommandLeft 				= 129,
  IRCommandForward 			= 130,
  IRCommandRight 				= 131,
  IRCommandSpot 				= 132,
  IRCommandMax 				= 133,
  IRCommandSmall 				= 134,
  IRCommandMedium 				= 135,
  IRCommandLargeClean 			= 136,
  IRCommandStop 				= 137,
  IRCommandPower 				= 138,
  IRCommandArcForwardLeft 		= 139,
  IRCommandArcForwardRight 		= 140,
  IRCommandDriveStop 			= 141,
  // Scheduling Remote:
  IRCommandDownload 			= 142,
  IRCommandSeekDock 			= 143,
  // Roomba Discovery Drive on Charge:
  IRCommandReserved1 			= 240,
  IRCommandRedBuoy 			= 248,
  IRCommandGreenBuoy 			= 244, 
  IRCommandForceField 			= 242,
  IRCommandRedGreenBuoy 		= 252,
  IRCommandRedBuoyForceField 		= 250,
  IRCommandGreenBuoyForceField 	= 246,
  IRCommandRedGreenBuoyForceField 	= 254,
} IRCommand;

/// \enum ChargeState
/// Values for sensor packet ID 21
typedef enum{
  ChargeStateNotCharging 			= 0,
  ChargeStateReconditioningCharging 	= 1,
  ChargeStateFullChanrging 			= 2,
  ChargeStateTrickleCharging 			= 3,
  ChargeStateWaiting 				= 4,
  ChargeStateFault 				= 5,
} ChargeState;

/// \enum OIMode
/// Values for sensor packet ID 35
typedef enum{
  ModeOff     			= 0,
  ModePassive 			= 1,
  ModeSafe    			= 2,	
  ModeFull    			= 3,
} OIMode;

/// \enum Sensor
/// Values for sensor packet IDs to pass to sensors() and queryList()
typedef enum{
  Sensors7to26 				= 0,
  Sensors7to16 				= 1,
  Sensors17to20 				= 2,
  Sensors21to26 				= 3,
  Sensors27to34 				= 4,
  Sensors35to42 				= 5,
  Sensors7to42 				= 6,
  Sensors7to58 				= 100,
  Sensors43to58 				= 101,
  Sensors46to51 				= 106,
  Sensors54to58 				= 107,
  SensorBumpsAndWheelDrops 		= 7,
  SensorWall 				= 8,
  SensorCliffLeft 				= 9,
  SensorCliffFrontLeft 			= 10,
  SensorCliffFrontRight 		= 11,
  SensorCliffRight 			= 12,
  SensorVirtualWall 			= 13,
  SensorOvercurrents 			= 14,
  SensorDirtDetect 			= 15,
//    SensorUnused1 				= 16,
  SensorIRopCode 				= 17,
  SensorButtons 				= 18,
  SensorDistance 				= 19,
  SensorAngle 				= 20,
  SensorChargingState 			= 21,
  SensorVoltage 				= 22,
  SensorCurrent 				= 23,
  SensorTemperature 			= 24,
  SensorBatteryCharge 			= 25,
  SensorBatteryCapacity 		= 26,
  SensorWallSignal 			= 27,
  SensoCliffLeftSignal 			= 28,
  SensoCliffFrontLeftSignal 		= 29,
  SensoCliffFrontRightSignal 		= 30,
  SensoCliffRightSignal 		= 31,
//    SensorUnused2	 			= 32,
//    SensorUnused3 				= 33,
  SensorChargerAvailable 		= 34,
  SensorOIMode 				= 35,
  SensorSongNumber 			= 36,
  SensorSongPlaying 			= 37,
  SensorOIStreamNumPackets 		= 38,
  SensorVelocity 				= 39,
  SensorRadius 				= 40,
  SensorRightVelocity 			= 41,
  SensorLeftVelocity 			= 42,
  SensorEncoderCountsLeft 		= 43,
  SensorEncoderCountsRight 		= 44,
  SensorLightBumper 			= 45,
  SensorLightBumperLeft 		= 46,
  SensorLightBumperFrontLeft 		= 47,
  SensorLightBumperCenterLeft 	= 48,
  SensorLightBumperCenterRight 	= 49,
  SensorLightBumperFrontRight 	= 50,
  SensorLightBumperRight 		= 51,
  SensorIRopCodeLeft 			= 52,
  SensorIRopCodeRight 			= 53,
  SensorLeftMotorCurrent 		= 54,
  SensorRightMotorCurrent 		= 55,
  SensorMainBrushCurrent 		= 56,
  SensorSideBrushCurrent 		= 57,
  SensorStasis	 			= 58,
} Sensor;


///Initialize serial connection to Roomba
/// Defaults to 57600, the default for the Roomba.

void roombInit();
// Create 2 commands

/// Resets the Create 2. 
/// It will emit its startup message
/// Caution, this may take several seconds to complete
void roombaReset(); //opCode-7

/// Starts the Open Interface and sets the mode to Passive. 
/// You must send this before sending any other commands.
/// Initialises the serial port to the baud rate given in the constructor
void roombaStart(); //opCode-128

/// Sets the OI to Safe mode.
/// In Safe mode, the cliff and wheel drop detectors work to prevent Roomba driving off a cliff
void roombaSafeMode(); //opCode-131

/// Sets the OI to Full mode.
/// In Full mode, the cliff and wheel drop detectors do not stop the motors: you are responsible
/// for full control of the Roomba
void roombaFullMode(); //opCode-132

/// Puts a Roomba in sleep mode.
///
void roombaPower(); //opCode-133

/// Starts the spot cover mode
/// Changes mode to Passive
void roombaSpot(); //opCode-134

/// Starts the defaul cleaning mode
/// Changes mode to Passive
void roombaClean(); //opCode-135

/// Starts the max cleaning mode
/// Changes mode to Passive
void roombaMax(); //opCode-136

/// Starts the Create 2 driving with a specified wheel velocity and radius of turn
/// \param[in] velocity Speed in mm/s 
/// -500 to 500
/// \param[in] radius Radius of the turn in mm. 
/// -2000 to 2000
/// Any of the special values in enum Create2::Drive may be used instead of a radius value
void drive(int16_t velocity, int16_t radius); //opCode-137. 

/// Controls the forward and backward motion of Roomba's main brush, side brush, and
/// vacuum independently. All motors will run at maximum speed when enabled
/// \param[in] motorBits Bitmask of outputs to enable.
/// ORed combination of CREATE2_MASK_DRIVER_*
void motors(int8_t motorBits); //opCode-138. 

/// Controls the LEDs on the Create
/// \param[in] leds Bitmask specifying which LEDs to activate. 
/// ORed combination of CREATE2_MASK_LED_*
/// \param[in] powerColor The colour of the Power LED. 
/// 0 to 255: 0 = green, 255 = red, intermediate values are intermediate colours
/// \param[in] powerIntensity Power LED intensity. 
/// 0 to 255. 0 = off, 255 = full intensity
void LEDs(uint8_t leds, uint8_t powerColor, uint8_t powerIntensity); //opCode-139. 

/// Defines a song which can later be played with playSong()
/// \param[in] songNumber Song number for this song. 
/// 0 to 4
/// \param[in] data Array of note/duration pairs. See Open Interface manual for details. 
/// 2 bytes per note, first byte is the note and the second is the duration.
/// \param[in] length Length of notes array in bytes, so this will be twice the number of notes in the song
void roombaSong(uint8_t songNumber, const uint8_t* data, int length); //opCode-140.

/// Plays a song that has previously been defined by song()
/// \param[in] songNumber The song number to play. 
/// 0 to 15
void roombaPlaySong(uint8_t songNumber); //opCode-141.

/// Causes roomba to immediately seek the docking station.
///
void roombaSeekDock(); //opCode-143

/// Sets the duty cycle of the PWM outputs for low side driver.
/// This is used to drive the main brush, side brush, and vacuum at various speeds.
/// For the main brush and side brush, positive values turn the motor in the default
/// direction and negative values turn it in the opposite direction. The vacuum only
/// runs in one direction.
/// \param[in] mainBrush Duty cycle for the main brush. 
/// -127 to 127
/// \param[in] sideBrush Duty cycle for the side brush.
/// -127 to 127
/// \param[in] vacuum Duty cycle for the vacuum.
/// 0 to 127
void roombaPWMmotors(uint8_t mainBrush, uint8_t sideBrush, uint8_t vacuum); //opCode-144

/// Starts the Roomba driving with a specified velocity for each wheel
/// \param[in] rightVelocity Right wheel velocity in mm/s 
/// -500 to 500
/// \param[in] leftVelocity Left wheel velocity in mm/s 
/// -500 to 500
void roombaDriveDirect(int16_t rightVelocity, int16_t leftVelocity); //opCode-145

/// Starts the Roomba driving with a specified PWM for each wheel
/// \param[in] rightPWM Right wheel PWM 
/// -255 to 255
/// \param[in] leftPWM Left wheel PWM 
/// -255 to 255
void roombaDrivePWM(int16_t rightPWM, int16_t leftPWM); //opCode-146

/// Controls the state of the scheduleing LEDs on the Roomba.
/// See the Open Interface for details on the parameters.
/// No change to mode
/// \param[in] weekdayBits bitmask for the weekday LEDs
/// \param[in] schedulingBits bitmask for the scheduling LEDs
void roombaScheduleLEDs(uint8_t weekdayBits, uint8_t schedulingBits); //opCode-162

/// Controls the four 7-segment displays on the Roomba.
/// Digits are ordered from left to right on the robot 3,2,1,0.
/// No change to mode
/// <B>Note:</B> the OI states that this command should use bitmasks to control the individual
/// segments of each 7-segment display. However, it instead displays the number which is
/// passed in as a parameter. So, 0x1 = 1, 0x2 = 2, etc.
/// \param[in] digit3 Bitmask for the leftmost digit.
/// \param[in] digit2 Bitmask for the second digit from the left.
/// \param[in] digit1 Bitmask for the second digit from the right.
/// \param[in] digit0 Bitmask for the rightmost digit.
void roombaDigitLEDsRaw(uint8_t digit3, uint8_t digit2, uint8_t digit1, uint8_t digit0); //opCode-163

/// Controls the four 7-segment displays on the Roomba using ASCII code.
/// See the Open Interface for a chart of ASCII values.
/// No change to mode
/// \param[in] digit3 ASCII code for the leftmost display.
/// \param[in] digit2 ASCII code for the second display from the left.
/// \param[in] digit1 ASCII code for the second dispaly from the right.
/// \param[in] digit0 ASCII code for the rightmost display.
void roombaDigitLEDsASCII(uint8_t digit3, uint8_t digit2, uint8_t digit1, uint8_t digit0); //opCode-164
/// Lets you push Roomba's buttons. Code equilalent of pushing a button. 
/// Button will automatically release after 1/6th of a second
/// No change to mode
/// \param[in] buttons Bitmask for the button being 'pressed'.
/// ORed combination of CREATE2_MASK_BUTTON_*
void roombaButtons(uint8_t buttons); //opCode-165

/// This command sends Roomba a new schedule. 
/// To clear the schedule, send all 0s.
/// No change to mode
/// \param[in] days Bitmask for which days the schedule is being set
/// \param[in] schedule Array holding the hour and minute for the schedule for each day.
/// This is in the format [Sun Hour][Sun Minute][Mon Hour][Mon Minute]...[Sat Hour][Sat Minute]
void roombaSchedule(uint8_t days, uint8_t* schedule); //opCode-167

/// This command sets Roomba's clock
/// No change to mode
/// \param[in] day The day of the week
/// 0 (Sunday) to 6 (Saturday)
/// \param[in] hour The current hour
/// 0 to 23
/// \param[in] minute The current minute
/// 0 to 59
void roombaSetDayTime(uint8_t day, uint8_t hour, uint8_t minute); //opCode-168

/// Stops the OI - stops all streams and the robot will no longer take commands.
/// Changes mode to off
void roombaStop(); //opCode-173

#endif
