void RC3(){
    int mL, mR;
    mL = vexRT[Ch3];
    mR = vexRT[Ch3];
    mL = mL + vexRT[Ch1];
    mR = mR - vexRT[Ch1];
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
    motor[left] = mL;
    motor[right] = mR;
    //motor[left] =

    if(vexRT[Btn6U])
        motor[arm] = 63;
    else if(vexRT[Btn6D])
        motor[arm] = -63;
    else
        motor[arm] = 0;

    if(vexRT[Btn5D]) {
        motor[claw] = 127;
    }
    if(vexRT[Btn5U]) {
        motor[claw] = -127;
    }
    if(!vexRT[Btn5U] && !vexRT[Btn5D]) {
        motor[claw] = 0;
    }

}
