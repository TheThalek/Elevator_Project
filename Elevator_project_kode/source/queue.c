#include "queue.h"


int current_position(){
    for(int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++){
        if (hardware_read_floor_sensor(i) == 1) {
            return i;
        }
    }
    return (-1);
}

//     Lagrer alle array med bestillinger og sortere. 
// }



