
void calcMotorValues() {

	int actualFWD = rcDriveForward * cosDegrees(-gyroValue);
	int actualLFT = rcDriveStrafe * sinDegrees(-gyroValue);

	leftFrontDrivePower = actualFWD + actualLFT + rcDriveTurn;
	leftBackDrivePower = actualFWD - actualLFT + rcDriveTurn;
	rightFrontDrivePower = actualFWD - actualLFT + rcDriveTurn;
	rightBackDrivePower = actualFWD + actualLFT + rcDriveTurn;
}
