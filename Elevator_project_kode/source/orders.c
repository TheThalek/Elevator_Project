#include "orders.h"


int orders[HARDWARE_NUMBER_OF_FLOORS][HARDWARE_NUMBER_OF_BUTTONS]; 

HardwareOrder get_hardwareorder(int button) {
    if(button == 0) {
        return HARDWARE_ORDER_UP;
    }
    else if (button == 1) {
        return HARDWARE_ORDER_INSIDE;
    }
    else if (button == 2) {
        return HARDWARE_ORDER_DOWN;
    }
    return HARDWARE_ORDER_INSIDE;
}


void initialize_order_list() {
    for(int floor = 0; floor < HARDWARE_NUMBER_OF_FLOORS; floor++) {
        for (int button = 0; button < HARDWARE_NUMBER_OF_BUTTONS; button++) {
            if(!((floor == 0) && (button == HARDWARE_ORDER_DOWN)) || !((floor == HARDWARE_NUMBER_OF_FLOORS-1) && (button == HARDWARE_ORDER_UP))) {
                orders[floor][button] = 0;
            }
        }
    }
}


void set_orders() {
    for(int floor = 0; floor < HARDWARE_NUMBER_OF_FLOORS; floor++) {
        for (int button = 0; button < HARDWARE_NUMBER_OF_BUTTONS; button++) {
            if(!((floor == 0) && (button == HARDWARE_ORDER_DOWN)) || !((floor == HARDWARE_NUMBER_OF_FLOORS-1) && (button == HARDWARE_ORDER_UP))) {
                if(orders[floor][button] == 0) {
                    orders[floor][button] = hardware_read_order(floor, get_hardwareorder(button));
                }
            }
        }
    }
}


int get_order(int floor, int button){
    return orders[floor][button];
}


void clear_orders_on_floor(int floor) {
    for(int button = 0; button < HARDWARE_NUMBER_OF_BUTTONS; button++) {
        orders[floor][button] = 0;
    }
    clear_order_lights(floor);
}


void clear_all_orders() {
    for (int floor = 0; floor < HARDWARE_NUMBER_OF_FLOORS; floor++) {
        clear_orders_on_floor(floor);
    }
}


int check_order_floor(int floor) {
    if(floor == (-1)) {
        return 0;
    }
    else {
        for(int button = 0; button < HARDWARE_NUMBER_OF_BUTTONS; button++) {
            if (orders[floor][button]){
                return orders[floor][button];
            }
        }
    }
    return 0;
}


int check_all_order(){
    for (int floor = 0; floor < HARDWARE_NUMBER_OF_FLOORS; floor++){
        if (check_order_floor(floor) == 1){
            return 1;
        }
    }
    return 0;
}



int check_order_above() {
    for(int floor = (get_last_position()+1); floor < HARDWARE_NUMBER_OF_FLOORS; floor++){
        if(check_order_floor(floor)==1) {
            return 1;
        }
    }
    return 0;
}


int check_order_below() {
    for(int floor = 0; floor <= get_last_position(); floor++){
        if(check_order_floor(floor)==1) {
            return 1;
        }
    }
    return 0;
}


int check_order_below_current_floor() {
    for(int floor = 0; floor < get_last_position(); floor++){
        if(check_order_floor(floor)==1) {
            return 1;
        }
    }
    return 0;
}




int find_floor_with_order() {
    for(int floor = 0; floor < HARDWARE_NUMBER_OF_FLOORS; floor++) {
        if(check_order_floor(floor)) {
            return floor;
        }
    }
    return 1;
}



