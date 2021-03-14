#ifndef __STATE_DOT_H__
#define __STATE_DOT_H__


#include "hardware.h"
#include "timer.h"
#include "orders.h"
#include "door.h"
#include "queue.h"
#include <stdbool.h>

typedef enum State {Idle, Move, Wait, StopFloor, StopShaft} state;

void state_idle();

void state_wait();

void state_stop();

void state_run();

void state_move();

#endif


