// Nguyen Duong Anh 20210082
#include <stdio.h>
// in ra n
void print(int n) {
    printf("n=%d\n", n);
}
// hàm tính nếu n lẻ
int mul3plus1(int n) {
    return n * 3 + 1;
}
// hàm tính nếu n chẵn
int div2(int n) {
    return n / 2;
}
// khai báo các tham số cho các con trỏ hàm odd, even và output
void simulate(int n, int (*odd)(int), int( *even)(int), void( *output)(int))  {
    (*output)(n);
    if (n == 1) return;
    // nếu n chẵn thực hiện hàm trỏ tới bởi even
    if (n % 2 == 0) {
        n = (*even)(n);
    } else {
        // nếu n lẻ thực hiện hàm trỏ tới bởi odd 
        n = (*odd)(n);
    }
    // đệ quy
    simulate(n, odd, even, output);
}

int main() {
    // khai báo các con trỏ hàm
    int (*odd)(int) = mul3plus1;
    int (*even)(int) = div2;
    void (*output)(int) = print;
    // khai báo n và nhập từ bàn phím 
    int n;
    scanf("%d", &n);
    // thực hiện hàm simulate
    simulate(n, odd, even, output);
    return 0;
}
// Nguyen Duong Anh 20210082