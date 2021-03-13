#include "orders.h"
#include "hardware.h"


int orders[HARDWARE_NUMBER_OF_FLOORS][HARDWARE_NUMBER_OF_BUTTONS]; 

// int get_all_orders(){
//     return orders;
// }

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
}


void set_orders() {
    for (int button = 0; button < HARDWARE_NUMBER_OF_BUTTONS; ++button) {
        for(int floor = 0; floor < HARDWARE_NUMBER_OF_FLOORS; ++floor) {
            if(!((floor == 0) && (button == HARDWARE_ORDER_DOWN)) || !((floor == HARDWARE_NUMBER_OF_FLOORS-1) && (button == HARDWARE_ORDER_UP))) {
                orders[floor][button] = hardware_read_order(floor, get_hardwareorder(button));
            }
        }
    }
}


void clear_orders_on_floor(int floor) {
    for(int button = 0; button < HARDWARE_NUMBER_OF_BUTTONS; button++) {
        orders[floor][button] = 0;
    }
}

void clear_all_orders() {
    for (int floor = 0; floor < HARDWARE_NUMBER_OF_FLOORS; floor++) {
        clear_orders_on_floor(floor);
    }
}

int get_order(int floor, int button){
    return orders[floor][button];
}










