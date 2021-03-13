/**
 * @file
 * @brief Library for the implementation of the initialization of the elevator. 
 */



#ifndef __INITIALIZE_DOT_H__
#define __INITIALIZE_DOT_H__


#include "hardware.h"
#include "orders.h"
#include "lights.h"



#include <stdbool.h>


/**
 * @brief Function for initializing the elevator. If the elevator is in an undefined state (between floors), it will move up to the closest defined state. The function also deletes previous orders and clears all lights
*/
void initialize();


#endif
