#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("b5.inp", "r", stdin);
    int n;
    cin >> n;
    bool found = false;
    int a;
    while (n--)
    {
        cin >> a;
        if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
        {
            found = true;
            cout << "Yes ";
            // thoát khỏi chương trình ngay khi tìm ra năm nhuận
            return 0;
        }
    }
    cout << "No";
}