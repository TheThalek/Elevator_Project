#include "timer.h"


#define TIME_LIMIT 3

static time_t set_timer = -1; //Endre til nøyaktig variabel

void start_timer(){
    set_timer = time(NULL);
}

bool timer_countdown(){
    if(set_timer == -1){
        return 0;
    }
    else{
        return ((time(NULL) - set_timer) > TIME_LIMIT);
    }
}



