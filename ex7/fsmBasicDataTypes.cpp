
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
