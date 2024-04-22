#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <math.h>
#include <cstdlib>
float F(float x)
	{float y;
	if (5 < x && x < 10)
			{
				y = pow(sqrt(exp(-pow(2 + x, 2.0))), 0.2);
			}
			else if (-3 < x && x <= 2)
			{
				y = pow(x, -25);
			}
			else
			{
				y = pow(x, 30);
			}
			return y;
		}
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

	while (true)
	{
		double x_start, x_end, stop, x;

		if (argc == 4)
		{
			x_start = atof(argv[1]);
			x_end = atof(argv[2]);
			stop = atof(argv[3]);
		}
		else
		{
			while (true)
			{
				cout << "Введіть початкове значення інтервалу :";
				cin >> x_start;
				if (!cin)
				{
					cout << "Початкове значення має бути числом " << endl;
					text();
					continue;

				}
				cout << "Введіть кінцеве значення :";
				cin >> x_end;
				if (!cin)
				{
					cout << "Кінцеве значення має бути числом" << endl;
					text();
					continue;

				}
				cout << "Введіть значення кроку :";
				cin >> stop;
				if (!cin)
				{
					cout << "Значення кроку має бути числом" << endl;
					text();
					continue;

				}
				if (stop == 0)
				{
					cout << "Крок не може дорівнювати 0, введіть додатнє число" << endl;
					text();
					continue;
				}
				else if (stop < 0)
				{

					cout << "Крок не може бути від'ємним, введіть додатнє число" << endl;
					text();
					continue;
				}
				else if (x_start >= x_end)
				{
					cout << "Початкове значення повинно бути строго меншим за кінцеве" << endl;
					text();
					continue;
				}
				else break;
			}
		}
		long double y;
		cout << "________________________________________________" << endl;
		cout << setw(10) << "x" << setw(10) << "|" << setw(10) << "y" << endl;
		for (x = x_start; x <= x_end; x += stop)
		{
			if (abs(x) < 0.0000000000001) {
				cout << "________________________________________________" << endl;
				cout << setw(10) << "0" << setw(10) << "|" << setw(10) << "не входить у діапазон" << endl;
				continue;
			}
			else y =F(x);
			
			cout << setw(10) << x << setw(10) << "|" << setw(15) << y << endl;
		}int exit = -1;
		cout << "Якщо бажаєте продовжити натисніть будь-яку цифру, якщо хочете вийти натисніть 0 :";
		cin >> exit;
		if (exit == 0)
		{
			break;
		}

	}

	return 0;
}
