int precision = 1;

//=====================================================================================================================
//
//												OMNIDIRECTIONAL
//
//=====================================================================================================================
#if TYPE == 1
void move (int rotationsF, int rotationsR, int speed) {
  int m1, m2, m3, m4, speed2;
  if (abs(rotationsF) >= abs(rotationsR)){
    m1 = speed * (rotationsF / abs( rotationsF));
	m2 = speed * (rotationsF / abs( rotationsF));
	m3 = speed * (rotationsF / abs( rotationsF));
	m4 = speed * (rotationsF / abs( rotationsF));
	speed2 = (rotationsR / abs(rotationsF)) * speed;
	m1 = m1 + speed2;
	m2 = m2 - speed2;
	m3 = m3 - speed2;
	m4 = m4 + speed2;
  } else {
    m1 = speed * (rotationsF / abs( rotationsF));
	m2 = -speed * (rotationsF / abs( rotationsF));
	m3 = -speed * (rotationsF / abs( rotationsF));
	m4 = speed * (rotationsF / abs( rotationsF));
	speed2 = (rotationsF / abs(rotationsR)) * speed;
	m1 = m1 + speed2;
	m2 = m2 + speed2;
	m3 = m3 + speed2;
	m4 = m4 + speed2;
  }
  if(m1 > 127){
    m1 = 127;
  } else if(m1 < -127){
    m1 = -127;
  }
  if(m2 > 127){
    m2 = 127;
  } else if(m2 < -127){
    m2 = -127;
  }
  if(m3 > 127){
    m3 = 127;
  } else if(m3 < -127){
    m3 = -127;
  }
  if(m4 > 127){
    m4 = 127;
  } else if(m4 < -127){
    m4 = -127;
  }
  motor[FL] = m1 - 3;
  motor[FR] = m2 - 2;
  motor[BL] = m3 - 1;
  motor[BR] = m4;
  motor[FL] = m1
  motor[FR] = m2
  motor[BL] = m3

  if (abs(rotationsF) >= abs(rotationsR)) {
    wait1Msec[(abs(rotationsF) * 600) * (127 / speed)];
  } else {
    wait1Msec[(abs(rotationsR) * 600) * (127 / speed)];
  }
}

void glide() {
  bool end = false;
  while (end = false){
    if (motor[FL] > 0){
      motor[FL] = motor[FL] - 1;
    }
    if (motor[FR] > 0){
      motor[FR] = motor[FR] - 1;
    }
    if (motor[FL] < 0){
      motor[FL] = motor[FL] + 1;
    }
    if (motor[FR] > 0){
      motor[FR] = motor[FR] + 1;
    }
	if (motor[BL] > 0){
      motor[BL] = motor[BL] - 1;
    }
    if (motor[BR] > 0){
      motor[BR] = motor[BR] - 1;
    }
    if (motor[BL] < 0){
      motor[BL] = motor[BL] + 1;
    }
    if (motor[BR] > 0){
      motor[BR] = motor[BR] + 1;
    }
    if (motor[FR] == 0 && motor[FL] == 0 && motor[BR] == 0 && motor[BL] == 0){
      end = true;
    } else {
      wait10Msec[1];
    }
  }
}

void moveThenStop (int rotationsF, int rotationsR, int speed) {
  move(rotations, speed);
  motorBrake[m1];
  motorBrake[m2];
  motorBrake[m3];
  motorBrake[m4];
  }

void moveThenGlide (int rotationsF, int rotationsR, int speed) {
  move(rotations, speed);
  glide();
}

