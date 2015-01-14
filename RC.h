void RC(){

  //Drivetrain
  rcDriveForward = vexRT[Ch3]; //left  thumbstick up   down
  rcDriveStrafe  = vexRT[Ch4]; //left  thumbstick left right
  rcDriveTurn    = vexRT[Ch1]; //right thumbstick left right

  //Scissor Lift
  armPower = vexRT[Ch2Xmtr2]; //right thumbstick up down on second controller
  if (armPower >= 0 && armPower < MAINTAIN_HEIGHT_ARM_POWER)
    armPower = MAINTAIN_HEIGHT_ARM_POWER;


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

  if (vexRT[Btn8D]) //3.0.1
    gyroOverride = true;

  //Belt
  /*if (vexRT[Btn8UXmtr2] != vexRT[Btn8DXmtr2] && beltNextPos < 4) {
    if (vexRT[Btn8UXmtr2])
      beltNextPos = beltNextPos + 1;
    if (vexRT[Btn8DXmtr2] && beltNextPos > 1)
      beltNextPos = beltNextPos - 1;
  }*/


}
