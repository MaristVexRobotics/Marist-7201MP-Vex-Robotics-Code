task armReset() {
	setScissorHeight(CUBE_MAINTAIN_HEIGHT - 100, 127);
  armPower = -1;
}

task gotoScoringHeight() {
  setScissorHeight(2200, 127);
}

void AutoRedSkyrise(){ //LEFT
  ClearTimer(T1);









  clearLCDLine(1);
  displayLCDPos(1, 0);
  int autoTime = time1[T1];
  displayNextLCDNumber(autoTime, 6);
}
//endAutoRight
void AutoBlueSkyrise(){ //RIGHT
  ClearTimer(T1);









  clearLCDLine(1);
  displayLCDPos(1, 0);
  int autoTime = time1[T1];
  displayNextLCDNumber(autoTime, 6);
}

void AutoRedPost() {
  EFR = .7;
	EBR = .7;
  ClearTimer(T1);
  Kp = 0;
  Ki = 0;
  Kd = 0;
	setScissorHeight(1500, 127);
  setScissorHeight(CUBE_MAINTAIN_HEIGHT - 100, 127);
  armPower = -1;
	moveForward(350, 127);
	motor[leftBack] = -20;
	motor[rightBack] = -20;
	motor[rightFront] = -20;
	motor[leftFront] = -20;
	wait10Msec(2);
	drivetrainStop();
	beltFwd(650);
	moveBackward(480, 127);
	drivetrainStop();
	turnRight(90, 127);
	drivetrainStop();
	moveForward(350, 127);
	drivetrainStop();
	beltFwd(600);
	moveLeft(500, 127);
	drivetrainStop();
	moveForward(330, 127);
	drivetrainStop();
	StartTask(gotoScoringHeight);
	turnRight(83, 127);
	moveForward(260, 127);
	drivetrainStop();
	StartTask(armReset);
	beltBkwd(1200);
	moveBackward(200, 127);








  clearLCDLine(1);
  displayLCDPos(1, 0);
  int autoTime = time1[T1];
  displayNextLCDNumber(autoTime, 6);
}

void AutoBluePost() {
	EFR = .7;
	EBR = .7;
  ClearTimer(T1);
  Kp = 0;
  Ki = 0;
  Kd = 0;
	setScissorHeight(1500, 127);
  setScissorHeight(CUBE_MAINTAIN_HEIGHT - 100, 127);
  armPower = -1;
	moveForward(350, 127);
	drivetrainStop();
	beltFwd(700);
	moveBackward(480, 127);
	turnLeft(90, 127);
	drivetrainStop();
	moveForward(350, 127);
	drivetrainStop();
	beltFwd(600);
	moveRight(500, 127);
	drivetrainStop();
	moveForward(500, 127);
	drivetrainStop();
	StartTask(gotoScoringHeight);
	turnLeft(90, 127);
	moveForward(300, 127);
	drivetrainStop();
	StartTask(armReset);
	beltBkwd(1000);
	moveBackward(200, 127);




	/*Kp = 0.8;
  Ki = 0.005;
  Kd = 0.05;*/
  clearLCDLine(1);
  displayLCDPos(1, 0);
  int autoTime = time1[T1];
  displayNextLCDNumber(autoTime, 6);
}
