#include<iostream>
using namespace std;

typedef struct {
    double real;
    double img;
} SP;

SP SetSP (double real, double img){
    SP sp;
    sp.real = real;
    sp.img = img;
    return sp;
}

void DisplaySP(SP sp){
    string sign = sp.img > 0 ? " + " : " - ";
    cout<<sp.real<<sign<<abs(sp.img)<<"i"<<endl;
};

SP operator+(SP sp1, SP sp2){
    SP sp;
    sp.real = sp1.real + sp2.real;
    sp.img = sp1.img + sp2.img;
    return sp;
};
SP operator-(SP sp1, SP sp2){
    SP sp;
    sp.real = sp1.real - sp2.real;
    sp.img = sp1.img - sp2.img;
    return sp;
};

int main(){
    SP sp1 = SetSP(1,2);
    SP sp2 = SetSP(3,-4);
    DisplaySP(sp1);
    DisplaySP(sp2);
    SP sp3 = sp1 + sp2;
    SP sp4 = sp1 - sp2;
    DisplaySP(sp3);
    DisplaySP(sp4);
    return 0;
}