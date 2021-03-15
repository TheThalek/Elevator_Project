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





//last position lagrer kun siste definert posisjon, altså den kan aldri være -1
void set_last_position(){
    if(current_position() != (-1)){
        last_position = current_position();
        hardware_command_floor_indicator_on(last_position);
    } 
}


int get_last_position() {
    return last_position;
}

//setter current direction når man er i idle 
void set_start_direction(int new_floor) {
    //direction = ned
    if(new_floor < last_position) {
        set_direction(-1);
    }
    //direction = samme
    else if (new_floor == last_position){
        set_direction(0);
    }
    //direction = opp
    else if (new_floor > last_position){
        set_direction(1);
    }
}


void set_direction(int direction) {
    current_direction = direction;
}


int get_current_direction() {
    return current_direction;
}





int find_direction_when_stop() {
    printf("Im looking for the right direction \n");
    int new_floor = find_floor_with_order();
    if(last_position > new_floor) {
        printf("Setting new directin = -1 \n");
        return (-1);
    }
    else if(last_position < new_floor) {
        printf("Setting new directin = 1 \n");
        return 1;
    }
    else if(last_position == new_floor){
        if(current_direction == (-1)) {
            printf("Setting new directin = -1 \n");
            return 1;
        }
        else if(current_direction == 1) {
            printf("Setting new directin = -1 \n");
            return (-1);
        }
    }
}

