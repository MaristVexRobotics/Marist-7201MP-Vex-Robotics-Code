void RunRobot(){
	//read sensor values and put them into the variables
	leftFrontEncoder = nMotorEncoder[leftFront];
	rightFrontEncoder = nMotorEncoder[rightFront];
	leftBackEncoder = nMotorEncoder[leftBack];
	rightBackEncoder = nMotorEncoder[rightBack];

	leftScissorEncoder = nMotorEncoder[leftScissor1];
	rightScissorEncoder = nMotorEncoder[rightScissor];

	gyroValue = SensorValue[gyro]/10;

	motor[leftFront] = leftFrontDrivePower * EFL;
	motor[leftBack] = leftBackDrivePower * EBL;
	motor[rightFront] = rightFrontDrivePower * EFR;
	motor[rightBack] = rightBackDrivePower * EBR;

	motor[leftScissor1] = scissorPower;
	motor[leftScissor2] = scissorPower;
	motor[rightScissor] = scissorPower;

	motor[frontClaw] = frontClawPower;
	motor[backClaw] = backClawPower;
}

void resetEncoders() {
	nMotorEncoder[leftFront] = 0;
	nMotorEncoder[rightFront] = 0;
	nMotorEncoder[leftFront] = 0;
	nMotorEncoder[rightFront] = 0;
	nMotorEncoder[leftBack] = 0;
	nMotorEncoder[rightBack] = 0;
	nMotorEncoder[leftScissor1] = 0;
	nMotorEncoder[rightScissor] = 0;
}
