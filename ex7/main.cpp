#include <iostream>
using namespace std;

class FSMBuilder;

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

class FSMState {
public:
	FSMState() {
		transitions = nullptr;
		transitionsCount = 0;
		finalStates = nullptr;
		finalStatesCount = 0;
		initialState = State();
		errorState = State();
	}

	~FSMState() {
		doDelete();
	}

	FSMState(const FSMState& other) {
		doCopy(other);
	}

	FSMState& operator=(const FSMState& other) {
		if (this != &other) {
			doDelete();
			doCopy(other);
		}
		return *this;
	}

	void addTransition(Transition transition) {
		expandTransitions();
		transitions[transitionsCount - 1] = transition;
	}

	void addFinalState(State finalState) {
		expandFinalStates();
		finalStates[finalStatesCount - 1] = finalState;
	}

private:
	void expandTransitions() {
		int newSize = transitionsCount + 1;
		Transition * newTransitions = new Transition[newSize];
		for (int i = 0; i < transitionsCount; i++) {
			newTransitions[i] = transitions[i];
		}
		transitionsCount = newSize;
	}

	void expandFinalStates() {
		int newSize = finalStatesCount + 1;
		State * newFinalStates = new State[newSize];
		for (int i = 0; i < finalStatesCount; i++) {
			newFinalStates[i] = finalStates[i];
		}
		finalStatesCount = newSize;
	}

	void doCopy(const FSMState& other) {
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

	void doDelete() {
		delete[] transitions;
		delete[] finalStates;
	}

public:
	Transition * transitions;
	int transitionsCount;
	State * finalStates;
	int finalStatesCount;
	State initialState;
	State errorState;
};



class FSM {
public:
	void print() {
		cout << state << endl;
	}

private:
	FSM(FSMState fsmState) {
		this->fsmState = fsmState;
	}

private:
	FSMState fsmState;

	friend class FSMBuilder;
};

class FSMBuilder {
public:
	void addTransition(Transition transition) {
		fsmState.addTransition(transition);
	}

	void addFinalState(State state) {
		fsmState.addFinalState(state);
	}

	void setInitialState(State state) {
		fsmState.initialState = state;
	}

	void setErrorState(State state) {
		fsmState.errorState = errorState;
	}

	FSM build() {
		return FSM(fsmState);
	}
private:
	FSMState fsmState;
};

int main() {
	FSM fsm = FSMBuilder().build();
	fsm.print();
	return 0;
}
