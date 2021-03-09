#include "hardware.h"
#include "door.h"


void open_door(){
    hardware_command_door_open(1);
}

void close_door(){
    hardware_command_door_open(0);
}