#include <iostream>

// State Interface
class TrafficLightState {
public:
	virtual void handle() = 0;
};

// Concrete States
class RedState : public TrafficLightState {
public:
	void handle() override
	{
		std::cout << "Traffic Light is Red\n";
	}
};

class YellowState : public TrafficLightState {
public:
	void handle() override
	{
		std::cout << "Traffic Light is Yellow\n";
	}
};

class GreenState : public TrafficLightState {
public:
	void handle() override
	{
		std::cout << "Traffic Light is Green\n";
	}
};

// Context
class TrafficLight {
private:
	TrafficLightState* state;

public:
	TrafficLight()
		: state(new RedState())
	{
	}

	void setState(TrafficLightState* newState)
	{
		delete state;
		state = newState;
	}

	void change() { state->handle(); }
    ~TrafficLight() {
        if(state) delete state;
    }
};

int main()
{
	TrafficLight trafficLight;

	trafficLight.change(); // Initial state: Red
	trafficLight.setState(new GreenState());
	trafficLight.change(); // State changed to Green

	return 0;
}
