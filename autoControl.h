void Auton(int leftWheels, int rightWheels, int armSpeed, int beltSpeed, int leftEncoderVal, int rightEncoderVal, int leftArmEncoderVal, int rightArmEncoderVal) {
	// while loop is addition of 2.0.2 - checks to see that any motor has reached it's goal. last check is to
	// guarantee that the loop doesn't run if no motors with encoders are running.
	int wait = 0;
	while (((leftEncoderVal-leftEncoderVar > 0 && leftWheels > 0) || (leftEncoderVal-leftEncoderVar < 0 && leftWheels < 0) || leftWheels == 0)
		&& ((rightEncoderVal-rightEncoderVar > 0 && rightWheels > 0 ) || (rightEncoderVal-rightEncoderVar < 0 && rightWheels < 0 ) || rightWheels == 0)
		&& (abs(leftWheels) > 10 || abs(rightWheels) > 10 || armSpeed != 0 )
		&& ((leftArmEncoderVal-leftArmEncoderVar > 0 && armSpeed > 0) || (leftArmEncoderVal-leftArmEncoderVar > 0 && armSpeed > 0) || armSpeed == 0)
		&& MAX_WAIT_TIME > wait) {
		RunRobot(); // update variables
		wait++;
	}
	if (MAX_WAIT_TIME <= wait)
		writeDebugStreamLine("I gave up");
	//applies values to motors
	leftDrive = leftWheels;
	rightDrive = rightWheels;
	armVar = armSpeed;
	beltVar = beltSpeed;

	//This section makes minor modifications to motor speeds if they overshot or undershot their goal.
	int diff = leftEncoderVal - leftEncoderVar;
	leftDrive += diff / CORRECTION;
	//writeDebugStream("Left %d", diff);

	diff = rightEncoderVal - rightEncoderVar; // bugfix 2.0.3.1 I had leftEncoderVar *SLAMS HEAD ON DESK*
	rightDrive += diff / CORRECTION;
	//writeDebugStreamLine(" Right %d", diff);

	diff = leftArmEncoderVal - leftArmEncoderVar;
	armVar += diff / CORRECTION;
}

void moveForward (int rotations, int speed) {
	nMotorEncoder[leftFront] = 0;
  nMotorEncoder[rightFront] = 0;
	while (nMotorEncoder[leftFront] < rotations) {
		mL = speed; mR = speed;
		int diff = nMotorEncoder[leftFront] - nMotorEncoder[rightFront];
		if (diff > 0 ){
			mL -= diff * 2;
		} else if (diff < 0){
			mR += diff * 2;
		}
		motor[leftFront] = mL * EL;
		motor[leftBack] = mL * EL;
		motor[rightFront] = mR * ER;
		motor[rightBack] = mR * ER;
	}
	motor[leftFront] = 0;
	motor[leftBack] = 0;
	motor[rightFront] = 0;
	motor[rightBack] = 0;
	wait10Msec(1);
}
void moveBack (int rotations, int speed) {
	nMotorEncoder[leftFront] = 0;
	nMotorEncoder[rightFront] = 0;
	while(nMotorEncoder[leftFront] > -1* rotations) {
		mL = -speed; mR = -speed;
		int diff = nMotorEncoder[leftFront] - nMotorEncoder[rightFront];
		if (diff > 0 ){
			mR += diff * 2;
		} else if (diff < 0){
			mL -= diff * 2;
		}
		motor[leftFront] = mL * EL;
		motor[leftBack] = mL * EL;
		motor[rightFront] = mR * ER;
		motor[rightBack] = mR * ER;
	}
	motor[leftFront] = 0;
	motor[leftBack] = 0;
	motor[rightFront] = 0;
	motor[rightBack] = 0;
	wait10Msec(1);
}
