#include <bits/stdc++.h>
#include <conio.h>
#include <vector>
#include <iostream>

using namespace std;

// int outerChoice;

struct DaThuc
{
    char ten[20];
    int thuTu;
    int bac;
    int heSo[10];
};

vector<DaThuc> danhSachDaThuc;
// sửa để dùng malloc
int x;
int soLuong;

void handleInput()
{
    cout << "Input" << endl;
    int thuTu = danhSachDaThuc.size() + 1;
    cout << "Nhap dt thu " << thuTu;
    cout << "Nhap ten da thuc: ";
    DaThuc dt;
    cin >> dt.ten;
    cout << "Nhap bac da thuc: ";
    cin >> dt.bac;
    cout << "Nhap x: ";
    cin >> x;
    for (int i = dt.bac; i >= 0; i--)
    {
        cout << "He so bac " << i << ": ";
        cin >> dt.heSo[i];
    }
    dt.thuTu = thuTu;
    danhSachDaThuc.push_back(dt);
}

void outputSingle(DaThuc dt)
{
    if (dt.heSo[dt.bac] != 0)
    {
        cout << dt.heSo[dt.bac] << "x^" << dt.bac;
    }
    // in ra từ bậc n-1 đến 1
    for (int i = dt.bac - 1; i > 0; i--)
    {
        if (dt.heSo[i] != 0)
        {
            if (dt.heSo[i] > 0)
            {
                cout << "+";
            }
            cout << dt.heSo[i] << "x^" << i;
        }
    }
    if (dt.heSo[0] != 0)
    {
        if (dt.heSo[0] > 0)
            cout << "+";
        cout << dt.heSo[0];
    }
    cout << "\n";
}

void handleOutput()
{
    cout << "Output" << endl;
    // for (auto it = danhSachDaThuc.begin(); it!= danhSachDaThuc.end(); it++){
    for (int j = 0; j < danhSachDaThuc.size(); j++)
    {
        DaThuc dt = danhSachDaThuc[j];
        outputSingle(dt);
    }
}

int calc(DaThuc dt)
{
    int result = 0;
    for (int i = dt.bac; i >= 0; i--)
    {
        result += dt.heSo[i] * pow(x, i);
    }
    return result;
}

DaThuc sumOfPolynomials()
{
    DaThuc result;
    // cout<<danhSachDaThuc.size();
    for (int i = 0; i <= 10; i++)
    {
        result.heSo[i] = 0;
    }

    int bacMax = danhSachDaThuc[0].bac;
    for (int j = 0; j < danhSachDaThuc.size(); j++)
    {
        if (bacMax < danhSachDaThuc[j].bac)
            bacMax = danhSachDaThuc[j].bac;
        for (int i = 0; i <= 10; i++)
        {
            if (i > danhSachDaThuc[j].bac)
                danhSachDaThuc[j].heSo[i] = 0;
        }
    }

    for (int i = 0; i <= 10; i++)
    {
        for (int j = 0; j < danhSachDaThuc.size(); j++)
        {
            if (i > bacMax)
                break; // van de
            int heSo = danhSachDaThuc[j].heSo[i];
            // cout << "\nhe so: " << heSo;
            result.heSo[i] += heSo;
        }
    }
    for (int i = 10; i >= 0; i--)
    {
        if (result.heSo[i] != 0)
        {
            result.bac = i;
            break;
        }
    }
    return result;
}

void handleExit()
{
    cout << "Exit" << endl;
}

void prompt()
{
    cout << "\n1. Input" << endl;
    cout << "2. Output" << endl;
    cout << "3. Exit" << endl;
    cout << "Your choice: ";
    int choice;
    cin >> choice;
    // outerChoice = choice;
    switch (choice)
    {
    case 1:
        handleInput();
        // break;
    case 2:
        handleOutput();
        // handleInput();
        DaThuc sum;
        sum = sumOfPolynomials();
        cout << "sum: ";
        outputSingle(sum);
        break;
    case 3:
        handleExit();
        break;
    default:
        cout << "Invalid choice " << choice << endl;
        break;
    }
}
// TODO program loop

int main()
{
    cout << "Nhap so luong da thuc: ";
    cin >> soLuong;
    
    prompt();
    // while(outerChoice!= 3){
    //     prompt();
    //     cout<< "Bam phim bat ky de tiep tuc";
    //     _getch();
    // }
}