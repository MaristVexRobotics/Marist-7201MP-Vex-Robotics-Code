void RunRobot(){
  //read sensor values and put them into the variables
  leftFrontEncoder  = nMotorEncoder[leftFront];
  rightFrontEncoder = nMotorEncoder[rightFront];
  leftBackEncoder   = nMotorEncoder[leftBack];
  rightBackEncoder  = nMotorEncoder[rightBack];

  leftArmDegrees  = SensorValue[leftScissorRot];
  rightArmDegrees = SensorValue[rightScissorRot] + POTENTIOMETER_DIFF;
  beltSensorVal   = nMotorEncoder[leftBelt];

  if(leftArmDegrees < 500 || rightArmDegrees < 500)
  	correctionOverride = true;

  /*SensorValue[leftSolenoid] = pneumaticsActivated;
  SensorValue[rightSolenoid] = pneumaticsActivated;*/

  if (gyroOverride)//3.0.1
    gyroValue = 0;
  else
    gyroValue = -SensorValue[gyro]/10;

  motor[leftFront]  = leftFrontDrivePower * EFL;
  motor[leftBack]   = leftBackDrivePower * EBL;
  motor[rightFront] = rightFrontDrivePower * EFR;
  motor[rightBack]  = rightBackDrivePower * EBR;

  long diff = leftArmDegrees - rightArmDegrees;

  /*if (abs(diff) < 100)
  	correctionOverride = true;*/

  int deriv = diff - armDiffOld;
  diffIntegral = diffIntegral + diff;
  if (diffIntegral > 10000)
  	diffIntegral = 10000;
 	else if (diffIntegral < -10000)
 		diffIntegral = -10000;
  armDiffOld = diff;
  /*int */result = Kp * diff + Kd * deriv + Ki * diffIntegral;
  if (correctionOverride || dualThumbstick)
  	result = 0;
	if (dualThumbstick) {
		motor[leftScissor1]  = EAL * leftArmPower;
  	motor[leftScissor2]  = EAL * leftArmPower;
  	motor[rightScissor1] = EAR * rightArmPower;
  	motor[rightScissor2] = EAR * rightArmPower;
	} else {
  	motor[leftScissor1]  = EAL * (armPower/* - result/**/);
  	motor[leftScissor2]  = EAL * (armPower/* - result/**/);
  	motor[rightScissor1] = EAR * (armPower + result/**/);
  	motor[rightScissor2] = EAR * (armPower + result/**/);
	}

  //leftArmPower = motor[leftScissor1];
  //rightArmPower = motor[rightScissor1];

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
  SensorValue[gyro] = 0;
  armMaintainHeight = SensorValue[leftScissorRot];
}

void GyroCalibration() {
	bool gyroWorking = true;
	int gyroOld = SensorValue[gyro];
	for (int i = 0; i < 20; i++) {
		if (SensorValue[gyro] - 5 > gyroOld) //changing rapidly
			gyroWorking = false;
		wait10Msec(5);
	}
	if (!gyroWorking) {
		//pos = -1;
		clearLCDLine(0);
 		clearLCDLine(1);
	  displayLCDPos(0, 0);
	  displayNextLCDString("PLEASE DEAR GOD");
	  displayLCDPos(1, 0);
	  displayNextLCDString("FIX ME!!!   OK");
	  while (nLCDButtons != 4);
	}
}
