#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int **mt; int R=2,C=3;
    mt=new int *[R];
    for (int i = R-1; i >=0; i--)
    {
        mt[i]=new int [C];
        // cấp phát cho các hàng từ dưới lên
        // --> không liên tiếp nhau trong bộ nhớ
    }
    return 0;
}
