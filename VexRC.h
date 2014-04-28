void RC(){

	//Drivetrain
	leftDrive = vexRT[Ch3];
	rightDrive = vexRT[Ch3];

	//steering
	leftDrive = leftDrive + .5 * vexRT[Ch4];
	rightDrive = rightDrive - .5 * vexRT[Ch4];

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
	if(vexRT[Ch2] >= 20 || vexRT[Ch2] <= -10)
		armVar = vexRT[Ch2] * .5;
	else
		armVar = 10;

	//Set Belt Variables
	if(vexRT[Btn5U] || vexRT[Btn6U]) {
		beltVar = 127;
	}
	if(vexRT[Btn6D] || vexRT[Btn5D]) {
		beltVar = -127;
	}
	if(!vexRT[Btn5U] && !vexRT[Btn5D] && !vexRT[Btn6D] && !vexRT[Btn6U]) {
		beltVar = 0;
	}
}
