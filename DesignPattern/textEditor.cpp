#include <iostream>
#include <string>
#include <memory>
// Interface for text formatting strategies
class TextFormatter {
public:
  virtual std::string format(const std::string& text) const = 0;
};

// Concrete strategy for uppercase formatting
class UppercaseFormatter : public TextFormatter {
public:
  std::string format(const std::string& text) const override {
    std::string formattedText;
    for (char c : text) {
      formattedText.push_back(std::toupper(c));
    }
    return formattedText;
  }
};

// Concrete strategy for lowercase formatting
class LowercaseFormatter : public TextFormatter {
public:
  std::string format(const std::string& text) const override {
    std::string formattedText;
    for (char c : text) {
      formattedText.push_back(std::tolower(c));
    }
    return formattedText;
  }
};

// Context class that holds the formatting strategy
class TextEditor {
private:
  std::unique_ptr<TextFormatter> formatter;

public:
  // Set the formatting strategy
  void setFormatter(std::unique_ptr<TextFormatter> formatter) {
    this->formatter = std::move(formatter);
  }

  // Apply the formatting strategy to a text
  std::string formatText(const std::string& text) const {
    if (!formatter) {
      return text;
    }
    return formatter->format(text);
  }
};

int main() {
  TextEditor editor;

  // Use uppercase formatting
  editor.setFormatter(std::make_unique<UppercaseFormatter>());
  std::string formattedText = editor.formatText("Hello, World!");
  std::cout << formattedText << std::endl; // Output: HELLO, WORLD!

  // Switch to lowercase formatting
  editor.setFormatter(std::make_unique<LowercaseFormatter>());
  formattedText = editor.formatText("HELLO, WORLD!");
  std::cout << formattedText << std::endl; // Output: hello, world!

  return 0;
}
