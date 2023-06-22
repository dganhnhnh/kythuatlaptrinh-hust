// Nguyen Duong Anh 20210082
#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip> 
using namespace std;
// định nghĩa struct số phức với trường phần thực và phần ảo
struct Complex {
    double real;
    double imag;
};
// cộng số phức 
Complex operator + (Complex a, Complex b) {
   Complex result;
    //   cộng các phần thực với nhau
   result.real=  a.real+b.real;
   //   cộng các phần ảo với nhau
   result.imag=  a.imag+b.imag;
   return result;
}
// trừ số phức 
Complex operator - (Complex a, Complex b) {
   Complex result;
    //   trừ  các phần thực cho nhau    
   result.real=  a.real-b.real;
   //   trừ  các phần ảo cho nhau    
   result.imag=  a.imag-b.imag;
   return result;
}
// nhân số phức 
Complex operator * (Complex a, Complex b) {
   Complex result;
    //   phần thực của kết quả là hệ số phần thực của a và b nhân với nhau, trừ đi tích hệ số phần ảo của chúng 
   result.real=  a.real*b.real - a.imag*b.imag;
   //   phần ảo của kết quả là tổng hệ số phần thực của a nhân với  phần ảo của b và ngược lại
   result.imag=  a.imag*b.real +b.imag*a.real ;
   return result;

}
// chia số phức dùng nhân liên hợp
Complex operator / (Complex a, Complex b) {
//   khai báo biến temp gồm phần thực là phần thực của b và phần ảo là đối của phần ảo của b 
   Complex temp;
   temp.real = b.real;
   temp.imag  = -b.imag;
//  nhân cả tử và mẫu của phép chia với temp và triệu tiêu phần phức ở mẫu số 
   Complex result = a*temp;
  double soChia = b.real* b.real+ b.imag*b.imag;
   result.real /= soChia;
   result.imag /= soChia;
   return result;
}
// in ra kết quả
ostream& operator << (ostream& out, const Complex &a) {
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out;
}

int main() {
    // khai báo phần thực, ảo của a,b và nhập từ bàn phím 
    double real_a, real_b, img_a, img_b;
    cin >> real_a >> img_a;
    cin >> real_b >> img_b;
    // khởi tạo số phức a, b
    Complex a{real_a, img_a};
    Complex b{real_b, img_b};
    // in ra kết quả của các phép toán
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;
    
    return 0;
}
// Nguyen Duong Anh 20210082