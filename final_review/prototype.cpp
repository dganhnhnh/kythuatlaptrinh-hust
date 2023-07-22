#include <iostream>
using namespace std;
int f(int x, int y = 5);
int f(int x, int y = 8){
	cout<<x<<y<<endl;
	return (x + y);
}
int main(int argc, char const *argv[])
{
    f(3);
    return 0;
}
