#include <iostream>
#include <string>
#include "windows.h"

using namespace std;

struct StudentDebt {
    string Surname;
    int debtCount;
    string subject;
};

void print_all_students(StudentDebt* students, int num) {
    cout << "\n Повний список студентів \n";
    for (int i = 0; i < num; i++) {
        cout << i + 1 << ". Прізвище: " << students[i].Surname
            << " | Кількість заборгованостей: " << students[i].debtCount
            << " | Предмет: " << students[i].subject << endl;
    }
}

void sort_debts(StudentDebt* students, int num) {
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (students[j].debtCount > students[j + 1].debtCount) {
                StudentDebt temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int num;
    cout << "Введіть кількість студентів: ";
    cin >> num;

    StudentDebt* students = new StudentDebt[num];

    for (int i = 0; i < num; i++) {
        cout << "\nВведіть дані для студента № " << i + 1 << endl;
        cout << "Прізвище: ";
        cin >> students[i].Surname;
        cout << "Кількість заборгованостей: ";
        cin >> students[i].debtCount;
        cout << "Предмет заборгованості: ";
        cin >> students[i].subject;
    }

    print_all_students(students, num);

    sort_by_debts(students, num);

    cout << "\n Список студентів у порядку зростання заборгованостей \n";
    for (int i = 0; i < num; i++) {
        cout << "Прізвище: " << students[i].Surname
            << " (Боргів: " << students[i].debtCount
            << ", Предмет: " << students[i].subject << ")" << endl;
    }
    delete[] students;
}