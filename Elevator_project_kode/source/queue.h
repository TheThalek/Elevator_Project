#ifndef __QUEUE_DOT_H__
#define __QUEUE_DOT_H__


#include "hardware.h"
#include "orders.h"

int current_position();
void set_last_position();
int get_last_position();
void set_start_direction(int new_floor);
void set_direction(int direction);
int get_current_direction();
void queue_update();

#endif