#include <iostream>
#include <Student.h>

using namespace std;

int main() //Студент, гражданин, студент должен наследоваться от жителя и иметь два дополнительных поля
{
    Student a("And", "Usa", "Ole", "09.04.2002", "place", 1);
    Citizen b("Rei", "Nov", "Gov", "01.01.2000");

    a.getInfo();
    b.getInfo();
}
