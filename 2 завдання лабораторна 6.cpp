#include <iostream>
#include <Windows.h>
#include <math.h>
#include <iomanip>
#include <cstdlib>
using namespace std;

void text()
{
    cin.clear();
    cin.ignore(32767, '\n');
}

int main(int argc, char** argv)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double x, eps;
    const double min_eps = 1e-15;
    while (true)
    {
        if (argc == 3)
        {
            x = atof(argv[1]);
            eps = atof(argv[2]);
        }
        else
        {
            while (true)
            {
                cout << "X у вашому інтервалі = ";
                cin >> x;
                cout << endl;
                if (!cin)
                {
                    cout << "x повинно бути числом, а не символом" << endl;
                    text();
                    continue;
                }
                if (x >= 1 || x <= -1)
                {
                    cout << "x не в інтервалі"<<endl;
                    text();
                    continue;
                }
                cout << "Уведіть eps =";
                cin >> eps;
                cout << endl;
                if (!cin)
                {
                    cout << "eps повинно бути числом, а не символом" << endl;
                    text();
                    continue;
                }
                if (eps < min_eps)
                {
                    cout << "eps замаленьке"<<endl;
                    text();
                    continue;
                }
                break;
            }
        }

        long double sum_for = x;
        long double sum_while = x;
        long double sum_do = x;
        double num = x;
        double n, i = 1;

        for (n = 1; fabs(num) > eps; n++)
        {
            num *= -x * x * (2 * n - 1) / (2 * n + 1);
            sum_for += num;
            if (n == 5)
                cout << "Сума перших 5 членів ряда Тейлора за допомогою цикла for: " << setprecision(25) << sum_for << endl;
        }
        cout << "Сума всіх членів ряда Тейлора за допомогою цикла for: " << setprecision(25) << sum_for << endl;
        cout << "Кількість ітерацій за допомогою цикла for: " << n - 1 << endl;

        num = x;
        n = 0;
        while (fabs(num) > eps)
        {
            num *= -x * x * (2 * n + 1) / (2 * n + 3);
            sum_while += num;
            n++;
            if (n == 5)
                cout << "Сума перших 5 членів ряда Тейлора за допомогою цикла while: " << setprecision(25) << sum_while << endl;
        }
        cout << "Сума всіх членів ряда Тейлора за допомогою цикла while: " << setprecision(25) << sum_while << endl;
        cout << "Кількість ітерацій за допомогою цикла while: " << n << endl;

        num = x;
        n = 0;
        do
        {
            num *= -x * x * (2 * n + 1) / (2 * n + 3);
            sum_do += num;
            n++;
            if (n == 5)
                cout << "Сума перших 5 членів ряда Тейлора за допомогою цикла do while: " << setprecision(25) << sum_do << endl;
        } while (fabs(num) > eps);
        cout << "Сума всіх членів ряда Тейлора за допомогою цикла do while: " << setprecision(25) << sum_do << endl;
        cout << "Кількість ітерацій за допомогою цикла do while: " << n << endl;

        cout << "\narth(x)=" << atanh(x) << endl;

        int exit;
        cout << "Якщо бажаєте продовжити, натисніть будь-яку цифру. Для виходу натисніть 0: ";
        cin >> exit;
        if (exit == 0)
            break;
    }
    return 0;
}