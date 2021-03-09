#include <time.h>
#include "timer.h"

#define TIME_LIMIT 3

//definerer time limit som 3 sekunder. DONE
//definerer der timeren slutter som -1 (3-2, 2-1, 1-0) DONE
//funksjon som starter timer (henter inn tida time(NULL))
//funksjon der timeren går ut
    //hvis timeren slutter aka timer == -1, stop 
    //hvis timeren er ikke lik -1, så har vi time(NULL) - timer 

static int timer_countdown = -1;

void timer_start(time_t* current_time){
    time(current_time);
}

int timer_countdown(){
    if (timer_countdown == -1){
        return 0;
    }
    else{
        return (current_time - timer_countdown 
    }
}



