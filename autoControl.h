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


void moveForward(int ticks, int speed) {
	resetEncoders();
	leftBackDrivePower   = speed;
	rightBackDrivePower  = speed;
	leftFrontDrivePower  = speed;
	rightFrontDrivePower = speed;
	RunRobot();
	while (leftFrontEncoder  < ticks
			&& rightFrontEncoder < ticks
			&& leftBackEncoder   < ticks
			&& rightBackEncoder  < ticks) { // until a motor has reached the distance

			//reset motor speeds
		leftBackDrivePower   = speed;
		rightBackDrivePower  = speed;
		leftFrontDrivePower  = speed;
		rightFrontDrivePower = speed;

		//calculate average encoder distance
		int averageEncoder  = (leftFrontEncoder + rightFrontEncoder + leftBackEncoder + rightBackEncoder) / 4;

		//check and adjust based on encoder values.
		leftBackDrivePower   += (averageEncoder - leftBackEncoder)   * CORRECTION;
		rightBackDrivePower  += (averageEncoder - rightBackEncoder)  * CORRECTION;
		leftFrontDrivePower  += (averageEncoder - leftFrontEncoder)  * CORRECTION;
		rightFrontDrivePower += (averageEncoder - rightFrontEncoder) * CORRECTION;

		RunRobot();
	}
}

void moveBackward(int ticks, int speed) {
	resetEncoders();
	leftBackDrivePower   = -speed;
	rightBackDrivePower  = -speed;
	leftFrontDrivePower  = -speed;
	rightFrontDrivePower = -speed;
	RunRobot();
	while (leftFrontEncoder  > ticks
			&& rightFrontEncoder > ticks
			&& leftBackEncoder   > ticks
			&& rightBackEncoder  > ticks) { // until a motor has reached the distance

			//reset motor speeds
		leftBackDrivePower   = speed;
		rightBackDrivePower  = speed;
		leftFrontDrivePower  = speed;
		rightFrontDrivePower = speed;

		//calculate average encoder distance
		int averageEncoder  = (leftFrontEncoder + rightFrontEncoder + leftBackEncoder + rightBackEncoder) / 4;

		//check and adjust based on encoder values.
		leftBackDrivePower   += (averageEncoder - leftBackEncoder)   * CORRECTION;
		rightBackDrivePower  += (averageEncoder - rightBackEncoder)  * CORRECTION;
		leftFrontDrivePower  += (averageEncoder - leftFrontEncoder)  * CORRECTION;
		rightFrontDrivePower += (averageEncoder - rightFrontEncoder) * CORRECTION;

		RunRobot();
	}
}
void moveLeft(int ticks, int speed) {
	resetEncoders();
	leftBackDrivePower   = speed;
	rightBackDrivePower  = -speed;
	leftFrontDrivePower  = -speed;
	rightFrontDrivePower = speed;
	RunRobot();
	while (leftFrontEncoder  > -ticks
			&& rightFrontEncoder > ticks
			&& leftBackEncoder   > ticks
			&& rightBackEncoder  > -ticks) { // until a motor has reached the distance

			//reset motor speeds
		leftBackDrivePower   = speed;
		rightBackDrivePower  = -speed;
		leftFrontDrivePower  = -speed;
		rightFrontDrivePower = speed;

		//calculate average encoder distance
		int averageEncoder  = (rightFrontEncoder - leftFrontEncoder + leftBackEncoder - rightBackEncoder) / 4;

		//check and adjust based on encoder values.
		leftBackDrivePower   += (averageEncoder - leftBackEncoder)   * CORRECTION;
		rightBackDrivePower  += (averageEncoder + rightBackEncoder)  * CORRECTION;
		leftFrontDrivePower  += (averageEncoder + leftFrontEncoder)  * CORRECTION;
		rightFrontDrivePower += (averageEncoder - rightFrontEncoder) * CORRECTION;

		RunRobot();
	}
}
void moveRight(int ticks, int speed) {
	resetEncoders();
	leftBackDrivePower   = -speed;
	rightBackDrivePower  = speed;
	leftFrontDrivePower  = speed;
	rightFrontDrivePower = -speed;
	RunRobot();
	while (leftFrontEncoder  > ticks
			&& rightFrontEncoder > -ticks
			&& leftBackEncoder   > -ticks
			&& rightBackEncoder  > ticks) { // until a motor has reached the distance

			//reset motor speeds
		leftBackDrivePower   = -speed;
		rightBackDrivePower  = speed;
		leftFrontDrivePower  = speed;
		rightFrontDrivePower = -speed;

		//calculate average encoder distance
		int averageEncoder  = (leftFrontEncoder - rightFrontEncoder - leftBackEncoder + rightBackEncoder) / 4;

		//check and adjust based on encoder values.
		leftBackDrivePower   += (averageEncoder + leftBackEncoder)   * CORRECTION;
		rightBackDrivePower  += (averageEncoder - rightBackEncoder)  * CORRECTION;
		leftFrontDrivePower  += (averageEncoder - leftFrontEncoder)  * CORRECTION;
		rightFrontDrivePower += (averageEncoder + rightFrontEncoder) * CORRECTION;

		RunRobot();
	}
}

void drivetrainStop() {
	leftBackDrivePower = 0;
	rightBackDrivePower = 0;
	leftFrontDrivePower = 0;
	rightFrontDrivePower = 0;
	RunRobot();
}


