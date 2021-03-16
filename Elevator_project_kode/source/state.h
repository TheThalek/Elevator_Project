/**
 * @file
 * @brief Library for the implementation of the State Machine
 */


#ifndef __STATE_DOT_H__
#define __STATE_DOT_H__


#include "hardware.h"
#include "timer.h"
#include "orders.h"
#include "queue.h"
#include <stdbool.h>

typedef enum State {Idle, Move, Wait, StopFloor, StopShaft} state;

void set_current_state(state new_state);

void state_init();

void read_stop_signal();

void state_idle();

void state_wait();

void state_stop_floor();

void state_stop_shaft();

void state_move();

void state_run();

#endif


