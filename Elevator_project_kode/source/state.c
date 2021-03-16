#include "state.h"




static inline state current_state = Idle;


void set_current_state(state new_state) {
    current_state = new_state;
}


void state_init() {
    bool at_floor = 0;
    while (!at_floor) {
        for (int i = 0; i < (HARDWARE_NUMBER_OF_FLOORS); i++) {
            at_floor += hardware_read_floor_sensor(i);
        }    
        if (!at_floor) {
            hardware_command_movement(HARDWARE_MOVEMENT_UP);
        }
    }
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    initialize_order_list();
    clear_all_order_lights();
};


void read_stop_signal() {
        if (hardware_read_stop_signal()){
            hardware_command_movement (HARDWARE_MOVEMENT_STOP);
        if (current_position() == (-1)){
            current_state = StopShaft;
        }
        else {
            current_state = StopFloor;
        }
    }
}


void state_idle() {
    close_door();
    for(int floor = 0; floor < HARDWARE_NUMBER_OF_FLOORS; floor++) {
            if(check_order_floor(floor) == 1){
                set_start_direction(floor);
                current_state = Move;    
            }
    }
}


void state_wait() {
    if(hardware_read_obstruction_signal() == 1) {
        start_timer();
    }
    if(timer_countdown() == 1) {
        if(get_current_direction() == 0) {
            close_door();
            clear_orders_on_floor(current_position());
            current_state = Idle;
        }
        else {
            close_door();
            current_state = Move;
        }
    }
}


void state_stop_floor() {
    while(hardware_read_stop_signal()) {
        hardware_command_movement(HARDWARE_MOVEMENT_STOP);
        on_stop_light(); 
        clear_all_orders(); 
        clear_all_order_lights();
        open_door();
    }
    off_stop_light();
    start_timer();   
    set_current_direction(0);
    current_state = Wait;
}


void state_stop_shaft(){
    while(hardware_read_stop_signal()) {
        hardware_command_movement(HARDWARE_MOVEMENT_STOP);
        on_stop_light(); 
        clear_all_orders(); 
        clear_all_order_lights();
    }
    off_stop_light();
    while(check_all_order() == 0) {
        set_orders();
        set_order_lights();
        if (hardware_read_stop_signal()){
            current_state = StopShaft;
            break;
        }
    }
    set_current_direction(find_direction_when_stop());
    current_state = Move;
}


void state_move() {
    queue_manager();
}


void state_run() {
    while(1) {
        set_orders(); 
        set_order_lights();
        set_last_position();
        read_stop_signal();

        switch(current_state) {
            case(Idle):{
                state_idle();                           
                break;
                }
            case(Wait):
                state_wait();
                break;

            case(StopFloor): {
                state_stop_floor();
                break;
            }
            case(StopShaft): {
                state_stop_shaft();
                break;
            }
            case(Move):{
                state_move();
                break;
                }
        }
    }
}