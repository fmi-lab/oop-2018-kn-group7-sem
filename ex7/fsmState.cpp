#include <iostream>
#include "fsmState.h"

FSMState::FSMState() {
	transitions = nullptr;
	transitionsCount = 0;
	finalStates = nullptr;
	finalStatesCount = 0;
	initialState = State();
	errorState = State();
}

FSMState::~FSMState() {
	doDelete();
}

FSMState::FSMState(const FSMState& other) {
	doCopy(other);
}

FSMState& FSMState::operator=(const FSMState& other) {
	if (this != &other) {
		doDelete();
		doCopy(other);
	}
	return *this;
}

void FSMState::addTransition(Transition transition) {
	expandTransitions();
	transitions[transitionsCount - 1] = transition;
}

void FSMState::addFinalState(State finalState) {
	expandFinalStates();
	finalStates[finalStatesCount - 1] = finalState;
}

void FSMState::expandTransitions() {
	int newSize = transitionsCount + 1;
	Transition * newTransitions = new Transition[newSize];
	for (int i = 0; i < transitionsCount; i++) {
		newTransitions[i] = transitions[i];
	}
	transitionsCount = newSize;
}

void FSMState::expandFinalStates() {
	int newSize = finalStatesCount + 1;
	State * newFinalStates = new State[newSize];
	for (int i = 0; i < finalStatesCount; i++) {
		newFinalStates[i] = finalStates[i];
	}
	finalStatesCount = newSize;
}

void FSMState::doCopy(const FSMState& other) {
	this->transitions = new Transition[other.transitionsCount];
	for (int i = 0; i < other.transitionsCount; i++) {
		this->transitions[i] = other.transitions[i];
	}
	this->transitionsCount = other.transitionsCount;

	this->finalStates = new State[other.finalStatesCount];
	for (int i = 0; i < other.finalStatesCount; i++) {
		this->finalStates[i] = other.finalStates[i];
	}
	this->finalStatesCount = other.finalStatesCount;

	this->initialState = other.initialState;
	this->errorState = other.errorState;
}

void FSMState::doDelete() {
	delete[] transitions;
	delete[] finalStates;
}
