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
 * @brief Returns the given value saved in the specified place in the orders-array.
 * 
 * @param [in] floor The specified floor
 * @param [in] button The specified order-button
 * 
 * @return orders[floor][button], which is 1 if it has an active order, 0 otherwise
*/
int get_order(int floor, int button);


/**
 * @brief Clears all order on a given floor
 * 
 * @param [in] floor The specified floor.
*/
void clear_orders_on_floor(int floor);


/**
 * @brief Clears all orders by iterating clear_orders_on_floor(int floor) through all floors.
 * 
*/
void clear_all_orders();


/**
 * @brief If floor != (-1), if the elevator is not in an undefined position, check if the there is an active order on the current floor.
 * 
 * @param [in] floor The current floor.
 * 
 * @return 0, if floor != (-1), or if there aren't active orders on floor. 1, there is an active order on the current floor.
*/
int check_order_floor(int floor);


/**
 * @brief Check for all active orders by iterating through all existing floors.
 * For each iteration, checks if check_order_floor(int floor) == 1. If true, return 1. False, return 0.
 * 
 * @return 1, if there is an active order on any of the floors. 0, if there are no active orders.
*/
int check_all_order();


/**
 * @brief Check for all active orders above current floor by iterating between current floor and top floor. 
 * For each iteration, checks if check_order_floor(int floor) == 1. If true, return 1. False, return 0.
 * 
 * @return 1, if there is an active order on any of the floors above. 0, otherwise.
*/
int check_order_above();


/**
 * @brief Check for all active orders below current floor by iterating between ground floor and current floor. 
 * For each iteration, checks if check_order_floor(int floor) == 1. If true, return 1. False, return 0.
 * 
 * @return 1, if there is an active order on any of the floors below. 0, otherwise.
*/
int check_order_below();


/**
 * @brief Check for all active orders below current floor by iterating between ground floor and the floor directly under the current floor.
 * Used in check_priority_down() in queue.c.
 * For each iteration, checks if check_order_floor(int floor) == 1. If true, return 1. False, return 0.
 * 
 * @return 1, if there is an active order on any of the floors below. 0, otherwise.
*/
int check_order_below_current_floor();


/**
 * @brief Finds a floor with an active order.
 * Uses check_order_floor(int floor) by iterating through all floors, and returning the floor with an active order.
 * 
 * @return the floor with an active order, 1 if invalid floor.
*/
int find_floor_with_order();


#endif