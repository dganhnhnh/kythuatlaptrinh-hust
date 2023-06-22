// Nguyen Duong Anh 20210082
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

// tính toán hàm ax^2+bx+c dùng các tham số ngầm định 
int get_value(int x, int a=2, int b=1, int c=0){
    return a*x*x+b*x+c;
}

int main(){
    // khai báo và nhập x từ bàn phím
    int x;
    scanf("%d", &x);
    int a = 2; //# giá trị mặc định của a
    int b = 1; //# giá trị mặc định của b
    int c = 0; //# giá trị mặc định của c
    //# Nhập 3 số nguyên a, b, c từ bàn phím
    scanf("%d %d %d", &a,&b,&c);
    // tính hàm với toàn bộ giá trị mặc định
    printf("a=2, b=1, c=0: %d\n", get_value(x));
    // tính hàm với giá trị mặc định b và c 
    printf("a=%d, b=1, c=0: %d\n", a, get_value(x, a));
    // tính hàm với giá trị mặc định c 
    printf("a=%d, b=%d, c=0: %d\n", a, b, get_value(x, a, b));
    // tính hàm với toàn bộ giá trị tự truyền vào 
    printf("a=%d, b=%d, c=%d: %d\n", a, b, c, get_value(x, a, b, c));
    return 0;
}
// Nguyen Duong Anh 20210082