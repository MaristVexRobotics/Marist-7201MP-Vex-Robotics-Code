#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  button,         sensorTouch)
#pragma config(Sensor, I2C_1,  left,           sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  right,          sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_3,  armL,           sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           leftBack,      tmotorVex393, openLoop)
#pragma config(Motor,  port2,           leftBelt,      tmotorVex393, openLoop)
#pragma config(Motor,  port3,           leftFront,     tmotorVex393, openLoop, encoder, encoderPort, I2C_1, 1000)
#pragma config(Motor,  port4,           arm4,          tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           arm,           tmotorVex393, openLoop)
#pragma config(Motor,  port6,           arm2,          tmotorVex393, openLoop)
#pragma config(Motor,  port7,           arm3,          tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_3, 1000)
#pragma config(Motor,  port8,           rightFront,    tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_2, 1000)
#pragma config(Motor,  port9,           rightBelt,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port10,          rightBack,     tmotorVex393, openLoop, reversed)
#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

/*****************************************************\
|		Code by Konrad Kraemer														|
|																											|
|		Current Version 2.0.8.1														|
|																											|
|		Modular code to ease testing on VirtualWorlds.		|
|		Autonomous code records itself using the 					|
|		writeStream() function.														|
|																											|
|																											|
| 2.0.8.1 Tweak - correction value changed to .5 to   |
|						make the autonomous even less jumpy				|
|																											|
| 2.0.8 Modification - removed the lurching and 			|
|						anti-tippingcode because our drivers			|
|						thought it limited our mobility						|
|																											|
|	2.0.7 Feature Replacement - we decided that we need	|
|						full power, so we are dropping the 2.0.5	|
|						changes, and instead tweaking the accel		|
|																											|
|	2.0.6	Feature- software speed limiting to prevent		|
|						the robot from lurching forward if arm 		|
|						is fully up. This previously caused the		|
|						robot to flip.														|
|																											|
| 2.0.5	Feature- software arm limiting to prevent the	|
|						arm from exceding a certain height and		|
|						flipping the robot. Also, this code turns	|
|						off the automatic arm	power which would		|
|						keep it level.														|
|																											|
|	2.0.4.1 Tweak - ticks to give up changed to 500			|
|						ticks. Now it doesn't take soo long				|
|						to move on. Also, correction value				|
|						changed to 1 to make it less jumpy.				|
|										JANUARY 8, 2014										|
|																											|
|	2.0.4		BugFix - told robot to give up after				|
|						1000 ticks. Robot used to try to					|
|						complete a command indefinitely, if				|
|						it hit a wall, it would just sit there		|
|						and do nuthin, so now it gives up.				|
|								JANUARY 7, 2014												|
| 																										|
|	2.0.3.2	Tweak - deadzone changed to 27. 						|
|						Maximum speed	becomes 100 								|
|					JANUARY 6, 2014															|
|																											|
|	2.0.3.1	Bugfix - correction code wasn't working.		|
|						motor values went to -3000s. Problem was	|
|						that I accidentaly read the left encoder	|
|						instead of the right encoder 							|
|							JANUARY 6, 2014													|
|																											|
|	2.0.3	Bugfix - some motors were having problems			|
|					catching up with the others, added code to  |
|					set the max speed for motors during					|
|					recording to 127 MINUS the value of 				|
|					variable deadzone (max 122).								|
|						 JANUARY 6, 2014													|
|																											|
|	2.0.2	Bugfix - same problem as 2.0.1, I solved it		|
|					by having the code wait any encoder reaches	|
|					its predefined target for that cycle.				|
|						JANUARY 5, 2014														|
|																											|
|	2.0.1	Bugfix - since the recording code takes more	|
|					time to execute than the autonomous, the		|
|					autonomous code ends up running a tad too		|
|					quickly. I started fixing this by forcing 	|
|					certain parts of the code to execute at			|
|					a certain time, however I abandoned this		|
|					approach and went with another (2.0.2)			|
|							JANUARY 4, 2014													|
|																											|
|	2.0		Complete rewrite - modular code to aid 				|
|				testing in VirtualWorlds and make the code		|
|				more legible. Autonoumous recording now				|
|				supports full control with thumbsticks				|
|							December 28, 2013												|
|																											|
|	1.2		Rewrote Autonomous - Working	- FALL 2013			|
|					Codes itself, uses D-pad controls						|
|					(fwd,back,turnLeft,turnRight)								|
|																											|
|	1.1		Added self-writing Autonomous									|
|					Was unfunctional, witten early 2013					|
|																											|
|	1.0		Original Version Of remote code	Late 2012			|
|																											|
|																											|
\*****************************************************/

//=====================
//includes
//=====================
#include "Vars.h" // file for global vars

#include "Robot.h"  //when using actual robot
#include "VexRC.h"

#include "Autonomous.c" // main autonomous file, includes more files

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
  resetVars(); // reset all values (encoders and variables)
	//Autonomous();
	//AutoBF();
	//AutoBB(); //Doesn't work
	AutoRF();
	//AutoRB(); //Doesn't work
  /*wait10Msec(100);
  motor[arm] = 50;
	motor[arm2] = 50;
	motor[arm3] = 50;
	motor[arm4] = 50;
	wait10Msec(70);
	motor[arm] = 0;
	motor[arm2] = 0;
	motor[arm3] = 0;
	motor[arm4] = 0;
	motor[rightBelt] = 127;
	motor[leftBelt] = 127;*/
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
	  RC(); // recieve inputs
		RunRobot();
	}
}
