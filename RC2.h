void RC2(){
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
    
    if(vexRT[Ch2] >= 10 || vexRT[Ch2] <= -10)
        motor[arm] = vexRT[Ch2];
    else
        motor[arm] = 0;
    motor[arm2] = motor[arm];
    
    if(vexRT[Btn5U] || vexRT[Btn5D]) {
        motor[claw] = 127;
    }
    if(vexRT[Btn6D] || vexRT[Btn6U]) {
        motor[claw] = -127;
    }
    if(!vexRT[Btn5U] && !vexRT[Btn5D] && !vexRT[Btn6D] && !vexRT[Btn6U]) {
        motor[claw] = 0;
    }
    
    if(vexRT[Btn7U] == 1){
        //active = false;
    }
    
}