//void moveForward (int rotations, int speed)
//void moveBack (int rotations, int speed)
//void Stop()
//void turnLeft (int rotations, int speed)
//void turnRight (int rotations, int speed)

int mL = 0;
int mR = 0;
void moveForward (int rotations, int speed) {
	nMotorEncoder[leftFront] = 0;
  nMotorEncoder[rightFront] = 0;
  while (nMotorEncoder[leftFront] < rotations - 50) {
		mL = speed; mR = speed;
		int diff = nMotorEncoder[leftFront] - nMotorEncoder[rightFront];
		if (diff > 0 ){
			mL -= diff * 2;
		} else if (diff < 0){
			mR += diff * 2;
		}
		motor[leftFront] = mL * EL;
		motor[leftBack] = mL * EL;
		motor[rightFront] = mR * ER;
		motor[rightBack] = mR * ER;
	}
	while (nMotorEncoder[leftFront] < rotations) {
		mL = 30; mR = 30;
		int diff = nMotorEncoder[leftFront] - nMotorEncoder[rightFront];
		if (diff > 0 ){
			mL -= diff * 2;
		} else if (diff < 0){
			mR += diff * 2;
		}
		motor[leftFront] = mL * EL;
		motor[leftBack] = mL * EL;
		motor[rightFront] = mR * ER;
		motor[rightBack] = mR * ER;
	}
	motor[leftFront] = 0;
	motor[leftBack] = 0;
	motor[rightFront] = 0;
	motor[rightBack] = 0;
	wait10Msec(1);
}
void moveForwardY (int rotations, int speed) {
	nMotorEncoder[leftFront] = 0;
  nMotorEncoder[rightFront] = 0;
  while (nMotorEncoder[leftFront] < rotations) {
		mL = speed; mR = speed;
		int diff = nMotorEncoder[leftFront] - nMotorEncoder[rightFront];
		if (diff > 0 ){
			mL -= diff * 2;
		} else if (diff < 0){
			mR += diff * 2;
		}
		motor[leftFront] = mL * EL;
		motor[leftBack] = mL * EL;
		motor[rightFront] = mR * ER;
		motor[rightBack] = mR * ER;
	}
	motor[leftFront] = 0;
	motor[leftBack] = 0;
	motor[rightFront] = 0;
	motor[rightBack] = 0;
	wait10Msec(1);
}
void moveBack (int rotations, int speed) {
	nMotorEncoder[leftFront] = 0;
	nMotorEncoder[rightFront] = 0;
	while(nMotorEncoder[leftFront] > -1* (rotations - 50)) {
		mL = -speed; mR = -speed;
		int diff = nMotorEncoder[leftFront] - nMotorEncoder[rightFront];
		if (diff > 0 ){
			mR += diff * 2;
		} else if (diff < 0){
			mL -= diff * 2;
		}
		motor[leftFront] = mL * EL;
		motor[leftBack] = mL * EL;
		motor[rightFront] = mR * ER;
		motor[rightBack] = mR * ER;
	}
	while(nMotorEncoder[leftFront] > -1* rotations) {
		mL = -30; mR = -30;
		int diff = nMotorEncoder[leftFront] - nMotorEncoder[rightFront];
		if (diff > 0 ){
			mR += diff * 2;
		} else if (diff < 0){
			mL -= diff * 2;
		}
		motor[leftFront] = mL * EL;
		motor[leftBack] = mL * EL;
		motor[rightFront] = mR * ER;
		motor[rightBack] = mR * ER;
	}
	motor[leftFront] = 0;
	motor[leftBack] = 0;
	motor[rightFront] = 0;
	motor[rightBack] = 0;
	wait10Msec(1);
}
void turnLeft (int rotations, int speed) {
	nMotorEncoder[leftFront] = 0;
	nMotorEncoder[rightFront] = 0;
	while(nMotorEncoder[leftFront] > -1* (rotations - 50)) {
		mL = -speed; mR = speed;
		int diff = nMotorEncoder[leftFront] + nMotorEncoder[rightFront];
		if (diff > 0 ){
			mR -= diff * 2;
		} else if (diff < 0){
			mL -= diff * 2;
		}
		motor[leftFront] = mL * EL;
		motor[leftBack] = mL * EL;
		motor[rightFront] = mR * ER;
		motor[rightBack] = mR * ER;
	}
	while(nMotorEncoder[leftFront] > -1* rotations) {
		mL = -35; mR = 35;
		int diff = nMotorEncoder[leftFront] + nMotorEncoder[rightFront];
		if (diff > 0 ){
			mR -= diff * 2;
		} else if (diff < 0){
			mL -= diff * 2;
		}
		motor[leftFront] = mL * EL;
		motor[leftBack] = mL * EL;
		motor[rightFront] = mR * ER;
		motor[rightBack] = mR * ER;
	}
	motor[leftFront] = 0;
	motor[leftBack] = 0;
	motor[rightFront] = 0;
	motor[rightBack] = 0;
	wait10Msec(1);
}
void turnRight (int rotations, int speed) {
	nMotorEncoder[leftFront] = 0;
	nMotorEncoder[rightFront] = 0;
	while (nMotorEncoder[leftFront] < rotations - 50) {
		mL = speed; mR = -speed;
		int diff = nMotorEncoder[leftFront] + nMotorEncoder[rightFront];
		if (diff > 0 ){
			mL -= diff * 2;
		} else if (diff < 0){
			mR -= diff * 2;
		}
		motor[leftFront] = mL * EL;
		motor[leftBack] = mL * EL;
		motor[rightFront] = mR * ER;
		motor[rightBack] = mR * ER;
	}
	while (nMotorEncoder[leftFront] < rotations) {
		mL = 35; mR = -35;
		int diff = nMotorEncoder[leftFront] + nMotorEncoder[rightFront];
		if (diff > 0 ){
			mL -= diff * 2;
		} else if (diff < 0){
			mR -= diff * 2;
		}
		motor[leftFront] = mL * EL;
		motor[leftBack] = mL * EL;
		motor[rightFront] = mR * ER;
		motor[rightBack] = mR * ER;
	}
	motor[leftFront] = 0;
	motor[leftBack] = 0;
	motor[rightFront] = 0;
	motor[rightBack] = 0;
	wait10Msec(1);
}
void Stop() {
    motor[leftBack] = 1;
    motor[leftFront] = 1;
    motor[rightBack] = 1;
    motor[rightFront] = 1;
    motor[leftBack] = 0;
    motor[leftFront] = 0;
    motor[rightBack] = 0;
    motor[rightFront] = 0;
}
void ArmUp(int rotations) {
	nMotorEncoder[arm3] = 0;
  nMotorEncoder[arm2] = 0;
  while (nMotorEncoder[arm2] < rotations) {

		motor[arm2] = 35;
		//int diffA = nMotorEncoder[arm2] - nMotorEncoder[arm3];
		motor[arm3] = motor[arm2];// + diffA * 2;
		motor[arm] = motor[arm2];
		motor[arm4] = motor[arm3];
  }
  motor[arm2] = 10;
	motor[arm3] = 10;// + diffA * 2;
	motor[arm] = 10;
	motor[arm4] = 10;
}
void ArmDown(int rotations) {
	nMotorEncoder[arm3] = 0;
  nMotorEncoder[arm2] = 0;
  while (nMotorEncoder[arm2] > -1 * rotations) {

		motor[arm2] = -35;
		//int diffA = nMotorEncoder[arm2] - nMotorEncoder[arm3];
		motor[arm3] = motor[arm2];// + diffA * 2;
		motor[arm] = motor[arm2];
		motor[arm4] = motor[arm3];
  }
  motor[arm2] = 10;
	motor[arm3] = 10;// + diffA * 2;
	motor[arm] = 10;
	motor[arm4] = 10;

}

void moveBelt(bool fwd) {
	if (fwd) {
		motor[rightBelt] = 127;
		motor[leftBelt] = 127;
	} else {
		motor[rightBelt] = -127;
		motor[leftBelt] = -127;
	}
	wait10Msec(500);
	motor[rightBelt] = 0;
	motor[leftBelt] = 0;
}
