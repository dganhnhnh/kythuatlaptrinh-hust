#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;

struct HocVien
{
    char maHV[10];
    char hoTenHV[50];
    int soMonHoc;
    int soTienHoc;
    int tienHoc;

    int soTienDaNop;
    int soTienHocPhaiDong;
    char loaiGio[10];
    char khoiLuong[10];
};

struct MonHoc{
    //  MaMH, sotinchiLT, sotichiBT, SotinchiTH, sotichihocphi
    char maMH[10];
    int soTinChiLT;
    int soTinChiBT;
    int soTinChiTH;
    int soTinChiHocPhi;
};

int choice;
void prompt()
{
    cout << "** CHUONG TRINH QUAN LY HOC PHI **" << endl;
    cout << "** 1. Nhap cac sinh vien va mon hoc **" << endl;
    cout << "** 2. In ds sinh vien va hoc phi cac mon \n";
    cout << "** 0. Thoat **";
    cout <<"*******************************\n**   Nhap lua chon cua ban   **\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        // nhapDSDT();
        break;
    case 2:
        // inDSDT();
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
        cout << "Bam phim bat ky de tiep tuc";
        _getch();
    }
}