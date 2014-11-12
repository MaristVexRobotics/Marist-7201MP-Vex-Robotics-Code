void RC(){

	//TODO, add code to maintain scissor hight

	//Drivetrain
	rcDriveForward = vexRT[Ch3]; //left  thumbstick up   down
	rcDriveStrafe  = vexRT[Ch4]; //left  thumbstick left right
	rcDriveTurn		 = vexRT[Ch1]; //right thumbstick left right

	//Scissor Lift
	scissorPower	 = vexRT[Ch2Xmtr2]; //right thumbstick up down on second controller
	if (scissorPower >= 0 && scissorPower < MAINTAIN_HEIGHT_SCISSOR_POWER)
		scissorPower = MAINTAIN_HEIGHT_SCISSOR_POWER;


	//Front Claw
	if (vexRT[Btn6UXmtr2]) {
		beltPower = 127;
	}
	if (vexRT[Btn6DXmtr2]) {
		beltPower = -127;
	}
	if (vexRT[Btn6DXmtr2] == vexRT[Btn6UXmtr2]) { //if they are both not pushed, or both pushed, dont move the claw
		beltPower = 0;
	}

	if (vexRT[Btn8UXmtr2] != vexRT[Btn8DXmtr2]) {
		if (vexRT[Btn8UXmtr2])
			beltNextPos = beltCurrentPos + 1;
		if (vexRT[Btn8DXmtr2])
			beltNextPos = beltCurrentPos - 1;
		if (beltNextPos == 0)
			beltNextPos = 4;
		else if (beltNextPos == 5)
			beltNextPos = 1;
	}
}
