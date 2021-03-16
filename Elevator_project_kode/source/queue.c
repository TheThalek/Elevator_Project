#include "queue.h"
static int last_position;
static int current_direction;


int current_position(){
    for(int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++){
        if (hardware_read_floor_sensor(i) == 1) {
            return i;
        }
    }
    return (-1);
}


void set_last_position(){
    if(current_position() != (-1)){
        last_position = current_position();
        hardware_command_floor_indicator_on(last_position);
    } 
}


int get_last_position() {
    return last_position;
}


void set_current_direction(int direction) {
    current_direction = direction;
}


void set_start_direction(int new_floor) {
    if(new_floor < last_position) {
        set_current_direction(-1);
    }
    else if (new_floor == last_position){
        set_current_direction(0);
    }
    else if (new_floor > last_position){
        set_current_direction(1);
    }
}


int get_current_direction() {
    return current_direction;
}


int find_direction_when_stop() {
    int new_floor = find_floor_with_order();
    if(last_position > new_floor) {
        return (-1);
    }
    else if(last_position < new_floor) {
        return 1;
    }
    else if(last_position == new_floor){
        if(current_direction == (-1)) {
            return 1;
        }
        else if(current_direction == 1) {
            return (-1);
        }
    }
    return 1;
}


int check_priority_up() {
    return ((get_order(current_position(), 2)) && ((check_order_above() == 1)) && ((get_order(current_position(), 1) == 0) && (get_order(current_position(), 0) == 0)));
}


void movement_up() {
    if(check_order_above() == 1) {
        if(check_order_floor(current_position()) == 1) {
            if(check_priority_up()){
                hardware_command_movement(HARDWARE_MOVEMENT_UP);
            }
            else {
                hardware_command_movement(HARDWARE_MOVEMENT_STOP);
                clear_orders_on_floor(current_position());
                start_timer();
                set_current_state(Wait);
            }
        }
        else if (check_order_floor(current_position()) == 0) {
            hardware_command_movement(HARDWARE_MOVEMENT_UP);
        }
    }
    else if(check_order_above() == 0) {
        if(check_order_below() == 1) {
            set_current_direction(-1);
        }
        else if(check_order_below() == 0) {
            set_current_state(Idle);
        } 
    }
}


int check_priority_down() {
    return ((get_order(current_position(), 0)) && ((check_order_below_current_floor() == 1)) && ((get_order(current_position(), 1) == 0) && (get_order(current_position(), 2) == 0)));
}


void movement_down() {
    if(check_order_below() == 1) {
        if(check_order_floor(current_position()) == 1) {
            if(check_priority_down()) {
                hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
            }
            else{
                hardware_command_movement(HARDWARE_MOVEMENT_STOP);
                clear_orders_on_floor(current_position());
                start_timer();
                set_current_state(Wait);                  
            }
        }
        else if (check_order_floor(current_position()) == 0) {
            hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
        }        
    }
    else if(check_order_below() == 0) {
        if(check_order_above() == 1) {
            set_current_direction(1);
        }
        else if(check_order_above() == 0) {
            set_current_state(Idle);
        } 
    }
}


void queue_manager() {
    if(get_current_direction() == 1) {
        movement_up();
    }
    else if (get_current_direction() == (-1)) {
        movement_down();
    }
    else if(get_current_direction() == 0) {
        start_timer();
        set_current_state(Wait);
    }
}