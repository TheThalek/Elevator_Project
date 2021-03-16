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

/** @brief Finds the current position
 * 
 * @return -1, if in an undefined floor, the floor number if in a defined floor. 
*/
int current_position();


/** @brief The last_position variable is updated
 * When the elevator moves to a defined floor, last_position = current_position()
*/
void set_last_position();



/** @brief Returns last_position
 * @return last_position
*/
int get_last_position();


/** @brief Changes current_direction to direction.
 * 
 * @param [in] direction
*/
void set_current_direction(int direction);


/** @brief Chooses the starting direction, when order is placed in idle
 * 
 * @param [in] new_floor The ordered floor
*/
void set_start_direction(int new_floor);


/** @brief Returns current_direction
 * 
 * @return current_direction
*/
int get_current_direction();


/** @brief Decides te new direction, when order is placed in state StopShaft.
 * Uses new_floor and last_position to decide which floors the elevator is located between. Chooses the direction based on this.
 * 
 * @return -1 = direction down, 1 = direction up.
 * @return 1 if unexpected event.
*/
int find_direction_when_stop();


/** @brief Decide if Down-orders should be ignored when movement is Up.
 * 
 * @return 1 if it should be ignored, 0 otherwise
*/
int check_priority_up();


/** @brief Decides if the elevator should stop, continue up or change direction.
 *  Moves up until elevator reaches floor with order. Stops, clear orders on floor and lights. Set timer.
 *  Checks if there are more orders above. If yes, continues up. 
 *  If not, checks if there are more orders below. If yes, changes direction down. Otherwise, changes state to Idle.
 * 
*/
void movement_up();


/** @brief Decide if Up-orders should be ignored when movement is Down.
 * 
 * @return 1 if it should be ignored, 0 otherwise
*/
int check_priority_down();


/** @brief Decides if the elevator should stop, continue up or change direction.
 *  Moves down until elevator reaches floor with order. Stops, clear orders on floor and lights. Set timer.
 *  Checks if there are more orders below. If yes, continues down. 
 *  If not, checks if there are more orders above. If yes, changes direction up. Otherwise, changes state to Idle.
*/
void movement_down();


/** @brief Decides queue based on current_direction.
 * If the direction is up, calls movement_up(), if direction is down, calls movement_down(). 
 * If the order is on current floor, stays on current floor, change state to Wait after set_timer().
*/
void queue_manager();


#endif