// 11 общая

#include <iostream>

using namespace std;

class Shape {
protected:
    double dimension = 0;

    Shape(double dimension) {
        this->dimension = dimension;
    }

    virtual double area() = 0;
};

class Rectangle : public Shape {
private:
    double height = 0;

public:
    Rectangle(double width, double height) : Shape(width) {
        this->height = height;
    }

    virtual double area() {
        return dimension * height;
    }
};

class Square : public Shape {
public:
    Square(double side) : Shape(side) {}

    virtual double area() {
        return dimension * dimension;
    }
};

class Circle : public Shape {
public:
    Circle(double radius) : Shape(radius) {}

    virtual double area() {
        return dimension * dimension * 3.14;
    }
};

int main() {
    double rectangle_width;
    double rectangle_height;
    double square_side;
    double circle_radius;

    setlocale(LC_ALL, "Russian");

    cout << "Введите сторону a прямоугольника\n";
    cin >> rectangle_width;
    cout << "Введите сторону b прямоугольника\n";
    cin >> rectangle_height;
    cout << "Введите сторону квадрата\n";
    cin >> square_side;
    cout << "Введите радиус круга\n";
    cin >> circle_radius;

    Rectangle rectangle(rectangle_width, rectangle_height);
    Square square(square_side);
    Circle circle(circle_radius);

    cout << "Остаток: "
         << rectangle.area() - square.area() - circle.area() << endl;

    return 0;
}
