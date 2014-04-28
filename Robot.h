void RunRobot(){

	leftEncoderVar = nMotorEncoder[leftFront];
	rightEncoderVar = nMotorEncoder[rightFront];
	leftArmEncoderVar = -1 * nMotorEncoder[arm3];
	//rightArmEncoderVar = nMotorEncoder[arm2];

	/*if ((rightArmEncoderVar >= MAX_ARM_HEIGHT || leftArmEncoderVar >= MAX_ARM_HEIGHT) && armVar > 10) //addition from 2.0.5
		armVar = 10;	*/																				//addition from 2.0.5


	//2.0.7 Addition
	/*if ((rightArmEncoderVar >= ARM_UP_HEIGHT || leftArmEncoderVar >= ARM_UP_HEIGHT) && leftDrive-leftDriveOld < ACCEL_LIMIT)
		leftDrive = leftDriveOld - ACCEL_LIMIT;
  if ((rightArmEncoderVar >= ARM_UP_HEIGHT || leftArmEncoderVar >= ARM_UP_HEIGHT) && leftDrive-leftDriveOld > ACCEL_LIMIT)
		leftDrive = leftDriveOld + ACCEL_LIMIT;
	if ((rightArmEncoderVar >= ARM_UP_HEIGHT || leftArmEncoderVar >= ARM_UP_HEIGHT) && rightDrive-rightDriveOld < ACCEL_LIMIT)
		rightDrive = rightDriveOld - ACCEL_LIMIT;
  if ((rightArmEncoderVar >= ARM_UP_HEIGHT || leftArmEncoderVar >= ARM_UP_HEIGHT) && rightDrive-rightDriveOld > ACCEL_LIMIT)
		rightDrive = rightDriveOld + ACCEL_LIMIT;*/


	motor[leftFront] = leftDrive * EL;
	motor[leftBack] = leftDrive * EL;
	motor[rightFront] = rightDrive * ER;
	motor[rightBack] = rightDrive * ER;

	motor[arm] = armVar;
	motor[arm2] = armVar;
	motor[arm3] = armVar;
	motor[arm4] = armVar;

	motor[rightBelt] = -1 * beltVar;
	motor[leftBelt] = -1 * beltVar;

	leftDriveOld = leftDrive;
	rightDriveOld = rightDrive;
}

void resetVars() {
	leftDrive = 0;
  rightDrive = 0;
  armVar = 0;
  beltVar = 0;
  leftEncoderVar = 0;
  rightEncoderVar = 0;
  leftArmEncoderVar = 0;
  rightArmEncoderVar = 0;
  nMotorEncoder[leftFront] = 0;
  nMotorEncoder[rightFront] = 0;
  nMotorEncoder[arm3] = 0;
  nMotorEncoder[arm2] = 0;
}
