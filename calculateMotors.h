
void calcMotorValues() {

	int actualFWD = rcDriveForward * cosDegrees(gyroValue) + rcDriveStrafe * cosDegrees(90 - gyroValue);
	int actualLFT = rcDriveForward  * sinDegrees(gyroValue) + rcDriveStrafe  * sinDegrees(90 - gyroValue);


	/*
	RobotY = AbsoluteY * cos(-angle) + AbsoluteX * cos(90 + angle);
	RobotX = AbsoluteY * sin(-angle) + AbsoluteX * sin(90 + angle);
	*/

	leftFrontDrivePower = actualFWD + actualLFT + rcDriveTurn;
	leftBackDrivePower = actualFWD - actualLFT + rcDriveTurn;
	rightFrontDrivePower = actualFWD - actualLFT - rcDriveTurn;
	rightBackDrivePower = actualFWD + actualLFT - rcDriveTurn;
}
