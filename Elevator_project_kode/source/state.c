#include "state.h"
#include "timer.h"
#include <stdbool.h>

void state_idle() {

}



void state_wait() {
    if (timer_countdown() == 1) {
        close_door();
    }
}



void state_stop() {
    int x = 1;
    if(x=1){
        
    }
}



void state_move() {

}






