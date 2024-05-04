#include <Rectangle.h>

using namespace std;

int main() //Прямоугольник, проверить, входит ли в первый квадрант, является ли прямоугольником и квадратом, вывести длину, ширину, периметр, площадь.
{
    Coord coord[4] = {{0, 0},{3, 0},{0, 3},{3, 3}};
    Rectangle abc(coord);
    for(int i = 0; i < 4; i++)
        cout << "Pair " << i + 1 << "   X:" << abc.getX(i) << ", Y:" << abc.getY(i) << endl;

    abc.checkSquare();
    cout << endl << "Length: " << abc.length() << "\nWidth: " <<  abc.width() << "\nPerimeter: " << abc.perimeter() << "\nArea: " << abc.area() << endl;
    return 0;
}
