#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void S(const double x, const double eps, int& n, double& s);
void A(const double x, const int n, double& a);

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    if (xp <= 0 || dx <= 0)
    {
        cout << "Ряд збігається лише при x > 0, dx > 0" << endl;
        return 1;
    }

    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << "      |"
        << setw(10) << "ln(x)" << "   |"
        << setw(7) << "S" << "     |"
        << setw(5) << "n" << "   |"
        << endl;
    cout << "-------------------------------------------------" << endl;
    x = xp;
    while (x <= xk)
    {
        S(x, eps, n, s);

        cout << "|" << setw(7) << setprecision(2) << x << "   |"
            << setw(10) << setprecision(5) << log(x) << "   |"
            << setw(10) << setprecision(5) << s << "   |"
            << setw(5) << n << "   |"
            << endl;
        x += dx;
    }
    cout << "-------------------------------------------------" << endl;

    return 0;
}

void S(const double x, const double eps, int& n, double& s)
{
    n = 0;
    double a = (x - 1) / (x + 1);   // перший доданок (без множника 2)
    s = a;
    do {
        n++;
        A(x, n, a);
        s += a;
    } while (fabs(a) >= eps);
    s *= 2;
}

void A(const double x, const int n, double& a)
{
    double q = (x - 1) / (x + 1);
    double R = q * q * (2. * n - 1) / (2. * n + 1);
    a *= R;
}