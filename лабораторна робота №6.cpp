#include <iostream>
#include <cmath>
#include <iomanip> 

using namespace std;

// Функція для обчислення значення функції F(x) для першого рівняння
double equation1(double x) {
    return pow(sqrt(exp(-pow(2 + x, 2.0))), 0.2);
}

// Функція для обчислення значення функції F(x) для другого рівняння
double equation2(double x) {
    return pow(x, -25);
}

// Функція для обчислення значення функції F(x) для третього рівняння
double equation3(double x) {
    return pow(x, 30);
}

// Перевірка, чи значення x належить до вказаної області допустимих значень
bool checkDomain(int equationNumber, double x) {
    if (equationNumber == 1) {
        return (5 < x && x < 10);
    }
    else if (equationNumber == 2) {
        return (-3 < x && x <= 2);
    }
    else {
        return true;
    }
}

// Функція для обчислення значення ряду Тейлора для заданої функції
double taylorSeries(double x, int n) {
    double result = 0.0;

    // Обчислюємо ряд Тейлора для кожного члена
    for (int i = 0; i < n; ++i) {
        // Обчислюємо значення кожного члена ряду Тейлора
        double term = (2 * i + 1) * pow(x, 2 * i);
        term = term / (2 * i + 1); // Застосовуємо коефіцієнт перед x^(2n)

        // Додаємо член до загальної суми
        result += term;
    }

    return result;
}

int main() {
    int choice;
    cout << "Оберіть завдання:" << endl;
    cout << "1. Розв'язання системи рівнянь" << endl;
    cout << "2. Обчислення ряду Тейлора" << endl;
    cout << "Ваш вибір: ";
    cin >> choice;

    if (choice == 1) {
        double start, end, step;

        cout << "Введіть початкове значення діапазону: ";
        cin >> start;
        cout << "Введіть кінцеве значення діапазону: ";
        cin >> end;
        cout << "Введіть крок зміни аргументу: ";
        cin >> step;

        int equationNumber;
        cout << "Введіть номер рівняння (1, 2 або 3): ";
        cin >> equationNumber;

        cout << "Значення функції F(x) для рівняння " << equationNumber << ":" << endl;
        cout << setw(25) << "X" << setw(25) << "F(X)" << endl; // Заголовки столбцов
        for (double x = start; x <= end; x += step) {
            if (checkDomain(equationNumber, x)) {
                double result;
                switch (equationNumber) {
                case 1:
                    result = equation1(x);
                    break;
                case 2:
                    result = equation2(x);
                    break;
                case 3:
                    result = equation3(x);
                    break;
                }
                cout << setw(25) << fixed << setprecision(3) << x << setw(25) << fixed << setprecision(3) << result << endl; // Вывод значений в таблице
            }
            else {
                cout << "Значення x = " << x << " не належить до області допустимих значень для рівняння " << equationNumber << endl;
            }
        }
    }
    else if (choice == 2) {
        double x = 0.0; // Значення x
        int n = 3; // Кількість членів ряду Тейлора, що беруться у розрахунок
        cout << "Уведіть х =";
        cin >> x;
        double taylor_result = taylorSeries(x, n);

        cout << "Значення ряду Тейлора для x = " << x << ": " << taylor_result << endl;
    }
    else {
        cout << "Неправильний вибір! Будь ласка, введіть 1 або 2." << endl;
    }

    return 0;
}