#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_1,  left,           sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  right,          sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_3,  armL,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_4,  armR,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           leftBack,      tmotorVex393, openLoop)
#pragma config(Motor,  port2,           leftBelt,      tmotorVex393, openLoop)
#pragma config(Motor,  port3,           leftFront,     tmotorVex393, openLoop, encoder, encoderPort, I2C_1, 1000)
#pragma config(Motor,  port4,           rightFront,    tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_2, 1000)
#pragma config(Motor,  port5,           arm,           tmotorVex393, openLoop)
#pragma config(Motor,  port6,           arm2,          tmotorVex393, openLoop, encoder, encoderPort, I2C_4, 1000)
#pragma config(Motor,  port7,           arm3,          tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_3, 1000)
#pragma config(Motor,  port8,           arm4,          tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port9,           rightBelt,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port10,          rightBack,     tmotorVex393, openLoop, reversed)
#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

float EL = .7;
float ER = 1;

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
#include "RC1.h"
#include "Autonomous.c"

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
  // .....................................................................................
  // Insert user code here.
  // .....................................................................................

	//AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
	Autonomous();
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
	while (1)
		RC1();
}
