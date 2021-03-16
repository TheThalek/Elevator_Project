/**
 * @file
 * @brief Library for the implementation of queue
 */


#ifndef __QUEUE_DOT_H__
#define __QUEUE_DOT_H__


#include "hardware.h"
#include "orders.h"
#include "stdio.h"
#include "state.h"

int current_position();


void set_last_position();


int get_last_position();


void set_current_direction(int direction);


void set_start_direction(int new_floor);


int get_current_direction();


int find_direction_when_stop();


int check_priority_up();


void movement_up();


int check_priority_down();


void movement_down();


void queue_manager();


#endif