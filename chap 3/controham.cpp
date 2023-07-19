#include <iostream>
using namespace std;

// int foo(){
//     return 0;
// }

// int (*pFoo)() = foo;
// int main(){
//     // pFoo = foo;
//     cout<<pFoo();
//     return 0;
// }

void swapValue(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

int main(){
    int a = 3;
    int b = 4;
    void (*pSwapValue)(int &, int &) =swapValue;
    pSwapValue(a,b);
    cout<<a<<b;
    return 0;
}