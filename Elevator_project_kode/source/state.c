#include "state.h"




static inline state current_state = Idle;

//Lagrer siste posisjon (global variabel) Skal kunne endres i både states og queue
//Lagrer retning (global variabel) Skal kunne endres i både states og queue




void state_idle() {
    for(int floor = 0; floor < HARDWARE_NUMBER_OF_FLOORS; floor++) {
            if(check_order_floor(floor) == 1){
                set_start_direction(floor);
                current_state = Move;    
            }
    }
}


void state_wait() {
    //Hvis obstruksjon, hold døra åpen
    //Når obstruksjon blir sluppet, start_timer();
    if (get_current_direction() == 0){
        if (timer_countdown() == 1) {
            printf("Im going to idle \n");
            clear_orders_on_floor(current_position());
            close_door();
            current_state = Idle;
        }
    }
    
    else {
        if (timer_countdown() == 1) {
            printf("Im going to move \n");
            close_door();
            current_state = Move;
        }
    }
}




void state_stop_floor() {
    while(hardware_read_stop_signal()) {
        //HA PÅ STOP-LYSET
        //åpne dør
        //slette alle bestillinger
    }
    //gå til wait
}

void state_stop_shaft(){
    // while(hardware_read_stop_signal()) {
    //     //HA PÅ STOP-LYSET
    //     //Slette alle bestillinger
    // }
    // while //(ingen bestilling) {
    //     //Ingenting
    // }
    // //hent last position og current direction. ut ifrå dette skal heisen bevege seg opp eller ned.
    // //Sette current_direction
    // //Gå til Move
}




void state_move() {
    if(get_current_direction() == 1) {
        if(check_order_above() == 1) {
            if(check_order_floor(current_position()) == 1) {
                hardware_command_movement(HARDWARE_MOVEMENT_STOP);
                clear_orders_on_floor(current_position());
                start_timer();
                open_door();
                current_state = Wait;
            }
            else if (check_order_floor(current_position()) == 0) {
                hardware_command_movement(HARDWARE_MOVEMENT_UP);
            }
            
        }
        else if(check_order_above() == 0) {
            if(check_order_below() == 1) {
                set_direction(-1);
            }
            else if(check_order_below() == 0) {
                current_state = Idle;
            } 
        }
    }

    else if(get_current_direction() == (-1)) {
        if(check_order_below() == 1) {
            if(check_order_floor(current_position()) == 1) {
                hardware_command_movement(HARDWARE_MOVEMENT_STOP);
                clear_orders_on_floor(current_position());
                start_timer();
                open_door();
                current_state = Wait;
            }
            else if (check_order_floor(current_position()) == 0) {
                hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
            }
            
        }
        else if(check_order_below() == 0) {
            if(check_order_above() == 1) {
                set_direction(1);
            }
            else if(check_order_above() == 0) {
                open_door();
                current_state = Idle;
            } 
        }
    }


    else if (get_current_direction() == 0) {
        start_timer();
        open_door();
        printf("open door \n");
        current_state = Wait;
    }
}








void state_run() {
    while(1) {
        set_orders(); 
        set_order_lights();
        set_last_position();
        if (hardware_read_stop_signal()){
            hardware_command_movement (HARDWARE_MOVEMENT_STOP);
            break;
        }
        // if(hardware_read_stop_signal()){
        //     hardware_command_movement(HARDWARE_MOVEMENT_STOP);
        //     if(current_position() == (-1)) {
        //         current_state = StopShaft;
        //     }
        //     else {
        //         current_state = StopFloor;
        //     }
        // }

        //SJekke stop_knapp();
        switch(current_state) {
            case(Idle):{
                state_idle();                           
                break;
                }
            case(Wait):
                state_wait();
                break;

            // case(StopFloor): {
            //     state_stop_floor();
            //     break;
            // }
            // case(StopShaft): {
            //     state_stop_shaft();
            //     break;
            // }
            case(Move):{
                state_move();
                break;
                }
        }
    }
}