void RC(){
    int x = 0;
  while(x==0){
    int m1, m2, m3, m4, Cha3, Cha4;
	Cha3 = vexRT[Ch3];
	Cha4 = vexRT[Ch4];
	if (abs(Cha3) >= 10) {
	  m1 = Cha3;
      m2 = Cha3;
      m3 = Cha3;
      m4 = Cha3;
	}
	if (abs(Cha4) >= 10) {
	  m1 = m1 + Cha4;
      m2 = m2 - Cha4;
      m3 = m3 - Cha4;
      m4 = m4 + Cha4;
	}

    if(vexRT[Btn8R] == 1 && vexRT[Btn8L] == 0){
    m1 = m1 + 64;
    m2 = m2 - 64;
    m3 = m3 + 64;
    m4 = m4 - 64;
    } else if(vexRT[Btn8L] == 1 && vexRT[Btn8R] == 0){
    m1 = m1 - 64;
    m2 = m2 + 64;
    m3 = m3 - 64;
    m4 = m4 + 64;
    }
    if(m1 > 127){
      m1 = 127;
    } else if(m1 < -127){
      m1 = -127;
    }
    if(m2 > 127){
      m2 = 127;
    } else if(m2 < -127){
      m2 = -127;
    }
    if(m3 > 127){
      m3 = 127;
    } else if(m3 < -127){
      m3 = -127;
    }
    if(m4 > 127){
      m4 = 127;
    } else if(m4 < -127){
      m4 = -127;
    }
    motor[FL] = m1 / precision;
    motor[FR] = m2 / precision;
    motor[BL] = m3 / precision;
    motor[BR] = m4 / precision;

    if(vexRT[Btn7U] == 1){
      x = 1;
    }

	motor[Arm] = vexRT[Ch2];
	if (vexRT[Btn5U] == 1) {
	  motor[Claw] = CLAWCLOSE;
	} else if (vexRT[Btn6U] == 1) {
	  motor[Claw] = ClawOPEN;
	}

	motor[Claw] = motor[Claw] - vexRT[Btn5D] + vexRT[Btn6D];
  }
}

void turn (int motorRotations, int speed) {
  motor[FR] = speed * (motorRotations / abs( motorRotations));
  motor[BR] = speed * (motorRotations / abs( motorRotations));
  motor[FL] = -1 * (speed * (motorRotations / abs( motorRotations)));
  motor[BL] = -1 * (speed * (motorRotations / abs( motorRotations)));
  wait1Msec[(abs(motorRotations) * 600) * (127 / speed)];
}


//=====================================================================================================================
//
//													NOT OMNIDIRECTIONAL
//
//=====================================================================================================================
#else
void move (int rotations, int speed) {
  motor[Left] = speed * (rotations / abs( rotations) ) - 1;
  motor[Right] = speed * (rotations / abs( rotations) );
  motor[Left] = speed * (rotations / abs( rotations) )
  wait1Msec[(abs(rotations) * 600) * (127 / speed)];
}

void glide() {
  bool end = false;
  while (end = false){
    if (motor[Left] > 0){
      motor[Left] = motor[Left] - 1;
    }
    if (motor[Right] > 0){
      motor[Right] = motor[Right] - 1;
    }
    if (motor[Left] < 0){
      motor[Left] = motor[Left] + 1;
    }
    if (motor[Right] > 0){
      motor[Right] = motor[Right] + 1;
    }
    if (motor[Right] == 0 && motor[Left] == 0){
      end = true;
    } else {
      wait10Msec[1];
    }
  }
}

void moveThenStop (int rotations, int speed) {
  move(rotations, speed);
  motorBrake[Left];
  motorBrake[Right];
}

void moveThenGlide (int rotations, int speed) {
  move(rotations, speed);
  glide();
}

void RC(){
  bool active = true;
  while(active == true){
    int mL, mR, Cha3, Cha4;
	Cha3 = vexRT[Ch3];
	Cha4 = vexRT[Ch4];
    if (abs(Cha3) >= 10) {
	  mL = Cha3;
      mR = Cha3;
	}
	if (abs(Cha4) >= 10) {
      mL = mL + Cha4;
      mR = mR - Cha4;
	}
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
    motor[Left] = mL / precision;
    motor[Right] = mR / precision;


    if(vexRT[Btn7U] == 1){
      active = false;
    }

	motor[Arm] = vexRT[Ch2];
	if (vexRT[Btn5U] == 1) {
	  motor[Claw] = CLAWCLOSE;
	} else if (vexRT[Btn6U] == 1) {
	  motor[Claw] = ClawOPEN;
	}

	motor[Claw] = motor[Claw] - vexRT[Btn5D] + vexRT[Btn6D];
  }
}

void turn (int motorRotations, int speed) {
  motor[Right] = speed * (motorRotations / abs( motorRotations));
  motor[Left] = -1 * (speed * (motorRotations / abs( motorRotations)));
  wait1Msec[(abs(motorRotations) * 600) * (127 / speed)];
}

#endif

//=====================================================================================================================
//
//														ARM CONTROLS
//
//=====================================================================================================================

void armMove (int motorRotations) {
  const speed = 90;
  if (motorRotations > 0) {
    motor[Arm] = speed;
  } else if (motorRotations < 0) {
    motor[Arm] = speed * -1;
  }
  wait1Msec[(abs(motorRotations) * 600) * (127 / speed)];
}

void clawOpen() {
  motor[Claw] = CLAWOPEN;
}

void clawClose() {
  motor[Claw] = CLAWCLOSE;
}
