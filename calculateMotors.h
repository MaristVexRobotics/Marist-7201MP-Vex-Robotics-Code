
void calcMotorValues() {


  int actualFWD = rcDriveForward * cosDegrees(gyroValue) + rcDriveStrafe * cosDegrees(90 + gyroValue);
  int actualLFT = rcDriveForward * sinDegrees(gyroValue) + rcDriveStrafe * sinDegrees(90 + gyroValue);

  if (abs(actualLFT) <= STRAFE_DEADZONE)
    actualLFT = 0;


  /*
  Fwd = Positive
  Right = Positive
  */

  leftFrontDrivePower  = actualFWD + actualLFT + rcDriveTurn;
  leftBackDrivePower   = actualFWD - actualLFT + rcDriveTurn;
  rightFrontDrivePower = actualFWD - actualLFT - rcDriveTurn;
  rightBackDrivePower  = actualFWD + actualLFT - rcDriveTurn;



  if (armPower != 0) { // 3.1.1
    armMaintainHeight = leftArmDegrees;
  }

  if (armPower == 0) {
    int proportional = armMaintainHeight - leftArmDegrees;
    int derivative = proportional - armError;
    integral = integral + proportional;
    if (integral > 1000)
  	  integral = 1000;
 	  else if (integral < -1000)
 		  integral = -1000;
 		if (!correctionOverride)
    	armPower = KpA * proportional + KdA * derivative + KiA * integral;
    armError = proportional;
    //armPower = MAINTAIN_HEIGHT_ARM_POWER + (armMaintainHeight - leftArmDegrees);*/
  }


  if (beltPower != 0) // 3.1.1
    beltMaintainValue = beltSensorVal;
  else
    beltPower = MAINTAIN_HEIGHT_BELT_POWER + (beltMaintainValue - beltSensorVal);
}
