#include <iostream>
using namespace std;

// truyền tham chiếu bằng con trỏ
void swap(int *x, int *y){
    int tmp = *x;
    *x =  *y;
    *y = tmp;
}

// void swap(int &x, int &y){ 
//     int tmp = x;
//     x =  y;
//     y = tmp;
// }

int x = 4;
int &myFunc(){
    return x;
}

void myDelay(int a, long loops = 1000, long start=0){
    for (int i=start; i<loops; ++i);
    cout<<a;
}

int main(){
    int a=3; int b=4;
    swap(&a, &b);
    // swap(a, b);
    printf("a:%d, b:%d", a,b);

    // cout<<"x: ";
    // // khi hàm trả về 1 tham chiếu, ta có thể gọi hàm bên trái phép gán
    // myFunc() = 20;
    // cout<< "x: ";

    // myDelay(3);
    // myDelay(3,5000);
    return 0;
}