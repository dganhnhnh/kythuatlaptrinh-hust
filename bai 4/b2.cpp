// Nguyen Duong Anh 20210082
#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
using namespace std;
using Point = pair<double, double>;

double area(Point a, Point b, Point c) {
    /*****************
    # YOUR CODE HERE #
    *****************/
   double AB = sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2));
   double BC = sqrt(pow(b.first-c.first,2)+pow(b.second-c.second,2));
   double CA = sqrt(pow(c.first-a.first,2)+pow(c.second-a.second,2));
   double s = (AB+BC+CA)/2;
   return sqrt(s*(s-AB)*(s-BC)*(s-CA));
}

int main() {
    cout << setprecision(2) << fixed;
    cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
    return 0;
}
// Nguyen Duong Anh 20210082