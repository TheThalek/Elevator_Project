/**
 * @file
 * @brief Implementation of timer on the elevator door 
 */

#ifndef __TIMER_DOT_H__
#define __TIMER_DOT_H__

#include <stdbool.h>
#include <time.h>

/** @brief Start timer
*/
void start_timer();

/** @brief Function that implements the 3 seconds countdown.
 * @return countdown executed (0). countdown ongoing (1)
*/ 
bool timer_countdown();

#endif