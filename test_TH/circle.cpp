#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;

struct Diem{
    char ten;
    double x, y,z;
};

struct DuongTron{
    Diem tam;
    double banKinh;
};

int choice;
DuongTron dsDT[100];
Diem dsDiem[300];
int n;

Diem nhap1Diem(){
    Diem X;
    cin>> X.ten;
    cout<< "x: "; cin>>X.x;
    cout<< "y: "; cin>>X.y;
    cout<< "z: "; cin>>X.z;
    return X;
}

DuongTron nhapDT(){
    DuongTron dt;
    cout<<"Ten tam duong tron: ";
    Diem tam = nhap1Diem();
    dt.tam = tam;
    
    int bk;
    do{
        cout << "Nhap ban kinh (0<R<10): ";
        cin>> bk;
    }while(bk < 0 || bk >= 10);
    dt.banKinh = bk;
    return dt;
}

void nhap3Diem(int thuTu){
    for(int i=1; i<=3; i++){
        cout<< "Ten diem "<< i<< ": ";
        Diem X= nhap1Diem();
        dsDiem[thuTu+i-1] = X;
    }
}

double chuVi(DuongTron dt){

}

void nhapDSDT(){
    cout<< "So duong tron: ";
    cin >> n;
    for (int i = 0; i < n; i++){
        dsDT[i] = nhapDT();
        nhap3Diem(3*i); 
    }
}

void inToaDo(Diem A){
    cout<< "\nToa do Diem "<< A.ten 
        << "("<<A.x<<","<<A.y<<","<<A.z<<")";
}

void inDSDT(){
    for(int i=0; i<n; i++){
        cout<< "Hinh tron tam "<<dsDT[i].tam.ten;
        cout<< "("<<dsDT[i].tam.x<<","<<dsDT[i].tam.y<<","<<dsDT[i].tam.z<<")";
        cout<< "\nBK R: "<<dsDT[i].banKinh;
        for(int j=3*i; j<3*i+3; j++){
            inToaDo(dsDiem[j]);
        }
    }
}

Diem trungDiem(Diem A, Diem B){
    Diem T;
    T.x= (A.x+B.x)/2;
    T.y = (A.y+B.y)/2;
    T.z = (A.z+B.z)/2;
    return T;
}

void tamGiac(Diem A, Diem B, Diem C){
    // toa do trong tam tam giac
    // chu vi
}

void viTriDiemDT(DuongTron dt, Diem X){
    double kc = sqrt(pow(dt.tam.x-X.x,2)+pow(dt.tam.y-X.y,2)+pow(dt.tam.z-X.z,2));
    if(kc == dt.banKinh){
        cout<< "Diem "<<X.ten<< "nam tren duong tron";
    }else if(kc < dt.banKinh){
        cout<< "Diem "<<X.ten<< "nam trong duong tron";
    }else{
        cout<< "Diem "<<X.ten<< "nam ngoai duong tron";
    }
}

void prompt()
{
    cout << "\n1. Input" << endl;
    cout << "2. Output" << endl;
    cout << "3. Exit" << endl;
    cout << "Your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        nhapDSDT();
        // break;
    case 2:
        inDSDT();
        break;
    case 3:
        // handleExit();
        break;
    default:
        cout << "Invalid choice " << choice << endl;
        break;
    }
}

int main(){
    while(choice !=3){
        prompt();
        cout << "Bam phim bat ky ";
        _getch();
    }
}