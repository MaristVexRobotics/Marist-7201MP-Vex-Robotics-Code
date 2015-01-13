#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    gyro,           sensorGyro)
#pragma config(Sensor, in2,    leftScissorRot, sensorPotentiometer)
#pragma config(Sensor, in3,    rightScissorRot,sensorPotentiometer)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_4,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_5,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           rightFront,    tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_3, 1000)
#pragma config(Motor,  port2,           leftBack,      tmotorVex393, openLoop, encoder, encoderPort, I2C_1, 1000)
#pragma config(Motor,  port3,           rightBack,     tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_4, 1000)
#pragma config(Motor,  port4,           leftFront,     tmotorVex393, openLoop, encoder, encoderPort, I2C_2, 1000)
#pragma config(Motor,  port5,           rightScissor1, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           rightScissor2, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port7,           leftScissor1,  tmotorVex393, openLoop)
#pragma config(Motor,  port8,           leftScissor2,  tmotorVex393, openLoop)
#pragma config(Motor,  port9,           leftBelt,      tmotorVex393, openLoop)
#pragma config(Motor,  port10,          rightBelt,     tmotorVex393, openLoop, encoder, encoderPort, I2C_5, 1000)
#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

/*****************************************************\
|   Code by Konrad Kraemer                            |
|                                                     |
|   Current Version 3.0.1.1                           |
|                                                     |
|   Modular code to ease testing on VirtualWorlds.    |
|   Autonomous code records itself using the          |
|   writeStream() function.                           |
|                                                     |
|                                                     |
| 3.0.1.1 Fix - Fixed the competition template        |
|                                                     |
| 3.0.1 Feature - Added a gyroscope override. This is |
|           because the drive function previously     |
|           locked up if the robot was at all moved   |
|           while the gyroscope was being calibrated, |
|           this change allows the user to bypass the |
|           gyrosope in the case of an "emergency"    |
|                     JANUARY 13, 2015                |
|                                                     |
| 3.0   Rewrite - codebase completely rewritten to    |
|           acommodate the mechanum wheels, control   |
|           the scissor lift, and redo the autonomous |
|           to run from a library, instead of the     |
|           recording done in previous years. Also,   |
|           remote control code was modified to allow |
|           the controls to always be in-relation to  |
|           driver, regardless of the rotation of the |
|           robot.                                    |
|                                                     |
| 2.0.8.1 Tweak- correction value changed to .5 to    |
|           make the autonomous even less jumpy       |
|                                                     |
| 2.0.8 Modification- removed the lurching and        |
|           anti-tippingcode because our drivers      |
|           thought it limited our mobility           |
|                                                     |
| 2.0.7 Feature Replacement- we decided that we need  |
|           full power, so we are dropping the 2.0.5  |
|           changes, and instead tweaking the accel   |
|                                                     |
| 2.0.6	Feature- software speed limiting to prevent   |
|           the robot from lurching forward if arm    |
|           is fully up. This previously caused the   |
|           robot to flip.                            |
|                                                     |
| 2.0.5	Feature- software arm limiting to prevent the |
|           arm from exceding a certain height and    |
|           flipping the robot. Also, this code turns |
|           off the automatic arm power which would   |
|           keep it level.                            |
|                                                     |
| 2.0.4.1 Tweak- ticks to give up changed to 500      |
|           ticks. Now it doesn't take soo long       |
|           to move on. Also, correction value        |
|           changed to 1 to make it less jumpy.       |
|                                                     |
| 2.0.4	BugFix- told robot to give up after           |
|           1000 ticks. Robot used to try to          |
|           complete a command indefinitely, if       |
|           it hit a wall, it would just sit there    |
|           and do nuthin, so now it gives up.        |
|                                                     |
| 2.0.3.2 Tweak- deadzone changed to 27.              |
|           Maximum speed becomes 100                 |
|           JANUARY 6, 2014                           |
|                                                     |
| 2.0.3.1 Bugfix- correction code wasn't working.     |
|           motor values went to -3000s. Problem was  |
|           that I accidentaly read the left encoder  |
|           instead of the right encoder              |
|           JANUARY 6, 2014                           |
|                                                     |
| 2.0.3	Bugfix- some motors were having problems      |
|           catching up with the others, added code   |
|           to set the max speed for motors during    |
|           recording to 127 MINUS the value of       |
|           variable deadzone (max 122).              |
|           JANUARY 6, 2014                           |
|                                                     |
| 2.0.2	Bugfix- same problem as 2.0.1, I solved it    |
|           by having the code wait until any encoder |
|           reaches its predefined target for that    |
|           cycle.     JANUARY 5, 2014                |
|                                                     |
| 2.0.1 Bugfix- since the recording code takes more   |
|           time to execute than the autonomous, the  |
|           autonomous code ends up running a tad too |
|           quickly. I started fixing this by forcing |
|           certain parts of the code to execute at   |
|           a certain time, however I abandoned this  |
|           approach and went with another (2.0.2)    |
|           JANUARY 4, 2014                           |
|                                                     |
| 2.0  Complete rewrite- modular code to aid          |
|           testing in VirtualWorlds and make it      |
|           more legible. Autonoumous recording now   |
|           supports full control with thumbsticks    |
|           December 28, 2013                         |
|                                                     |
| 1.2 Rewrote Autonomous- Working - FALL 2013         |
|           Codes itself, uses D-pad controls         |
|           (fwd,back,turnLeft,turnRight)             |
|                                                     |
| 1.1 Added self-writing Autonomous                   |
|           Was not functional, witten early 2013     |
|                                                     |
| 1.0 Original Version Of remote code - Late 2012     |
|                                                     |
|                                                     |
\*****************************************************/

//=====================
//includes
//=====================
#include "Vars.h" // file for global vars
#include "calculateMotors.h"


#include "Robot.h"  //when using actual robot
#include "RC.h"

#include "autoControl.h"
#include "autoCode.h"


#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton() {
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

  resetVars(); // reset all variables
	resetSensors(); // reset all sensors
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous() {
  AutoRF();
  //AutoBF();
  //AutoRB();
  //AutoBB();
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol() {
	// User control code here, inside the loop

	while (true) {
		RC();  // recieve inputs
		calcMotorValues();
		RunRobot();
	}
}
