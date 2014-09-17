void RC(){

	//Drivetrain
	rcDriveForward = vexRT[Ch3]; //left  thumbstick up   down
	rcDriveStrafe  = vexRT[Ch4]; //left  thumbstick left right
	rcDriveTurn		 = vexRT[Ch1]; //right thumbstick left right

	//Scissor Lift
	scissorPower	 = vexRT[Ch2Xmtr2]; //right thumbstick up down on second controller


	//Front Claw
	if (vexRT[Btn6U]) {
		frontClawPower = 127;
	}
	if (vexRT[Btn6D]) {
		frontClawPower = -127;
	}
	if(vexRT[Btn6D] == vexRT[Btn6U]) { //if they are both not pushed, or both pushed, dont move the claw
		frontClawPower = 0;
	}


	//Rear Claw
	if (vexRT[Btn5U]) {
		backClawPower = 127;
	}
	if (vexRT[Btn5D]) {
		backClawPower = -127;
	}
	if (vexRT[Btn5U] == vexRT[Btn5D]) {
		backClawPower = 0;
	}
}
