void RC4(){
    motor[left] = vexRT[Ch3];
    motor[right] = vexRT[Ch2];
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