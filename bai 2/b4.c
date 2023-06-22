// Nguyen Duong Anh 20210082
#include <stdio.h>
// hàm tính lập phương với kiểu dữ liệu số nguyên
int cube(int x) {
    return x*x*x;
}
// hàm tính lập phương với kiểu dữ liệu số thực
double cube(double x) {
    return x*x*x;
}
int main() {
    // khai báo số nguyên n, số thực f và nhậo vào từ bàn phím 
    int n;
    double f;
    scanf("%d %lf", &n, &f);
    // gọi hàm tính lập phương kiểu int
    printf("Int: %d\n", cube(n));
    // gọi hàm tính lập phương kiểu double
    printf("Double: %.2lf\n", cube(f));
    return 0;
}
// Nguyen Duong Anh 20210082