void Auton(int leftFrontWheel, int leftBackWheel, int rightFrontWheel, int rightBackWheel,
           int armSpeed, int beltSpeed,
           int leftFrontEncoderGoal, int leftBackEncoderGoal, int rightFrontEncoderGoal, int rightBackEncoderGoal,
           int leftPotentiometerGoal, int rightPotentiometerGoal) {


	// guarantee that the loop doesn't run if no motors with encoders are running.
	int wait = 0;
	while (((leftFrontEncoderGoal - leftFrontEncoder >= 0 && leftFrontDrivePower > 0)
		   || (leftFrontEncoderGoal - leftFrontEncoder <= 0 && leftFrontDrivePower < 0)
		   || (leftFrontDrivePower == 0)) // if not moving

       && ((leftBackEncoderGoal - leftBackEncoder >= 0 && leftBackDrivePower > 0 )
		   ||  (leftBackEncoderGoal - leftBackEncoder <= 0 && leftBackDrivePower < 0 )
		   ||  (leftBackDrivePower == 0))

		   && ((rightFrontEncoderGoal - rightFrontEncoder >= 0 && rightFrontDrivePower > 0 )
		   ||  (rightFrontEncoderGoal - rightFrontEncoder <= 0 && rightFrontDrivePower < 0 )
		   ||  (rightFrontDrivePower == 0))

		   && ((rightBackEncoderGoal - rightBackEncoder >= 0 && rightBackDrivePower > 0 )
		   ||  (rightBackEncoderGoal - rightBackEncoder <= 0 && rightBackDrivePower < 0 )
		   ||  (rightBackDrivePower == 0))

		   && ((leftPotentiometerGoal-leftArmDegrees > 0 && armPower > 0)
		   ||  (leftPotentiometerGoal-leftArmDegrees > 0 && armPower > 0)
		   ||  (armPower == 0))

		   && ((rightPotentiometerGoal-rightArmDegrees > 0 && armPower > 0)
		   ||  (rightPotentiometerGoal-rightArmDegrees > 0 && armPower > 0)
		   ||  (armPower == 0))

		   && (abs(leftFrontDrivePower)  > 10 || abs(leftBackDrivePower)  > 10
		   ||  abs(rightFrontDrivePower) > 10 || abs(rightBackDrivePower) > 10
		   ||  armPower != 0 || beltPower != 0)

		   //or while you haven't waited longer than the max wait time
       && !wait > MAX_WAIT_TIME) { //END WHILE CONDITION

		RunRobot(); // update variables
		wait++; // increase the wait tick
	}
	if (MAX_WAIT_TIME <= wait) // if loop was ended by waiting
		writeDebugStreamLine("I gave up"); // notify via debug stream

	//applies values to motors
	leftFrontDrivePower  = leftFrontWheel;
	leftBackDrivePower   = leftBackWheel;
	rightFrontDrivePower = rightFrontWheel;
	rightBackDrivePower  = rightBackWheel;
	armPower  = armSpeed;
	beltPower = beltSpeed;

	//This section makes minor modifications to motor speeds if they overshot or undershot their goal.
	int diff = leftFrontEncoderGoal - leftFrontEncoder;
	leftFrontDrivePower += diff * CORRECTION;

	diff = leftBackEncoderGoal - leftBackEncoder;
	leftBackDrivePower += diff * CORRECTION;

	diff = rightFrontEncoderGoal - rightFrontEncoder;
	rightFrontDrivePower += diff * CORRECTION;

	diff = rightBackEncoderGoal - rightBackEncoder;
	rightBackDrivePower += diff * CORRECTION;

	diff = leftPotentiometerGoal - leftArmDegrees;
	armPower += diff * CORRECTION;

	//NOTE: right arm not necessary because that correction is done in Robot.h
}


