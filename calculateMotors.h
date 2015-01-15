
void calcMotorValues() {


  int actualFWD = rcDriveForward * cosDegrees(gyroValue) + rcDriveStrafe * cosDegrees(90 + gyroValue);
  int actualLFT = rcDriveForward * sinDegrees(gyroValue) + rcDriveStrafe * sinDegrees(90 + gyroValue);

  if (abs(actualLFT) <= DEADZONE)
    actualLFT = 0;


  /*
  Fwd = Positive
  Right = Positive
  */

  leftFrontDrivePower  = actualFWD + actualLFT + rcDriveTurn;
  leftBackDrivePower   = actualFWD - actualLFT + rcDriveTurn;
  rightFrontDrivePower = actualFWD - actualLFT - rcDriveTurn;
  rightBackDrivePower  = actualFWD + actualLFT - rcDriveTurn;

  if (armPower >= 0 && armPower < MAINTAIN_HEIGHT_ARM_POWER)
    armPower = MAINTAIN_HEIGHT_ARM_POWER - deltaArm; //3.0.3

  if (beltPower == 0)
  	beltPower = MAINTAIN_HEIGHT_BELT_POWER - deltaBelt; //3.0.3
}
