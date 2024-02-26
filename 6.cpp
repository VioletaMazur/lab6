#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
    int choice;
    cout << "������ ��������:" << endl;
    cout << "1. ���������� ������� F(x)" << endl;
    cout << "2. ������� ������� �������" << endl;
    cout << "��� ����: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        double i;
        double x, sum; // �������� �������, ���� ����
        double term; // ������� �������� ����� ����
        double eps; // ���� �������
        int n; // ʳ������ ��������

        cout << "���������� ������� F(x)\n\n";
        cout << "������ �������� x: ";
        cin >> x;
        cout << "������ ���� ������� (eps): ";
        cin >> eps;

        sum = x; // ��������� �������� ���� ����
        term = x; // ������ ���� ����

        for (i = 2, n = 1; fabs(term) > eps; i += 2, n++) {
            term *= (-x * x) / (i * (i + 1)); // ���������� ���������� ����� ����
            sum += term; // ��������� ����� �� ����
            if (n == 5) {
                cout << "���� ������ 5 ����� ���� = " << setprecision(18) << sum << endl;
            }
        }

        cout << setprecision(18) << "���� ���� = " << sum << " ʳ������ �������� = " << n << endl;
        cout << "F(x) = " << sum << endl;
        break;
    }
    case 2: {
        double xn, xk, shag, y;

        cout << "������ xn, xk, ����: \n";
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
        cout << "������������ ����! ���� �����, ������ 1 ��� 2." << endl;
        break;
    }

    return 0;
}