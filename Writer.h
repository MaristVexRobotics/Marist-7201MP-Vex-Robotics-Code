void writeStream() {


  //----------------------
  if (leftBackDrivePower < -127 + DEADZONE)
    leftBackDrivePower = -127 + DEADZONE;
  else if (leftBackDrivePower > 127 - DEADZONE)
    leftBackDrivePower = 127 - DEADZONE;

  if (rightBackDrivePower < -127 + DEADZONE)
    rightBackDrivePower = -127 + DEADZONE;
  else if (rightBackDrivePower > 127 - DEADZONE)
    rightBackDrivePower = 127 - DEADZONE;

  if (leftFrontDrivePower < -127 + DEADZONE)
    leftFrontDrivePower = -127 + DEADZONE;
  else if (leftFrontDrivePower > 127 - DEADZONE)
    leftFrontDrivePower = 127 - DEADZONE;

  if (rightFrontDrivePower < -127 + DEADZONE)
    rightFrontDrivePower = -127 + DEADZONE;
  else if (rightFrontDrivePower > 127 - DEADZONE)
    rightFrontDrivePower = 127 - DEADZONE;

  if (armPower < -127 + DEADZONE)
    armPower = -127 + DEADZONE;
  else if (armPower > 127 - DEADZONE)
    armPower = 127 - DEADZONE;
  //----------------------


  // if there is something happening, write autonomous code
  if (abs(leftBackDrivePower)  > 10 || abs(rightBackDrivePower)  > 10
   || abs(leftFrontDrivePower) > 10 || abs(rightFrontDrivePower) > 10
   || abs(armPower) > 10 || abs(beltPower) > 10
   || abs(leftFrontEncoder) > 10 || abs(rightFrontEncoder) > 10
   || abs(leftBackEncoder)  > 10 || abs(rightBackEncoder)  > 10
   /*|| abs(leftArmDegrees)   > 10 || abs(rightArmDegrees)   > 10*/) {

    writeDebugStream("Auton(%d, ", (leftFrontDrivePower));
    writeDebugStream("%d, ", (leftBackDrivePower));
    writeDebugStream("%d, ", (rightFrontDrivePower));
    writeDebugStream("%d, ", (rightBackDrivePower));
    writeDebugStream("%d, ", (armPower));
    writeDebugStream("%d, ", (beltPower));
    writeDebugStream("%d, ", (leftFrontEncoder));
    writeDebugStream("%d, ", (leftBackEncoder));
    writeDebugStream("%d, ", (rightFrontEncoder));
    writeDebugStream("%d, ", (rightBackEncoder));
    writeDebugStream("%d, ", (leftArmDegrees));
    writeDebugStreamLine("%d);", (rightArmDegrees));
    writeDebugStreamLine("RunRobot();");
    writeDebugStreamLine("wait10Msec(%d);", (AUTO_TIME_INTERVAL));

  }
  wait10Msec(AUTO_TIME_INTERVAL);
}
