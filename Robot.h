void RunRobot(){
  //read sensor values and put them into the variables
  leftFrontEncoder  = nMotorEncoder[leftFront];
  rightFrontEncoder = nMotorEncoder[rightFront];
  leftBackEncoder   = nMotorEncoder[leftBack];
  rightBackEncoder  = nMotorEncoder[rightBack];

  leftArmDegrees  = SensorValue[leftScissorRot] - POTENTIOMETER_DIFF;
  rightArmDegrees = SensorValue[rightScissorRot];
  beltSensorVal   = nMotorEncoder[rightBelt];

  if (gyroOverride)//3.0.1
    gyroValue = 0;
  else
    gyroValue = SensorValue[gyro]/10;

  motor[leftFront]  = leftFrontDrivePower * EFL;
  motor[leftBack]   = leftBackDrivePower * EBL;
  motor[rightFront] = rightFrontDrivePower * EFR;
  motor[rightBack]  = rightBackDrivePower * EBR;


  motor[leftScissor1]  = armPower;
  motor[leftScissor2]  = armPower;
  motor[rightScissor1] = armPower;
  motor[rightScissor2] = armPower;

  armDiff = rightArmDegrees - leftArmDegrees;
  int diff = armDiff * CORRECTION;
  diff = 0;
  if (armPower > 0) {
    if (leftArmDegrees > rightArmDegrees) {
      motor[leftScissor1] += diff;
      motor[leftScissor2] += diff;
    } else /*if (leftArmDegrees < rightArmDegrees)*/ {
      motor[rightScissor1] -= diff;
      motor[rightScissor2] -= diff;
    }
  } else /*if (scissorPower < 0)*/ {
    if (leftArmDegrees > rightArmDegrees) {
      motor[rightScissor1] -= diff;
      motor[rightScissor2] -= diff;
    } else /*if (leftArmDegrees < rightArmDegrees)*/ {
      motor[leftScissor1] += diff;
      motor[leftScissor2] += diff;
    }
  }



  motor[leftBelt] = beltPower;
  motor[rightBelt] = beltPower;

}

void resetSensors() {
  nMotorEncoder[leftFront]  = 0;
  nMotorEncoder[rightFront] = 0;
  nMotorEncoder[leftFront]  = 0;
  nMotorEncoder[rightFront] = 0;
  nMotorEncoder[leftBack]   = 0;
  nMotorEncoder[rightBack]  = 0;
  nMotorEncoder[rightBelt]  = 0;
  SensorValue[rightScissorRot] = 0;
  SensorValue[leftScissorRot]  = 0;
}
