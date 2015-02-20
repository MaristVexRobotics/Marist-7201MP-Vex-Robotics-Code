void RunRobot(){
  //read sensor values and put them into the variables
  leftFrontEncoder  = nMotorEncoder[leftFront];
  rightFrontEncoder = nMotorEncoder[rightFront];
  leftBackEncoder   = nMotorEncoder[leftBack];
  rightBackEncoder  = nMotorEncoder[rightBack];

  leftArmDegrees  = SensorValue[leftScissorRot] - POTENTIOMETER_DIFF;
  rightArmDegrees = SensorValue[rightScissorRot];
  beltSensorVal   = nMotorEncoder[leftBelt];

  if (gyroOverride)//3.0.1
    gyroValue = 0;
  else
    gyroValue = SensorValue[gyro]/10;

  motor[leftFront]  = leftFrontDrivePower * EFL;
  motor[leftBack]   = leftBackDrivePower * EBL;
  motor[rightFront] = rightFrontDrivePower * EFR;
  motor[rightBack]  = rightBackDrivePower * EBR;

  int diff = leftArmDegrees - rightArmDegrees;
  //diff = 0;
  int deriv = diff - armDiffOld;
  diffIntegral = diffIntegral + diff;
  armDiffOld = diff;
  int result = Kp * diff + Kd * deriv + Ki * diffIntegral;

  motor[leftScissor1]  = armPower;
  motor[leftScissor2]  = armPower;
  motor[rightScissor1] = armPower + result;
  motor[rightScissor2] = armPower + result;

  motor[leftBelt] = beltPower;
  motor[rightBelt] = beltPower;
  //motor[skyrise] = skyrisePower;

}

void resetSensors() {
  nMotorEncoder[leftFront]  = 0;
  nMotorEncoder[rightFront] = 0;
  nMotorEncoder[leftFront]  = 0;
  nMotorEncoder[rightFront] = 0;
  nMotorEncoder[leftBack]   = 0;
  nMotorEncoder[rightBack]  = 0;
  nMotorEncoder[leftBelt]  = 0;
  armMaintainHeight = SensorValue[leftScissorRot];
}
