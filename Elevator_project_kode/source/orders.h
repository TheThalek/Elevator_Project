/**
 * @file
 * @brief Implementation of management of orders.
 */




#ifndef __ORDERS_DOT_H__
#define __ORDERS_DOT_H__

#include "stdbool.h"
#include "hardware.h"
#include "queue.h"
#include "lights.h"

void initialize_order_list();
void set_orders();
void clear_orders_on_floor(int floor);
void clear_all_orders();
int get_order(int floor, int button);
int check_order_floor(int floor);
int check_all_order();
int check_order_below();
int check_order_above();
int find_floor_with_order();
int check_order_below_except_current_floor();

#endif