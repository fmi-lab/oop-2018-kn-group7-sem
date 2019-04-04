#include "fsmBuilder.h"

void FSMBuilder::addTransition(Transition transition) {
	fsmState.addTransition(transition);
}

void FSMBuilder::addFinalState(State state) {
	fsmState.addFinalState(state);
}

void FSMBuilder::setInitialState(State state) {
	fsmState.initialState = state;
}

void FSMBuilder::setErrorState(State errorState) {
	fsmState.errorState = errorState;
}

FSM FSMBuilder::build() {
	return FSM(fsmState);
}
