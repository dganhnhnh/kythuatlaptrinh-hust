// Nguyen Duong Anh 20210082
#include <iostream>
#include <cmath>
#include <iomanip>
#include <tuple>
using namespace std;
using Vector = tuple<double, double, double>;

Vector cross_product(Vector a, Vector b)
{
    auto [a1, a2, a3] = a;
    auto [b1, b2, b3] = b;
    Vector c;
    auto [c1, c2, c3] = c;
    c1 = a2 * b3 - a3 * b2;
    c2 = a3 * b1 - a1 * b3;
    c3 = a1 * b2 - a2 * b1;
    get<0>(c) = c1;
    get<1>(c) = c2;
    get<2>(c) = c3;
    return c;
}

int main()
{
    cout << setprecision(2) << fixed;
    Vector a{1.2, 4, -0.5};
    Vector b{1.5, -2, 2.5};
    Vector c = cross_product(a, b);
    cout << get<0>(c) << ' ' << get<1>(c) << ' ' << get<2>(c) << endl;
    return 0;
}
// Nguyen Duong Anh 20210082