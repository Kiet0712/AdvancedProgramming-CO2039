#include<iostream>
using namespace std;

// Abstraction: Shape
class Shape {
public:
	virtual void draw() = 0;
};
// Implementations: Color (Red and Blue)
class Color {
public:
	virtual void show_color() = 0;
};

class Red : public Color {
public:
	void show_color() override {
		std::cout << "Red\n";
	}
};

class Blue : public Color {
public:
	void show_color() override {
		std::cout << "Blue\n";
	}
};
class Circle : public Shape {
public:
	Circle(Color& color) : color(color) {}

	void draw() override {
		std::cout << "Drawing a circle ";
		color.show_color();
	}

private:
	Color& color;
};

class Square : public Shape {
public:
	Square(Color& color) : color(color) {}

	void draw() override {
		std::cout << "Drawing a square ";
		color.show_color();
	}

private:
	Color& color;
};
int main() {
    Red red;
    Blue blue;
 
    Circle circle(red);
    Square square(blue);
 
    circle.draw();
    square.draw();
 
    return 0;
}