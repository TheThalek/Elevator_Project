#include "initialize.h"


    //Hardware init, if 0 -> stop/ferdig med heile programmet
    //INITIALIZE----(void elevator_init()) lages til funksjon

void initialize() {
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