void turnLeft(int degrees, int power) {
	resetEncoders();
	leftBackDrivePower   = -speed;
	rightBackDrivePower  = speed;
	leftFrontDrivePower  = -speed;
	rightFrontDrivePower = speed;
	RunRobot();
	while (-gyroValue < degrees) { // until a motor has reached the distance

			//reset motor speeds
		leftBackDrivePower   = -speed;
		rightBackDrivePower  = speed;
		leftFrontDrivePower  = -speed;
		rightFrontDrivePower = speed;

		//calculate average encoder distance
		int averageEncoder  = (-leftFrontEncoder + rightFrontEncoder - leftBackEncoder + rightBackEncoder) / 4;

		//check and adjust based on encoder values.
		leftBackDrivePower   -= (averageEncoder + leftBackEncoder)   * CORRECTION;
		rightBackDrivePower  += (averageEncoder - rightBackEncoder)  * CORRECTION;
		leftFrontDrivePower  -= (averageEncoder + leftFrontEncoder)  * CORRECTION;
		rightFrontDrivePower += (averageEncoder - rightFrontEncoder) * CORRECTION;

		RunRobot();
	}
}

void turnRight(int degrees, int power) {
	resetEncoders();
	leftBackDrivePower   = speed;
	rightBackDrivePower  = -speed;
	leftFrontDrivePower  = speed;
	rightFrontDrivePower = -speed;
	RunRobot();
	while (gyroValue < degrees) { // until a motor has reached the distance

			//reset motor speeds
		leftBackDrivePower   = speed;
		rightBackDrivePower  = -speed;
		leftFrontDrivePower  = speed;
		rightFrontDrivePower = -speed;

		//calculate average encoder distance
		int averageEncoder  = (leftFrontEncoder - rightFrontEncoder + leftBackEncoder - rightBackEncoder) / 4;

		//check and adjust based on encoder values.
		leftBackDrivePower   += (averageEncoder - leftBackEncoder)   * CORRECTION;
		rightBackDrivePower  -= (averageEncoder + rightBackEncoder)  * CORRECTION;
		leftFrontDrivePower  += (averageEncoder - leftFrontEncoder)  * CORRECTION;
		rightFrontDrivePower -= (averageEncoder + rightFrontEncoder) * CORRECTION;

		RunRobot();
	}
}

void move180(int power); // moves backwards while performing a 180 degree turn, so it ends up facing where it's going.

void setScissorHeight(int height, int speed) {
	if (height < leftScissorEncoder) {
		scissorPower = speed;
		while(height < leftScissorEncoder); // wait until the scissor lift has reached the height
		scissorPower = MAINTAIN_HEIGHT_SCISSOR_POWER;
	} else {
		scissorPower = -speed;
		while(height > leftScissorEncoder); // wait until the scissor lift has reached the height
		scissorPower = MAINTAIN_HEIGHT_SCISSIR_POWER;
	}
}

void openFrontClaw() {
	frontClawPower = 127;
	wait1Msec(800);
	frontClawPower = 0;
}

void closeFrontClaw() {
	frontClawPower = -127;
	wait1Msec(1000);
	frontClawPower = 0;
}

void openBackClaw() {
	backClawPower = 127;
	wait1Msec(800);
	backClawPower = 0;
}
void closeBackClaw() {
	backClawPower = -127;
	wait1Msec(1000);
	backClawPower = 0;
}

void snapLeftLine(int speed) {
	while (lineReadMid > LINE_SENSOR_THRESHOLD) {
		leftBackDrivePower   = speed;
		rightBackDrivePower  = -speed;
		leftFrontDrivePower  = -speed;
		rightFrontDrivePower = speed;
	}
	leftBackDrivePower   = 0;
	rightBackDrivePower  = 0;
	leftFrontDrivePower  = 0;
	rightFrontDrivePower = 0;
}
void snapRightLine(int speed) {
	while (lineReadMid > LINE_SENSOR_THRESHOLD) {
		leftBackDrivePower   = -speed;
		rightBackDrivePower  = speed;
		leftFrontDrivePower  = speed;
		rightFrontDrivePower = -speed;
	}
	leftBackDrivePower   = 0;
	rightBackDrivePower  = 0;
	leftFrontDrivePower  = 0;
	rightFrontDrivePower = 0;
}
void snapForwardLine(int speed) {
	while (lineReadMid > LINE_SENSOR_THRESHOLD) {
		leftBackDrivePower   = speed;
		rightBackDrivePower  = speed;
		leftFrontDrivePower  = speed;
		rightFrontDrivePower = speed;
	}
	leftBackDrivePower   = 0;
	rightBackDrivePower  = 0;
	leftFrontDrivePower  = 0;
	rightFrontDrivePower = 0;
}
void snapBackLine(int speed) {
	while (lineReadMid > LINE_SENSOR_THRESHOLD) {
		leftBackDrivePower   = -speed;
		rightBackDrivePower  = -speed;
		leftFrontDrivePower  = -speed;
		rightFrontDrivePower = -speed;
	}
	leftBackDrivePower   = 0;
	rightBackDrivePower  = 0;
	leftFrontDrivePower  = 0;
	rightFrontDrivePower = 0;
}

void snapFrontLeft(int speed);
void snapFrontRight(int speed);
void snapBackLeft(int speed);
void snapBackRight(int speed);

void waitBlockCompletion();
void signalBlockComplete();
