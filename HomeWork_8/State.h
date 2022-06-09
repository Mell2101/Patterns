#pragma once
#include <iostream>

class StateContext;

class State {
	bool coin;
	bool button;
	bool coffee;
public:

	State(bool coi = false, bool but = false, bool cof = true) : coin(coi), button(but), coffee(cof) {
		std::cout << " I don`t have a coin " << std::endl;
	};

	virtual void checkCoin(StateContext*  ) {
		std::cout << " I don`t have a coin " << std::endl;
	}

	virtual void checkButton(StateContext*) {
		std::cout << " Button didn`t pressed " << std::endl;
	}

	virtual void checkCoffee(StateContext*) {
		std::cout << " I have the coffee " << std::endl;
	}

	bool getCoin() {
		return coin;
	}

	bool getButton() {
		return button;
	}

	bool getCoffee() {
		return coffee;
	}
	
};

class StateContext {
	State* st;
public:
	StateContext(State* st) : st(st) {};

	void haveCoin() {
		//std::cout << " I have a coin " << std::endl;
		st->checkCoin(this);
	}

	void pressButton() {
	//	std::cout << " Button pressed " << std::endl;
		st->checkButton(this);
	}

	void Coffee() {
	//	std::cout << " I have the coffee " << std::endl;
		st->checkCoffee(this);
	}

	void setState(State* s) {
		std::cout << " Coins: " << s->getCoin() << "State button:" 
			<< s->getButton() << "State coffee" << s->getCoffee() << std::endl;
		delete st;
		st = s;
	}

	State* getState() {
		return st;
	}

	virtual ~StateContext() {
		delete st;
	}


};

class CoffeeState : public State {
public:
	CoffeeState() : State(false, false) {};

	void checkCoin(StateContext* state) override;
	void checkButton(StateContext* state) override;
	void checkCoffee(StateContext* state) override;
};

class ReternCoin : public State {
public:
	ReternCoin() : State(true, false) {};

	void checkCoin(StateContext* state) override;
	void checkButton(StateContext* state) override;
	void checkCoffee(StateContext* state) override;

};

class DoCoffee : public State {
public:
	DoCoffee() : State(true, true, true) {};

	void checkCoin(StateContext* state) override;
	void checkButton(StateContext* state) override;
	void checkCoffee(StateContext* state) override;

};

class EndedCoffee : public State {
public:
	EndedCoffee() : State(true, true, false) {};
};

void CoffeeState::checkCoin(StateContext* state) {
	std::cout << "I have a coin but the button didn`t pressed" << std::endl;
	state->setState(new ReternCoin);
}

void CoffeeState::checkButton(StateContext* state) {
	std::cout << "I have a coin and the button pressed" << std::endl;
	state->setState(new DoCoffee);
}

void CoffeeState::checkCoffee(StateContext* state) {
	std::cout << "Sorry! Coffee is ended" << std::endl;
	state->setState(new EndedCoffee);
}

void DoCoffee::checkCoin(StateContext* state) {
	std::cout << "Coin ended!" << std::endl;
	state->setState(new CoffeeState);
}

void DoCoffee::checkButton(StateContext* state) {
	std::cout << "Button didn`t pressed" << std::endl;
	state->setState(new CoffeeState);
}

void DoCoffee::checkCoffee(StateContext* state) {
	std::cout << "Sorry! Coffee is ended" << std::endl;
	state->setState(new EndedCoffee);
}

void ReternCoin::checkCoin(StateContext* state) {
	std::cout << "Coffee didn`t choose" << std::endl;
	state->setState(new CoffeeState);
}


