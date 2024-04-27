#include<iostream>
#include<vector>

//Handler Interface
class Handler {
 public:
  virtual Handler *SetNext(Handler *handler) = 0;
  virtual std::string Handle(const std::string& request) = 0;
};

//Base Handlers
class BaseHandlers : public Handler {
    private:
        Handler *next_handler;
    public:
        BaseHandlers() : next_handler(nullptr) {}
        Handler *SetNext(Handler* handler) override {
            this->next_handler = handler;
            return handler;
        }
        std::string Handle(const std::string& request) override {
            if(this->next_handler) {
                this->next_handler->Handle(request);
            }
        }
};


//MonekyHandlers (Concrete Handlers)
class MonkeyHandler : public BaseHandlers {
    public:
        std::string Handle(const std::string& request) override {
            if(request=="banana") {
                return "Money: I will eat banana!";
            }
            else BaseHandlers:Handle(request);
        }
};

//BirdHandlers (Concrete Handlers)
class BirdHandler : public BaseHandlers {
    public:
        std::string Handle(const std::string& request) override {
            if(request=="nut") {
                return "Bird: I will eat nut!";
            }
            else BaseHandlers:Handle(request);
        }
};

//LionHandlers (Concrete Handlers)
class LionHandler : public BaseHandlers {
    public:
        std::string Handle(const std::string& request) override {
            if(request=="meat") {
                return "Lion: I will eat meat!";
            }
            else BaseHandlers:Handle(request);
        }
};

//TigerHandlers (Concrete Handlers)
class TigerHandler : public BaseHandlers {
    public:
        std::string Handle(const std::string& request) override {
            if(request=="meat") {
                return "Tiger: I will eat meat!";
            }
            else BaseHandlers:Handle(request);
        }
};


void Client(Handler &handler) {
    std::vector<std::string> food = {"nut", "banana", "meat"};
    for (const std::string &f : food) {
        std::cout << "Client: Who wants a " << f << "?\n";
        const std::string result = handler.Handle(f);
        if (!result.empty()) {
            std::cout << "  " << result;
        } 
        else {
            std::cout << "  " << f << " was left untouched.\n";
        }
    }
};


int main() {
    MonkeyHandler* monkey = new MonkeyHandler;
    BirdHandler* bird = new BirdHandler;
    LionHandler* lion = new LionHandler;
    TigerHandler* tiger = new TigerHandler;
    tiger->SetNext(bird)->SetNext(lion)->SetNext(monkey);


    Client(*tiger);
    delete monkey;
    delete bird;
    delete lion;
    delete tiger;
    return 0;
}