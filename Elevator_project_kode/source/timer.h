/**
 * @file
 * @brief Implementation of timer on the elevator door 
 */

#ifndef __TIMER_DOT_H__
#define __TIMER_DOT_H__

#include <stdbool.h>
#include <time.h>

/** @brief Starts timer. 
 * Sets a variable equal to the current time, by calling the function time(NULL). 
*/
void start_timer();

/** @brief Implementation of the 3 seconds countdown.
 * Checks if the difference between the current time and the start time is higher or lower than the time limit. 
 * If higher, it has reached the time limit and returns 1.
 * If lower, returns 0
 * @return countdown executed (1). countdown ongoing (0)
*/
bool timer_countdown();

#endif