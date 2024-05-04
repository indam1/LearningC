#include <iostream>

#include <Square.h>
#include <Trapezoid.h>
#include <Rectangle.h>
#include <Circle.h>

using namespace std;

int main() //—оздать род. класс ‘игура, наследовать от нее разнообразные фигуры и вывести их площадь и периметр
{
    Shape shape;
    Circle circle(5);
    Quadrangle quad;
    Rectangle rect(5, 10);
    Square square(10);
    Trapezoid trap(5, 10, 2);

    cout << circle.area() << " " << circle.perimeter() << endl
     << rect.area() << " " << rect.perimeter() << endl
     << square.area() << " " << square.perimeter() << endl
     << trap.area() << " " << trap.perimeter() << endl;
}
