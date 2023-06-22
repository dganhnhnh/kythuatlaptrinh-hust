// Nguyen Duong Anh 20210082
#include <iostream>
using namespace std;
// định nghĩa hàm khái quát hóa arr_sum với kiểu dữ liệu T
template <typename T> 
T arr_sum(T a[],int a_size, T b[], int b_size){
   T result=0;
//   tổng các phần tử của a
   for(int i=0; i<a_size; i++){
      result+= a[i];
   }
//   tổng các phần tử của b 
   for(int i=0; i<b_size; i++){
      result+= b[i];
   }
   return result;
}
int main() {
    int val;
    cin >> val;
    // khai báo mảng a,b kiểu int trong khối lệnh và tỉnh tổng 
    {
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }   
    // khai báo mảng a,b kiểu double trong khối lệnh và tỉnh tổng 
    {
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }
    return 0;
}
// Nguyen Duong Anh 20210082