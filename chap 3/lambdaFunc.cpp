#include<iostream>
using namespace std;

// void stdio_doing(int n){
//     n+= 10;
//     cout<< n<<" ";
// }

void forEach(int *arr, int n, void (*func)(int)){
    for(int i=0; i<n; i++){
        func(*(arr+i));
    }
}

int main(){
    int arr[] = {1,2,3,4,5};
    // forEach(arr, 5, stdio_doing);
    forEach(arr, 5, [](int a){
        a+= 10;
        cout<<a<<" ";
    });

    int m=0, n=0;
    // mệnh đề bắt giữ: lamdba truy cập vào biến trong khối lệnh chứa nó
    auto func = [&, n](int a) mutable{
        m = ++ n +a;
    };
    func(4);
    cout<<m<<" "<<n<<endl;
    
    return 0;
}