// Nguyen Duong Anh 20210082
#include <stdio.h>
#include <math.h>

float get_hypotenuse(float x, float y) {
    // cạnh huyền bằng tổng bình phương cạnh góc vuông 
    return sqrt(x*x+y*y);
}
int main(){
    // khai báo và nhập vào x, y
    float x, y;
    scanf("%f%f", &x, &y);
    // tính cạnh huyền, lưu vào biến z và in ra
    float z = get_hypotenuse(x, y);
    printf("z = %.2f\n", z);
    return 0;
}
// Nguyen Duong Anh 20210082