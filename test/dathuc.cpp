// Nguyen Duong Anh 20210082
#include <iostream>
#include <conio.h>
#include<cmath>
using namespace std;

    typedef struct DaThuc{
        char ten;
        int bac;
        // mảng chứa hệ số bậc i của đa thức ở vị trí thứ i
        int heSo[10];
        double x;

        // Hàm tính giá trị của đa thức tại giá trị x đã cho
        double calcDT(){
            double result;
            for(int i=this->bac; i>= 0; i--){
                result+= this->heSo[i]*pow(this-> x,i);
            }
            return result;
        }
    } DT;

int choice=-1, soLuong;
DT dsDT[100];

void handleInput(int thuTu){
    DT dt;
    cout<<"Nhap ten da thuc: ";
    cin>> dt.ten;
    cout<<"Nhap bac: ";
    cin>> dt.bac;
    cout<<"Nhap x: ";
    cin >> dt.x;
    // khởi tạo hệ số bằng 0 cho tất cả các bậc
    for(int i=10; i> dt.bac; i--){
        dt.heSo[i]=0;
    }
    // nhập hệ số các bậc từ bàn phím
    for(int i=dt.bac; i>= 0; i--){
        cout<< "He so bac "<<i<<": ";
        cin >> dt.heSo[i];
    }
    dsDT[thuTu] = dt;
}

void handleOutput(int thuTu){
    DT dt = dsDT[thuTu];
    // in ra đa thức
    cout<< "\nDa thuc: "<< dt.ten << "(x) = " ;
    // in hệ số bậc lớn nhất 
    if(dt.heSo[dt.bac] != 0)  cout << dt.heSo[dt.bac]<<"*x^"<< dt.bac;

    // in hệ số bậc từ bậc lớn nhất -1 đến 2
    for(int i=dt.bac-1; i>1; i--){
        if(dt.heSo[i] > 0)  cout << " +";
        if(dt.heSo[i] != 0) 
            cout<< " " << dt.heSo[i]<<"*x^"<< i;
    }
    // in hệ số bậc 1
    if(dt.heSo[1] > 0)  cout << " +";
    if(dt.heSo[1] != 0) cout<< " " << dt.heSo[1]<<"*x";
    // in hệ số bậc 0
    if(dt.heSo[0] > 0)  cout << " +";
    if(dt.heSo[0] != 0) cout<< " " << dt.heSo[0];
    
    // tính giá trị đa thức tại x
    cout<< "\nGia tri da thuc: "<<dt.ten<<"("<<dt.x<<") = "<<dt.calcDT();
}

void prompt()
{
    cout << "\nNguyen Duong Anh - 20210082 - 2022.2 - 727635" << endl;
    cout << "** CHUONG TRINH QUAN LY CAC DA THUC **" << endl;
    cout << "** 1. Nhap cac da thuc, gia tri x **" << endl;
    cout << "** 2. In danh sach da thuc va gia tri \n";
    cout << "** 0. Thoat **";
    cout <<"*******************************\n**   Nhap lua chon cua ban   **\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        // nếu người dùng chọn 1 thì nhập ds đa thức và x
        cout<< "Ban da chon nhap DS da thuc! "<<endl;
        for(int i=0; i<soLuong; i++){
            handleInput(i);
        }
        break;
    case 2:
        // nếu người dùng chọn 2 thì xuất ds đa thức và x
        cout<< "Ban da chon xuat DS da thuc, Gia tri da thuc! "<<endl;
        for(int i=0; i<soLuong; i++){
            handleOutput(i);
        }        
        break;
    case 0:
        // nếu người dùng chọn 0 thì thoát 
        cout<< "Ban da chon thoat chuong trinh! ";
        break;
    default:
        // nếu người dùng chọn khác 0,1,2 thì báo không hợp lệ 
        cout << "Lua chon khong hop le! " << endl;
        break;
    }
}

int main()
{
    cout << "\nNguyen Duong Anh - 20210082 - 2022.2 - 727635" << endl;
    cout << "Nhap so luong da thuc: ";
    cin >> soLuong;
    
    while(choice!= 0){
        prompt();
        if(choice == 0) break;
        cout<< "\nBam phim bat ky de tiep tuc";
        _getch();
    }
}
// Nguyen Duong Anh 20210082