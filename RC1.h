void RC1(){
	int mL, mR;
	mL = vexRT[Ch3];
	mR = vexRT[Ch3];
	mL = mL + .5*vexRT[Ch4];
	mR = mR - .5*vexRT[Ch4];
	if(mL > 127){
		mL = 127;
		} else if(mL < -127){
		mL = -127;
	}
	if(mR > 127){
		mR = 127;
		} else if(mR < -127){
		mR = -127;
	}
	motor[leftFront] = mL * EL;
	motor[leftBack] = mL * EL;
	motor[rightFront] = mR * ER;
	motor[rightBack] = mR * ER;
	//motor[left] =

	if(vexRT[Ch2] >= 10 || vexRT[Ch2] <= -10)
		motor[arm2] = vexRT[Ch2];
	else
		motor[arm2] = 10;
	//int diffA = nMotorEncoder[arm2] - nMotorEncoder[arm3];
	motor[arm3] = motor[arm2];// + diffA * 2;
	motor[arm] = motor[arm2];
	motor[arm4] = motor[arm3];

	if(vexRT[Btn5U] || vexRT[Btn6U]) {
		motor[rightBelt] = 127;
		motor[leftBelt] = 127;
	}
	if(vexRT[Btn6D] || vexRT[Btn5D]) {
		motor[rightBelt] = -127;
		motor[leftBelt] = -127;
	}
	if(!vexRT[Btn5U] && !vexRT[Btn5D] && !vexRT[Btn6D] && !vexRT[Btn6U]) {
		motor[leftBelt] = 0;
		motor[rightBelt] = 0;
	}

	if(vexRT[Btn7U] == 1){
		//active = false;
	}
}
