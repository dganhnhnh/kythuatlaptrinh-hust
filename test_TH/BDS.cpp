// function overriding or templates??
#include <iostream>
#include <cstring>
using namespace std;

struct MiengDat
{
    char maSo[5];
    char hinhDang[10];
    int donGia;
    double dienTich;
    double thanhTien;
    double giamGiaPhanTram;
    double datCocPhanTram;
};

struct CongTy
{
    char ten[30];
    char diaChi[50];
    int soMiengDat;
    MiengDat dsMiengDat[50];
};

CongTy dsCongTy[50];
int soCongTy;
int choice;

// don gia, dat coc
void docMaSo(MiengDat &md)
{
    // todo: array of ma so
    if (strcmp(md.maSo, "MD001") == 0)
    {
        md.donGia = 50;
        cout << "Don gia: " << md.donGia;
        md.datCocPhanTram = 0.7;
    }
    if (strcmp(md.maSo, "MD002") == 0)
    {
        md.donGia = 30;
        cout << "Don gia: " << md.donGia;
        md.datCocPhanTram = 0.5;
    }
    if (strcmp(md.maSo, "MD003") == 0)
    {
        md.donGia = 10;
        cout << "Don gia: " << md.donGia;
        md.datCocPhanTram = 0.3;
    }
}

// prompt va tinh dien tich luon
double tinhDienTich(MiengDat &md)
{
    cout << "\nMieng dat hinh: ";
    char hinh[10];
    cin >> hinh;
    double S;
    if (strcmp(hinh, "HCNhat") == 0)
    {
        cout << "Chieu dai: ";
        double cd;
        cin >> cd;
        cout << "Chieu rong: ";
        double cr;
        cin >> cr;
        S = cd * cr;
    }
    if (strcmp(hinh, "Thang") == 0)
    {
        cout << "Day lon: ";
        double dl;
        cin >> dl;
        cout << "Day nho: ";
        double dn;
        cin >> dn;
        cout << "Chieu cao: ";
        double cc;
        cin >> cc;
        S = (dl + dn) * cc / 2;

        md.giamGiaPhanTram = 0.1;
    }
    if (strcmp(hinh, "Tamgiac") == 0)
    {
        cout << "Day: ";
        double d;
        cin >> d;
        cout << "Chieu cao: ";
        double cc;
        cin >> cc;
        S = d * cc / 2;

        md.giamGiaPhanTram = 0.1;
    }
    if (strcmp(hinh, "Vuong") == 0)
    {
        cout << "Canh: ";
        int c;
        cin >> c;
        S = c * c;
    }
    md.dienTich = S;
    cout << "Dien tich: " << md.dienTich;
    strcpy(md.hinhDang, hinh);
    return S;
}

MiengDat luuMiengDat()
{
    MiengDat md;
    cout << "\nNhap ma so: ";
    cin >> md.maSo;
    md.datCocPhanTram = 0;
    md.giamGiaPhanTram = 0;
    docMaSo(md);
    tinhDienTich(md);
    md.thanhTien = md.dienTich * md.donGia;
    cout << "\nThanh tien: " << md.thanhTien;
    cout << "\nDat coc: " << md.thanhTien * md.datCocPhanTram;
    cout << "\nGiam gia: " << md.thanhTien * md.giamGiaPhanTram;
    return md;
}

CongTy luuCongTy()
{
    CongTy ct;
    cout << "\nDia chi: ";
    cin >> ct.diaChi;
    cout << "So mieng dat: ";
    cin >> ct.soMiengDat;
    // loop de nhap lan luot het cac mieng dat
    for (int i = 0; i < ct.soMiengDat; i++)
    {
        ct.dsMiengDat[i] = luuMiengDat();
    }
    return ct;
}

// truyen tham tri
void tinhToanBDSCongTy(CongTy ct)
{
    // duyet danh sach 1 lan, dua ra cac so lieu tong, trung binh, ..
    double donGiaTB, tongDT, tongTT, tongDC, tongGG;

    for (int i = 0; i < ct.soMiengDat; i++)
    {
        donGiaTB += ct.dsMiengDat[i].donGia;
        tongDT += ct.dsMiengDat[i].dienTich;
        tongTT += ct.dsMiengDat[i].thanhTien;
        tongDC += ct.dsMiengDat[i].datCocPhanTram * ct.dsMiengDat[i].thanhTien;
        tongGG += ct.dsMiengDat[i].giamGiaPhanTram * ct.dsMiengDat[i].thanhTien;
    }
    donGiaTB /= ct.soMiengDat;
    cout << "Don gia trung binh: " << donGiaTB;
    cout << "\nTong dien tich: " << tongDT;
    cout << "\nTong thanh tien: " << tongTT;
    cout << "\nTong dat coc: " << tongDC;
    cout << "\nTong giam gia: " << tongGG;
}

void hienThiMiengDat(CongTy ct)
{
    cout << "\nHien thi mieng dat" << endl;
    cout << "MaMD\tHinh\t\tDon gia\tDien tich\tThanh tien\tGiam gia\tDat coc" << endl;
    for (int i = 0; i < ct.soMiengDat; i++)
    {
        cout << ct.dsMiengDat[i].maSo
             << "\t" << ct.dsMiengDat[i].hinhDang
             << "\t" << ct.dsMiengDat[i].donGia
             << "\t" << ct.dsMiengDat[i].dienTich
             << "\t\t" << ct.dsMiengDat[i].thanhTien
             << "\t\t" << ct.dsMiengDat[i].giamGiaPhanTram*ct.dsMiengDat[i].thanhTien
             << "\t\t" << ct.dsMiengDat[i].datCocPhanTram*ct.dsMiengDat[i].thanhTien
             << endl;
    }
}

void handleInput()
{
    cout << "Nhap so cong ty: ";
    cin >> soCongTy;
    for (int i = 1; i <= soCongTy; i++)
    {
        dsCongTy[i] = luuCongTy();
    }
}

void handleOutput()
{
    cout << "Xuat" << endl;
    for (int i = 1; i <= soCongTy; i++)
    {
        cout << "Cong ty " << i << endl;
        tinhToanBDSCongTy(dsCongTy[i]);
        hienThiMiengDat(dsCongTy[i]);
    }
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
    cin >> choice;
    switch (choice)
    {
    case 1:
        handleInput();
        break;
    case 2:
        handleOutput();
        break;
    case 3:
        handleExit();
        break;
    default:
        cout << "Invalid choice " << choice << endl;
        break;
    }
}

int main()
{
    while (choice != 3)
    {
        prompt();
    }
}