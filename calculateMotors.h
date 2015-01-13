
void calcMotorValues() {


	int actualFWD = rcDriveForward * cosDegrees(gyroValue) + rcDriveStrafe * cosDegrees(90 + gyroValue);
	int actualLFT = rcDriveForward * sinDegrees(gyroValue) + rcDriveStrafe * sinDegrees(90 + gyroValue);

	if (abs(actualLFT) <= DEADZONE)
		actualLFT = 0;


	/*
	Fwd = Positive
	Right = Positive
	*/

	leftFrontDrivePower  = actualFWD + actualLFT + rcDriveTurn;
	leftBackDrivePower   = actualFWD - actualLFT + rcDriveTurn;
	rightFrontDrivePower = actualFWD - actualLFT - rcDriveTurn;
	rightBackDrivePower  = actualFWD + actualLFT - rcDriveTurn;

	//update current belt pos
	/*if      (beltSensorVal + 5 >= BELT_POS1 && beltSensorVal - 5 <= BELT_POS1)
		beltCurrentPos = 1;
  else if (beltSensorVal + 5 >= BELT_POS2 && beltSensorVal - 5 <= BELT_POS2)
		beltCurrentPos = 2;
	else if (beltSensorVal + 5 >= BELT_POS3 && beltSensorVal - 5 <= BELT_POS3)
		beltCurrentPos = 3;
	else if (beltSensorVal + 5 >= BELT_POS4 && beltSensorVal - 5 <= BELT_POS4)
		beltCurrentPos = 4;
	else if (beltSensorVal + 5 >= BELT_POS5 && beltSensorVal - 5 <= BELT_POS5)
		beltCurrentPos = 5;

	if (beltNextPos > beltCurrentPos)
		beltPower = 127;
	else if (beltNextPos < beltCurrentPos)
		beltPower = 127;
	else
		beltPower = 0;*/
}
