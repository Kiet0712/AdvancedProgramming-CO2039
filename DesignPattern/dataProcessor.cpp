#include <iostream>

// Base class with the template method
class DataProcessor {
public:
  virtual void processData() {
    openFile();
    extractData();
    analyzeData();
    closeFile();
  }

protected:
  virtual void openFile() = 0; // Abstract step
  virtual void extractData() = 0; // Abstract step
  void analyzeData() {
    // Default implementation shared by subclasses
    std::cout << "Analyzing extracted data..." << std::endl;
  }
  virtual void closeFile() = 0; // Abstract step
};

// Subclass with specific implementations
class TextProcessor : public DataProcessor {
protected:
  void openFile() override {
    std::cout << "Opening text file..." << std::endl;
  }
  void extractData() override {
    std::cout << "Extracting text data..." << std::endl;
  }
  void closeFile() override {
    std::cout << "Closing text file..." << std::endl;
  }
};

int main() {
  TextProcessor textProcessor;
  textProcessor.processData();
  return 0;
}
