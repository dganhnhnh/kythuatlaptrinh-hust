#include<iostream>
using namespace std;

auto maxVal (auto x, auto y){
    return (x>y)? x : y;
}
auto add(int a, int b){
    return a+b;
}

int main(){
    cout<<maxVal(3,4)<<endl;
    cout<<maxVal(3.0,4.0)<<endl;
    return 0;
}