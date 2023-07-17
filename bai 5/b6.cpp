#include <bits/stdc++.h>
using namespace std;

int A = 0, B = 0, C = 0, D = 0, F = 0;

// thay vì so sánh string để cập nhật biến cục bộ thì cập nhật luôn vào biến toàn cục 
void cal(double a){
    if (a < 4) ++F;
    if (4 <= a && a < 5.5) ++D;
    if (5.5 <= a && a < 7) ++C;
    if (7 <= a && a < 8.5) ++B;
    if (8.5 <= a) ++A;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        cal(a);
    }
    cout << A << " " << B << " " << C << " " << D << " " << F;
}