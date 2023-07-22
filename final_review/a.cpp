// #include <iostream>
// using namespace std;

// int main(int argc, char const *argv[])
// {
//     int a =8;
//     cout << a && 1;
//     return 0;
// }
// __________________________________________________________

// #include <iostream>
// #include <math.h>
// using namespace std;

// double mySqrt(double d){
//     if( d <0.0) throw "cannot";
//     else return sqrt(d);
// }

// int main(int argc, char const *argv[])
// {
//     double d=5;
//     cout<< mySqrt(d);
//     return 0;
// }
// __________________________________________________________

// #include <iostream>
// using namespace std;

// int main(int argc, char const *argv[])
// {
//     char a[6] = {'H', 'a', 'n', 'o', 'i'};
//     char b[6] = "Hanoi";
//     cout << "a >= b " << (a <= b) << endl;
//     cout << "a == b " << (a == b) << endl;
//     cout << "a < b " << (a < b) << endl;
//     cout << "a > b " << (a > b) << endl;
//     return 0; 
// }
// __________________________________________________________


// #include <iostream>

// int value = 42;

// // Function returning a reference to an integer
// int& getReference() {
//     return value;
// }

// int main() {
//     int& refValue = getReference();
//     getReference() = 100;
//     // refValue = 100;

//     std::cout << "Value: " << value << std::endl; // Output: Value: 100

//     return 0;
// }

// __________________________________________________________

// #include <iostream>
// using namespace std;

// int main(int argc, char const *argv[])
// {
//     int a=1,b=2;
//     (a=b) = 3;
//     // a=b gán b vào a rồi trả về a
//     cout<< a << " " << b;

//     // vd khác về biểu thức
//     int x = 10;      // x là một biến và là một l-value
//     int y = x + 5;   // x + 5 là một biểu thức (r-value), có thể xuất hiện bên phải của phép gán
//     y = 20;         // 20 là một giá trị không thể thay đổi (r-value), có thể xuất hiện bên phải của phép gán

//     return 0;
// }

// __________________________________________________________

// #include <iostream>
// using namespace std;

// int main(int argc, char const *argv[])
// {
//     int M[3][3] ={1,2,3,4,5,6,7,8,9};
//     // int n[]={1,2,3};
//     // int m[][]={1,2,3};

//     // M = {1,2,3,4};
//     cout << 2[M][1];

//     int x=5; 
//     return 0;
// }
// __________________________________________________________

// #include <iostream>
// #include <algorithm>
// using namespace std;

// int main(int argc, char const *argv[])
// {
//     int sum=0.0;
//     float m[100][3];
//     fill_n(&m[0][0], 100 * 3, 1);

//     // float *p=&m[0][0];
//     for (int i = 0; i < 300; ++i) {
//         // cout<<*(p+i)<<" ";
//         sum += *(m+i);
//     }
//     cout<<sum;

//     return 0;
// }

// __________________________________________________________
// #include <iostream>
// using namespace std;
// int main(int argc, char const *argv[])
// {
//     char *s;
//     s = "Hello";
//     s+=3;
//     cout<<s;
//     return 0;
// }

// __________________________________________________________

// #include <iostream>
// using namespace std;

// inline int vd(int x,int y){
//     static int a =10;
//     return (x>a || y)? x-a+y++ : x+y;
// }

// int main(int argc, char const *argv[])
// {
//     // int m=5,n=8;
//     // cout << vd(m,n);
//     long** arr = new long*[10];
//     // long crr = new long[10];
//     return 0;
// }
// __________________________________________________________

#include <iostream>
// #include <assert.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int x=5,y=10,*p,*q;
    p=q=&x;
    // p=(q=&x);
    *q=6;
    cout<< *p;
    // assert(x>10);
    return 0;
}