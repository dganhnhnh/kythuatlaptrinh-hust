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

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int M[3][3] = {1,2,3,4};
    // print M
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
