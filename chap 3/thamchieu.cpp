#include <stdio.h>
// #include <iostream>
// using namespace std;

// void swap(int *x, int *y){
//     int tmp = *x;
//     *x =  *y;
//     *y = tmp;
// }

// truyen tham chieu
void swap(int &x, int &y){
    int tmp = x;
    x =  y;
    y = tmp;
}

int main(){
    int a=3; int b=4;
    // swap(&a, &b);
    swap(a, b);
    printf("a:%d, b:%d", a,b);
}