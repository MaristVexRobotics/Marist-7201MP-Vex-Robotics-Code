void RC(){

  //Drivetrain
  rcDriveForward = vexRT[Ch3]; //left  thumbstick up   down
  rcDriveStrafe  = vexRT[Ch4]; //left  thumbstick left right
  rcDriveTurn    = vexRT[Ch1]; //right thumbstick left right

  //Scissor Lift
  armPower = vexRT[Ch2Xmtr2]; //right thumbstick up down on second controller
	if (abs(armPower) <= 10)
		armPower = 0;

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

  if ((vexRT[Btn5U] || vexRT[Btn6U]) != (vexRT[Btn5D] || vexRT[Btn6D])) {
    if (vexRT[Btn5U])
      skyrisePower = SKYRISE_SPEED_SLOW;
    else //if (vexRT[Btn5D] || vexRT[Btn6D])
      skyrisePower = -SKYRISE_SPEED_SLOW;

    if (vexRT[Btn6U])
      skyrisePower = SKYRISE_SPEED_FAST;
    else if (vexRT[Btn6D])
      skyrisePower = -SKYRISE_SPEED_FAST;
  } else {
    skyrisePower = 0;
  }

  if (vexRT[Btn8D]) //3.0.1
    gyroOverride = true;
}
