#ifndef __STATE_DOT_H__
#define __STATE_DOT_H__

typedef enum State {Idle, Move, Wait, Stop} state;

void state_idle();

void state_wait();

void state_stop();

void state_move();

#endif


