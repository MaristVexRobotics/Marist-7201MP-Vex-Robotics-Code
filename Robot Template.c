#pragma config(Motor,  port1,           Left,          tmotorNormal, openLoop)
#pragma config(Motor,  port2,           Right,         tmotorNormal, openLoop)
#pragma config(Motor,  port1,           FL,          tmotorNormal, openLoop)
#pragma config(Motor,  port2,           FR,         tmotorNormal, openLoop)
#pragma config(Motor,  port3,           BL,          tmotorNormal, openLoop)
#pragma config(Motor,  port4,           BR,         tmotorNormal, openLoop)
#pragma config(Motor,  port5,           Arm,          tmotorNormal, openLoop)
#pragma config(Motor,  port6,           Claw,          tmotorServoStandard, openLoop)

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//     1 = omni
#define TYPE = 0
#define LOOPRC = 1


#define CLAWOPEN = 127
#define CLAWCLOSE = -127


#include "E:\Documents\Fun\robotics\Robot Template.h"











task main() {
  //Independent code Goes here




  //RC Starts
  RCMODE:;
  RC();
  #if LOOPRC = 1
	goto RCMODE;
  #endif
  }
}

















































/*  ===================================================================================================================================
    ===================================================================================================================================
                                                        Guide to Commands:




=======================
OmniDirectional:
=======================

-------------------------
Function move.
-------------------------

This causes the robot to move a certain distance at a certain speed. Then, returns control to main task.

SYNTAX: move(number of rotations foreward, number of rotations sideways right positive, speed 1 to 127);

EX:
move(7, -5, 17);

Moves robot 10 rotations foreward and 5 rotations Left at speed 17.


-------------------------
Funcion moveThenStop.
-------------------------

same as move, but stops robot quickly after distance. same syntax.


------------------------
Function moveThenGlide.
------------------------

same as moveThenStop, but instead of stopping quickly, it slows to a halt. same syntax


=======================
Standard Robot:
=======================


------------------------
Function move.
------------------------

This causes the robot to move a certain distance at a certain speed. Then, returns control to main task.

SYNTAX: move(number of rotations, speed -127 to 127);

EX:
move(10, 127);


Moves robot 10 rotations at speed 127.

------------------------
Funcion moveThenStop.
------------------------

same as move, but stops robot quickly after distance. same syntax.

------------------------
Function moveThenGlide.
------------------------

same as moveThenStop, but instead of stopping quickly, it slows to a halt. same syntax


=======================
Applies to all:
=======================

------------------------
Function turn
------------------------

turns the robot

NOTE: Positive to turn Left, negative to turn Right

SYNTAX:
turn(number of motor rotations, speed)

EX:

turn(-5, 127)

Turns the robot to the right 5 rotations at top speed.


------------------------
Function stop.
------------------------

stops robot quickly. No params


------------------------
Function glide.
------------------------

slows robot to a halt. no params


------------------------
Function RC.
------------------------

changes control to RC, returns to Main() after press of Btn7U.



-----------------------
Function armMove
-----------------------

Controls the arm

SYNTAX:
armMove(number of rotations);

EX:
armMove(27);

moves arm up. motor does 27 rotations



-----------------------
Function clawOpen
-----------------------

opens the claw. no params



-----------------------
Function clawClose
-----------------------

closes the claw. no params

















*/
