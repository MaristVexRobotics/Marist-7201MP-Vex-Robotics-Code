void RunRobot(){
	motor[frontLeftMotor] = leftDrive;
	motor[rearLeftMotor] = leftDrive;
	motor[frontRightMotor] = rightDrive;
	motor[rearRightMotor] = rightDrive;

	motor[leftArmMotor] = armVar;
	motor[rightArmMotor] = armVar;

	motor[rightClawMotor] = beltVar;
	motor[leftClawMotor] = beltVar;

	leftEncoderVar = SensorValue[leftEncoder];
	rightEncoderVar = SensorValue[rightEncoder];
	leftArmEncoderVar = 0;
	rightArmEncoderVar = 0;
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
  SensorValue[leftEncoder] = 0;
  SensorValue[rightEncoder] = 0;
}
