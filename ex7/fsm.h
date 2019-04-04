#ifndef FSM_H_INCLUDED
#define FSM_H_INCLUDED

#include "fsmState.h"

class FSMBuilder;

class FSM {
public:
	void print();

private:
	FSM(FSMState fsmState);

private:
	FSMState fsmState;

	friend class FSMBuilder;
};

#endif