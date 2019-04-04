#ifndef FSMBUILDER_H_INCLUDED
#define FSMBUILDER_H_INCLUDED

#include "fsmBasicDataTypes.h"
#include "fsmState.h"
#include "fsm.h"

class FSMBuilder {
public:
	void addTransition(Transition transition);
	void addFinalState(State state);
	void setInitialState(State state);
	void setErrorState(State errorState);
	FSM build();
private:
	FSMState fsmState;
};

#endif