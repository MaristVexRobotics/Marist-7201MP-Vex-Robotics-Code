void RC(){
	getJoystickSettings(joystick);

	//Drivetrain
	leftDrive = joystick.joy1_y1;
	rightDrive = joystick.joy1_y1;

	//steering
	leftDrive = leftDrive + .5 * joystick.joy1_x1;
	rightDrive = rightDrive - .5 * joystick.joy1_x1;

	//correct for too big motor values
	if(leftDrive > 127){
		leftDrive = 127;
		} else if (leftDrive < -127){
		leftDrive = -127;
	}
	if(rightDrive > 127){
		rightDrive = 127;
		} else if(rightDrive < -127){
		rightDrive = -127;
	}

	//Set Arm Variables
	if(joystick.joy1_y2 >= 10 || joystick.joy1_y2 <= -10)
		armVar = joystick.joy1_y2;
	else
		armVar = 10;

	//Set Belt Variables
	if(joy1Btn(5) == 1) { //Right Bumper
		beltVar = 127;
	}
	if(joy1Btn(6) == 1) { //Left Bumper
		beltVar = -127;
	}
	if(!joy1Btn(5) == 1 && !joy1Btn(6) == 1) {
		beltVar = 0;
	}
}
