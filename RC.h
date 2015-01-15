void RC(){

  //Drivetrain
  rcDriveForward = vexRT[Ch3]; //left  thumbstick up   down
  rcDriveStrafe  = vexRT[Ch4]; //left  thumbstick left right
  rcDriveTurn    = vexRT[Ch1]; //right thumbstick left right

  //Scissor Lift
  armPower = vexRT[Ch2Xmtr2]; //right thumbstick up down on second controller


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
}
