
void calcMotorValues() {


	int actualFWD = rcDriveForward * cosDegrees(gyroValue) + rcDriveStrafe * cosDegrees(90 + gyroValue);
	int actualLFT = rcDriveForward * sinDegrees(gyroValue) + rcDriveStrafe * sinDegrees(90 + gyroValue);


	/*
	int actualFWD = rcDriveForward;
	int actualLFT = rcDriveStrafe;
	*/


	/*
	Fwd = Positive
	Right = Positive
	*/

	leftFrontDrivePower = actualFWD - actualLFT + rcDriveTurn;
	leftBackDrivePower = actualFWD + actualLFT + rcDriveTurn;
	rightFrontDrivePower = actualFWD + actualLFT - rcDriveTurn;
	rightBackDrivePower = actualFWD - actualLFT - rcDriveTurn;


	//@TODO: belt thingy, jump to spots.

}
