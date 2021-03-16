#include "lights.h"


void set_order_lights() {
    for (int floor = 0; floor < HARDWARE_NUMBER_OF_FLOORS; floor++) {
        for (int button = 0; button < HARDWARE_NUMBER_OF_BUTTONS; button++) {
            if(hardware_read_order(floor, get_hardwareorder(button))) {
                hardware_command_order_light(floor, get_hardwareorder(button), 1);
            }
        }
    }
}


void clear_order_lights(int floor){
    for (int button = 0; button < HARDWARE_NUMBER_OF_BUTTONS; button++) {
        hardware_command_order_light(floor, get_hardwareorder(button) , 0);
    }
}


void clear_all_order_lights(){
    for (int floor = 0; floor < HARDWARE_NUMBER_OF_FLOORS; floor++) {
        for (int button = 0; button < HARDWARE_NUMBER_OF_BUTTONS; button++) {
            hardware_command_order_light(floor, get_hardwareorder(button), 0);
        }
    }
}


void on_stop_light(){
    hardware_command_stop_light(1);
}


void off_stop_light(){
    hardware_command_stop_light(0);
}


void open_door(){
    hardware_command_door_open(1);
}


void close_door(){
    hardware_command_door_open(0);
}