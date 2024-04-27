#include<iostream>
using namespace std;

class Computer {

private:
	string cpu_;
	string ram_;
	string storage_;
public:
	void setCPU(const std::string& cpu) {
		cpu_ = cpu;
	}

	void setRAM(const std::string& ram) {
		ram_ = ram;
	}

	void setStorage(const std::string& storage) {
		storage_ = storage;
	}

	void displayInfo() const {
		std::cout << "Computer Configuration:"
				<< "\nCPU: " << cpu_
				<< "\nRAM: " << ram_
				<< "\nStorage: " << storage_ << "\n\n";
	}
};
class Builder {
public:
	virtual void buildCPU() = 0;
	virtual void buildRAM() = 0;
	virtual void buildStorage() = 0;
	virtual Computer getResult() = 0;
};
class GamingComputerBuilder : public Builder {
private:
	Computer computer_;

public:
	void buildCPU() override {
		computer_.setCPU("Gaming CPU");
	}

	void buildRAM() override {
		computer_.setRAM("16GB DDR4");
	}

	void buildStorage() override {
		computer_.setStorage("1TB SSD");
	}

	Computer getResult() override {
		return computer_;
	}
};
class AITrainComputerBuilder : public Builder{
private:
    Computer computer_;
public:
	void buildCPU() override {
		computer_.setCPU("AI TRAINING CPU");
	}

	void buildRAM() override {
		computer_.setRAM("128GB DDR4");
	}

	void buildStorage() override {
		computer_.setStorage("20TB SSD");
	}

	Computer getResult() override {
		return computer_;
	}
};
class ComputerDirector {
public:
    void construct(Builder& builder) {
        builder.buildCPU();
        builder.buildRAM();
        builder.buildStorage();
    }
};

// Client
int main() {
	GamingComputerBuilder gamingBuilder;
	ComputerDirector director;

	director.construct(gamingBuilder);
	Computer gamingComputer = gamingBuilder.getResult();

	gamingComputer.displayInfo();
    AITrainComputerBuilder AITRainBuilder;
    director.construct(AITRainBuilder);
    Computer AITrainComputer = AITRainBuilder.getResult();
    AITrainComputer.displayInfo();
	return 0;
}
