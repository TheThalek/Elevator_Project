#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "initialize.h"
#include "hardware.h"
#include "state.h"
#include "queue.h"
#include "timer.h"




int main() {
    int error = hardware_init();
    if(error != 0){
        fprintf(stderr, "Unable to initialize hardware\n");
        exit(1);
    }

    initialize();
    
    open_door();
    start_timer();


    while(1) {
        if(hardware_read_stop_signal()){
            hardware_command_movement(HARDWARE_MOVEMENT_STOP);
            break;
        }

        //enum State current_state = Idle;


        // switch(current_state) {
        //     case(Idle):
        //         state_idle();
        //     case(Wait):
        //         state_wait();

        //     case(Stop):
        //         state_stop();
        //     case(Move):
        //         state_move();
        // }
    }



    // while(1){
    //     if(hardware_read_stop_signal()){
    //         hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    //         break;
    //     }

    //     /* Code block that makes the elevator go up when it reach the botton*/
    //     if(hardware_read_floor_sensor(0)){
    //         hardware_command_movement(HARDWARE_MOVEMENT_UP);
    //     }

    //     /* Code block that makes the elevator go down when it reach the top floor*/
    //     if(hardware_read_floor_sensor(HARDWARE_NUMBER_OF_FLOORS - 1)){
    //         hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
    //     }

    //     /* All buttons must be polled, like this: */
    //     for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
    //         if(hardware_read_floor_sensor(f)){
    //             hardware_command_floor_indicator_on(f);
    //         }
    //     }

    //     /* Lights are set and cleared like this: */
    //     for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
    //         /* Internal orders */
    //         if(hardware_read_order(f, HARDWARE_ORDER_INSIDE)){
    //             hardware_command_order_light(f, HARDWARE_ORDER_INSIDE, 1);
    //         }

    //         /* Orders going up */
    //         if(hardware_read_order(f, HARDWARE_ORDER_UP)){
    //             hardware_command_order_light(f, HARDWARE_ORDER_UP, 1);
    //         }

    //         /* Orders going down */
    //         if(hardware_read_order(f, HARDWARE_ORDER_DOWN)){
    //             hardware_command_order_light(f, HARDWARE_ORDER_DOWN, 1);
    //         }
    //     }

    //     /* Code to clear all lights given the obstruction signal */
    //     if(hardware_read_obstruction_signal()){
    //         hardware_command_stop_light(1);
    //         clear_all_order_lights();
    //     }
    //     else{
    //         hardware_command_stop_light(0);
    //     }
    // }

    return 0;
}