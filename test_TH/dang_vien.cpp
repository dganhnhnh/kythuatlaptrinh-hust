#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;

struct ChiBo
{
    char tenCB[50];
    char diaChi[50];
    int soDangVien;
    double tongLuong;
    double tongDangPhiThu;
};

struct DangVien{
    char soTheDV[10];
    char tenDV[50];
    int namVaoDang;
    char chucVuDang[50];
    double luong;
    double dangPhi;
    double tienPhuCap;
    double phaiDong;
};

int choice;
void prompt()
{
    cout << "** CHUONG TRINH QUAN LY CHI BO - DANG VIEN **" << endl;
    cout << "** 1. Nhap Cac Chi bo **" << endl;
    cout << "** 2. In Ket qua danh sach chi bo, dang vien \n";
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