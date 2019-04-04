#include <iostream>
#include "fsm.h"

void FSM::print() {
	std::cout << "FSM" << std::endl;
}

FSM::FSM(FSMState fsmState) {
	this->fsmState = fsmState;
}
