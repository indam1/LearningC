#include <Matrix.h>

int main()  //Матрица, вывести первую и вторую матрицу с произвольными элементами,
            //третью с максимальными значениями из первой и второй, отсортировать главную диагональ
{
    Matrix mat;

    mat.getFirst();
    mat.getSecond();
    mat.getThird();
    mat.sortMainDiagonal();
    mat.getThird();
}
