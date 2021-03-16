/**
 * @file
 * @brief A library for doing operations on the lights on the floor-panel
 */


#ifndef __LIGHTS_DOT_H__
#define __LIGHTS_DOT_H__


#include "hardware.h"
#include "orders.h"

/**
 * @brief Iterates through all the order-buttons. If an order button is active, which we check by using the hardware_read_order() from hardware.h, the funtion will turn the light on in said button.
*/
void set_order_lights();


/**
 * @brief Deactivate order lights on the floor specified in the parameter, by iterating through the order-buttons.
 * 
 * @param[in] floor The given floor that will have it's order-buttons lights deactivated.
 * */
void clear_order_lights(int floor);


/**
 * @brief By using clear_order_lights, this function iterates though all possible floors, deactivating the lights on all order-buttons.
*/
void clear_all_order_lights();


/**
 * @brief Activates the stop light, by calling hardware_command_stop_light(1) from hardware.h.
*/
void on_stop_light();


/**
 * @brief Deactivates the stop light, by calling hardware_command_stop_light(0) from hardware.h.
*/
void off_stop_light();


/**
 * @brief Activates the door light, by calling hardware_command_door_open(1) from hardware.h.
*/
void open_door();


/**
 * @brief Deactivates the door light, by calling hardware_command_door_open(0) from hardware.h.
*/
void close_door();

#endif



