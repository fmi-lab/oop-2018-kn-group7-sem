#include "fsm.h"
#include "fsmBuilder.h"

int main() {
	FSM fsm = FSMBuilder().build();
	fsm.print();
	return 0;
}
