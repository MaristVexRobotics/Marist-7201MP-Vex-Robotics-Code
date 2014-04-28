void writeStream() {

	//change for 2.0.3
	//----------------------
	if (rightDrive < -127 + DEADZONE)
		rightDrive = -127 + DEADZONE;
	else if (rightDrive > 127 - DEADZONE)
		rightDrive = 127 - DEADZONE;
	if (leftDrive < -127 + DEADZONE)
		leftDrive = -127 + DEADZONE;
	else if (leftDrive > 127 - DEADZONE)
		leftDrive = 127 - DEADZONE;
	if (armVar < -127 + DEADZONE)
		armVar = -127 + DEADZONE;
	else if (armVar > 127 - DEADZONE)
		armVar = 127 - DEADZONE;
	//----------------------


	// if there is something happening, write autonomous code
	if (abs(leftDrive) > 10 || abs(rightDrive) > 10 || abs(armVar) > 10 || abs(beltVar) > 10 ||
		abs(leftEncoderVar) > 10 || abs(rightEncoderVar) > 10 || abs(leftArmEncoderVar) > 10 || abs(rightArmEncoderVar) > 10) {

		writeDebugStream("Auton(%d, ", (leftDrive));
		writeDebugStream("%d, ", (rightDrive));
		writeDebugStream("%d, ", (armVar));
		writeDebugStream("%d, ", (beltVar));
		writeDebugStream("%d, ", (leftEncoderVar));
		writeDebugStream("%d, ", (rightEncoderVar));
		writeDebugStream("%d, ", (leftArmEncoderVar));
		writeDebugStreamLine("%d);", (rightArmEncoderVar));
		writeDebugStreamLine("RunRobot();");
		writeDebugStreamLine("wait10Msec(%d);", (AUTOTIMEINTERVAL));
	}
	wait10Msec(AUTOTIMEINTERVAL);
		// output = "Auton(127, 127, 0, 0 , 255, 255, 0, 0);
	//					 RunRobot();
	//					 wait10Msec(1);					"
}
