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

HardwareOrder get_hardwareorder(int button);


/**
 * @brief Initializes the order-array, makes an empty array: orders[floor][button]
*/
void initialize_order_list();



/**
 * @brief Iterates through all the buttons on the floor-panel. If a button is pushed, the corresponding place in the array will be set to active.
*/
void set_orders();


/**
 * @brief Iterates through all the buttons on the floor-panel. If a button is pushed, the corresponding place in the array will be set to active.
*/
int get_order(int floor, int button);


void clear_orders_on_floor(int floor);


void clear_all_orders();


int check_order_floor(int floor);


int check_all_order();


int check_order_above();


int check_order_below();


int check_order_below_current_floor();


int find_floor_with_order();


#endif