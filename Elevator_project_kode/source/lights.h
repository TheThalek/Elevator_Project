/**
 * @file
 * @brief Library for the implementation of lights
 */



#ifndef __LIGHTS_DOT_H__
#define __LIGHTS_DOT_H__


#include "hardware.h"
#include "orders.h"

/**
 * @brief Function that clears all the order lights (Up, Down and Inside elevator, in every floor)
*/
void clear_order_lights();



void set_lights();
void on_stop_light();
void off_stop_light();


#endif



