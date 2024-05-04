#include <iostream>
#include <Employee.h>
#include <map>
#include <algorithm>

using namespace std;

int main() //Сотрудник, расположить их по убыванию зарплаты и убыванию возраста
{
    Employee f("A", "U", "O", 18, "j", 50);
    Employee s("N", "S", "L", 20, "m", 100);
    Employee t("D", "A", "E", 19, "s", 150);

    map<int, Employee, greater<int>> age;
    map<double, Employee, greater<double>> salary;

    age.emplace(f.getAge(), f);
    age.emplace(s.getAge(), s);
    age.emplace(t.getAge(), t);

    salary.emplace(f.getSalary(), f);
    salary.emplace(s.getSalary(), s);
    salary.emplace(t.getSalary(), t);

    cout << "AGE:\n";
    for(auto it = age.begin(); it != age.end(); it++)
        (it->second).getInfo();

    cout << "\nSALARY:\n";

    for(auto it = salary.begin(); it != salary.end(); it++)
        (it->second).getInfo();

    return 0;
}