void moveForward(int ticks, int speed) {
	resetSensors();
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
	resetSensors();
	leftBackDrivePower   = -speed;
	rightBackDrivePower  = -speed;
	leftFrontDrivePower  = -speed;
	rightFrontDrivePower = -speed;
	RunRobot();
	while (leftFrontEncoder  > -ticks
			&& rightFrontEncoder > -ticks
			&& leftBackEncoder   > -ticks
			&& rightBackEncoder  > -ticks) { // until a motor has reached the distance

			//reset motor speeds
		leftBackDrivePower   = -speed;
		rightBackDrivePower  = -speed;
		leftFrontDrivePower  = -speed;
		rightFrontDrivePower = -speed;

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
	resetSensors();
	leftBackDrivePower   =  speed;
	rightBackDrivePower  = -speed;
	leftFrontDrivePower  = -speed;
	rightFrontDrivePower =  speed;
	RunRobot();
	while (leftFrontEncoder  > -ticks
			&& rightFrontEncoder <  ticks
			&& leftBackEncoder   <  ticks
			&& rightBackEncoder  > -ticks) { // until a motor has reached the distance

			//reset motor speeds
		leftBackDrivePower   =  speed;
		rightBackDrivePower  = -speed;
		leftFrontDrivePower  = -speed;
		rightFrontDrivePower =  speed;

		//calculate average encoder distance
		int averageEncoder  = (rightFrontEncoder - leftFrontEncoder + leftBackEncoder - rightBackEncoder) / 4;

		//check and adjust based on encoder values.
		leftBackDrivePower   += (averageEncoder - leftBackEncoder)   * CORRECTION;
		rightBackDrivePower  -= (averageEncoder + rightBackEncoder)  * CORRECTION;
		leftFrontDrivePower  -= (averageEncoder + leftFrontEncoder)  * CORRECTION;
		rightFrontDrivePower += (averageEncoder - rightFrontEncoder) * CORRECTION;

		RunRobot();
	}
}
void moveRight(int ticks, int speed) {///errere
	resetSensors();
	leftBackDrivePower   = -speed;
	rightBackDrivePower  =  speed;
	leftFrontDrivePower  =  speed;
	rightFrontDrivePower = -speed;
	RunRobot();
	while (leftFrontEncoder  <  ticks
			&& rightFrontEncoder > -ticks
			&& leftBackEncoder   > -ticks
			&& rightBackEncoder  <  ticks) { // until a motor has reached the distance

			//reset motor speeds
		leftBackDrivePower   = -speed;
		rightBackDrivePower  =  speed;
		leftFrontDrivePower  =  speed;
		rightFrontDrivePower = -speed;

		//calculate average encoder distance
		int averageEncoder  = (leftFrontEncoder - rightFrontEncoder - leftBackEncoder + rightBackEncoder) / 4;

		//check and adjust based on encoder values.
		leftBackDrivePower   -= (averageEncoder + leftBackEncoder)   * CORRECTION;
		rightBackDrivePower  += (averageEncoder - rightBackEncoder)  * CORRECTION;
		leftFrontDrivePower  += (averageEncoder - leftFrontEncoder)  * CORRECTION;
		rightFrontDrivePower -= (averageEncoder + rightFrontEncoder) * CORRECTION;

		RunRobot();
	}
}

void drivetrainStop() {
	leftBackDrivePower   = 0;
	rightBackDrivePower  = 0;
	leftFrontDrivePower  = 0;
	rightFrontDrivePower = 0;
	RunRobot();
}


void turnLeft(int degrees, int speed) {//error (remember loop back)
	resetSensors();
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

void turnRight(int degrees, int speed) { // look at that
	resetSensors();
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

void setScissorHeight(int height, int speed) {
	if (height > leftArmDegrees) {
		armPower = speed;
		while(height > leftArmDegrees); // wait until the scissor lift has reached the height
		armPower = MAINTAIN_HEIGHT_ARM_POWER;
	} else {
		armPower = -speed;
		while(height < leftArmDegrees); // wait until the scissor lift has reached the height
		armPower = MAINTAIN_HEIGHT_ARM_POWER;
	}
}

void beltFwd(int mSeconds) {
	beltPower = 127;
	wait1Msec(mSeconds);
	beltPower = 0;
}

void beltBkwd(int mSeconds) {
	beltPower = -127;
	wait1Msec(mSeconds);
	beltPower = 0;
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

void move180(int power); // moves backwards while performing a 180 degree turn, so it ends up facing where it's going.
