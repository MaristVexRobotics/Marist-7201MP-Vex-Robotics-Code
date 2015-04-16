void RC(){

  //Drivetrain
  rcDriveForward = vexRT[Ch3]; //left  thumbstick up   down
  rcDriveStrafe  = vexRT[Ch4]; //left  thumbstick left right
  rcDriveTurn    = vexRT[Ch1]; //right thumbstick left right

  //Scissor Lift
  armPower = vexRT[Ch2Xmtr2]; //right thumbstick up down on second controller
	leftArmPower = vexRT[Ch3Xmtr2];
  if (abs(armPower) <= 10)
		armPower = 0;
	if (abs(leftArmPower) <= 10)
		leftArmPower = 0;
	rightArmPower = armPower;

	if (vexRT[Btn7UXmtr2])
		dualThumbstick = true;
	if (vexRT[Btn8UXmtr2])
		dualThumbstick = false;

  if ((vexRT[Btn5UXmtr2] || vexRT[Btn6UXmtr2]) != (vexRT[Btn5DXmtr2] || vexRT[Btn6DXmtr2])) {
    if (vexRT[Btn5UXmtr2])
      beltPower = BELT_SPEED_SLOW;
    else //if (vexRT[Btn5DXmtr2] || vexRT[Btn6DXmtr2])
      beltPower = -BELT_SPEED_SLOW;

    if (vexRT[Btn6UXmtr2])
      beltPower = BELT_SPEED_FAST;
    else if (vexRT[Btn6DXmtr2])
      beltPower = -BELT_SPEED_FAST;
  } else {
    beltPower = 0;
  }

  if (!vexRT[Btn5U]) {
  	EFL = 1;
    EFR = 1;
    EBL = 1;
    EBR = 1;
  } else {
    EFL = .5;
    EFR = .5;
    EBL = .5;
    EBR = .5;
	}

  /*if (vexRT[Btn8D] && !pneumaticsWereActivated) {
  		pneumaticsActivated = !pneumaticsActivated;
  		pneumaticsWereActivated = true;
  	}
  	if (!vexRT[Btn8D])
  		pneumaticsWereActivated = false;*/

  //if (vexRT[Btn8D]) //3.0.1
    gyroOverride = true;

  if (vexRT[Btn7LXmtr2])
  	correctionOverride = true;
 	else
 		correctionOverride = false;

  if (vexRT[Btn7DXmtr2])
  	armMaintainHeight = CUBE_MAINTAIN_HEIGHT;

  //if (vexRT[Btn8DXmtr2])
  //	armMaintainHeight = SKYRISE_MAINTAIN_HEIGHT;
}
