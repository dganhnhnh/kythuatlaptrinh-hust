// Nguyen Duong Anh 20210082
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void rotate(int &x, int &y, int &z)
{
    // khai báo biến tmp, dùng tmp làm biến trung gian để đổi chỗ x,y,z
    int tmp;
    tmp = x;
    x = y;
    y = z;
    z = tmp;
}

int main()
{
    // khai báo và nhập vào x,y,zz
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    printf("Before: %d, %d, %d\n", x, y, z);
    // gọi hàm rotate để đổi chỗ x,y,z và in ra
    rotate(x, y, z);
    printf("After: %d, %d, %d\n", x, y, z);

    return 0;
}
// Nguyen Duong Anh 20210082