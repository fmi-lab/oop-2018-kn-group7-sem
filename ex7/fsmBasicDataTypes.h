#ifndef FSM_BASIC_DATA_TYPES_H_INCLUDED
#define FSM_BASIC_DATA_TYPES_H_INCLUDED

struct State {
	State() {
		id = 0;
	}

	int id;
};

struct Input {
	int value;
};

struct Transition {
	State from;
	Input input;
	State to;
};

#endif