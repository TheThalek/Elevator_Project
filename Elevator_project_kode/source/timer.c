#include <time.h>
#include <stdlib.h>
#include "timer.h"

#define TIME_LIMIT 3

static int set_timer = -1;

void start_timer(){
    set_timer = time(NULL);
}

int timer_countdown(){
    if(set_timer == -1){
        return 0;
    }
    else{
        return (time(NULL) - set_timer > TIME_LIMIT);
    }
}



