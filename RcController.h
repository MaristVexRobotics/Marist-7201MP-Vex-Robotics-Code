#include "RC1.h"
#include "RC2.h"
#include "RC3.h"
#include "RC4.h"

void RCController () {
    bool active = true;
    int toggle = 1;
    while(active == true){
        switch (toggle) {
            case 1:
                RC1();
                break;
            case 2:
                RC2();
                break;
            case 3:
                RC3();
                break;
            case 4:
                RC4();
                break;
        }
        if(vexRT[Btn8R] == 1)
            toggle = 1;
        else if(vexRT[Btn8L] == 1)
            toggle = 2;
        else if(vexRT[Btn8U] == 1)
            toggle = 3;
        else if(vexRT[Btn8D] == 1)
            toggle = 4;
        if(vexRT[Btn7U] == 1){
            //active = false;
        }
    }
}
