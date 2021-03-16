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

/** @brief Enum for the different states in the state machine.
  */
typedef enum State {
    Idle, ///< Elevator is idle on a defined floor with the doors closed, waiting for new orders.
    Move, ///< Elevator moves, according to the queue.
    Wait, ///< The door closes after the timer is expired.
    StopFloor, ///< The elevator stops on defined floor, if stop button is pushed. 
    StopShaft, ///< The elevator stops between floors, if stop button is pushed.
} state;


/** @brief Sets the variable current_state = new_state.
 * 
 * @param [in] new_state 
*/
void set_current_state(state new_state);


/** @brief Initializes the elevator.
 * If the elevator is in an undefined floor, when the program starts, it moves up until it reaches a defined floor.
*/
void state_init();


/** @brief Reads the stop-signal button and determines the new state.
 * If current_postion() is on undefined floor, current_state = StopShaft.
 * If current_postion() is on defined floor, current_state = StopFloor.
*/
void read_stop_signal();


/** @brief Elevator stands still on defined floor with doors closed,
 * Continuously look for new orders. 
 * If new order, sets start direction, before changing the state to Move.
*/
void state_idle();


/** @brief Opens the door, when the timer expires, closes door.
 * If obstruction signal is active, the door stays open.
 * If the timer expires when the current_direction = 0, the state goes to Idle. Otherwise it goes to Move.
*/
void state_wait();


/** @brief Stop button is activated when the elevator is on defined floor.
 * The stop light is turned on and the doors are opened. All pevious orders are cleared.
 * When the stop-button is released the stop light turns off.
 * The door closes after the timer is expired.
*/
void state_stop_floor();


/** @brief Stop button is activated when the elevator is on undefined floor.
 * The stop light is turned on. All previous orders are cleared.
 * When the stop-button is released the stop light turns off and the elevator stands still until a new order is placed.
 * A new direction is chosen. New state = move.
*/
void state_stop_shaft();


/** @brief Elevator is moving.
 * The movement is decided by queue_manager();
*/
void state_move();


/** @brief Implementation of the state machine.
 * The lights and orders are updated. The stop-button is checked. The chosen switch case is run. 
*/
void state_run();

#endif


