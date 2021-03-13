#include "state.h"




static inline state current_state = Idle;



void state_idle() {
    for(int floor = 0; floor < HARDWARE_NUMBER_OF_FLOORS; floor++) {
            if(hardware_read_order(floor, HARDWARE_ORDER_UP)) {
                current_state = Move;
            }
            if(hardware_read_order(floor, HARDWARE_ORDER_INSIDE)) {
                current_state = Move;
            }
            if(hardware_read_order(floor, HARDWARE_ORDER_DOWN)) {
                current_state = Move;
            }
    }
}



void state_wait() {
    if (timer_countdown() == 1) {
        close_door();
    }
}



void state_stop() {
    
}



void state_move() {
    if(get_order(3,2) == 1) {
        while (!(current_position() == 3)) {
            hardware_command_movement(HARDWARE_MOVEMENT_UP);
        }
    }
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
}







void state_run() {
    while(1) {
        set_orders();
        if(hardware_read_stop_signal()){
            hardware_command_movement(HARDWARE_MOVEMENT_STOP);
            break;
        }
        //Lage array (?) med knappetrykk, til lagring. T.d. legge desse i orders T.d. ti plasser, 1. = [1000][100], 2=[1000][010]
        //sjekke

        //SJekke stop_knapp();
        
        switch(current_state) {
            case(Idle):{
                state_idle();
                break;}
        //     case(Wait):
        //         state_wait();

        //     case(Stop):
        //         state_stop();
            case(Move):{
                open_door();
                state_move();
                break;}
                //state_move();
        }
    }
}