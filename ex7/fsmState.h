#ifndef FSMSTATE_H_INCLUDED
#define FSMSTATE_H_INCLUDED

#include "fsmBasicDataTypes.h"

class FSMState {
public:
	FSMState();
	~FSMState();
	FSMState(const FSMState& other);
	FSMState& operator=(const FSMState& other);
	void addTransition(Transition transition);
	void addFinalState(State finalState);

private:
	void expandTransitions();
	void expandFinalStates();
	void doCopy(const FSMState& other);
	void doDelete();

public:
	Transition * transitions;
	int transitionsCount;
	State * finalStates;
	int finalStatesCount;
	State initialState;
	State errorState;
};

#endif