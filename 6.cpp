#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
    int choice;
    cout << "Оберіть завдання:" << endl;
    cout << "1. Розрахунок функції F(x)" << endl;
    cout << "2. Таблиця значень функції" << endl;
    cout << "Ваш вибір: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        double i;
        double x, sum; // Аргумент функції, сума ряду
        double term; // Поточне значення члена ряду
        double eps; // Межа точності
        int n; // Кількість ітерацій

        cout << "Розрахунок функції F(x)\n\n";
        cout << "Введіть значення x: ";
        cin >> x;
        cout << "Введіть межу точності (eps): ";
        cin >> eps;

        sum = x; // Початкове значення суми ряду
        term = x; // Перший член ряду

        for (i = 2, n = 1; fabs(term) > eps; i += 2, n++) {
            term *= (-x * x) / (i * (i + 1)); // Обчислення наступного члена ряду
            sum += term; // Додавання члена до суми
            if (n == 5) {
                cout << "Сума перших 5 членів ряду = " << setprecision(18) << sum << endl;
            }
        }

        cout << setprecision(18) << "Сума ряду = " << sum << " Кількість ітерацій = " << n << endl;
        cout << "F(x) = " << sum << endl;
        break;
    }
    case 2: {
        double xn, xk, shag, y;

        cout << "Введіть xn, xk, крок: \n";
        cin >> xn >> xk >> shag;

        cout << "|-----------|-----------------|\n";
        cout << "|     x     |        y        |\n";
        cout << "|-----------|-----------------|\n";

        for (double x = xn; x <= xk; x += shag) {
            if (5 < x && x < 10)
                y = pow(sqrt(exp(-pow(2 + x, 2.0))), 0.2);
            else if (-3 < x && x <= 2)
                y = pow(x, -25);
            else
                continue;

            cout << "| " << setw(9) << fixed << setprecision(3) << x << " | " << setw(15) << y << " |\n";
        }

        cout << "|-----------|-----------------|\n";
        break;
    }
    default:
        cout << "Неправильний вибір! Будь ласка, введіть 1 або 2." << endl;
        break;
    }

    return 0;
}