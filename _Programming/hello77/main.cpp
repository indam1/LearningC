#include <iostream>
#include <Circle.h>
#include <Rectangle.h>
#include <Square.h>
#include <Trapezoid.h>
using namespace std;

int main() //Абстрактный класс фигура, остальные фигуры наследуются от него, вывести площадь и периметр
{
    Shape *shapes[4];
    Circle circle(5);
    Rectangle rect(10, 5);
    Square square(10);
    Trapezoid trap(5, 10, 2);
    shapes[0] = &circle;
    shapes[1] = &rect;
    shapes[2] = &square;
    shapes[3] = &trap;


    for(int i = 0; i < 4; i++)
        cout << shapes[i]->area() << " " << shapes[i]->perimeter() << endl;
}
