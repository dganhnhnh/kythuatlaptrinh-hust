#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    // cout << "So thon: ";
    cin >> n;
    int ans = 0, sum = 0;
    while (n--)
    {
        int k, t;
        // cout << "So nha, co giau khong: ";
        cin >> k >> t;
        // kiểm tra thôn trước, tránh lặp nhiều lần kiểm tra
        if (t == 1)
        {
            while (k--)
            {
                int a;
                // cout << "So tien: ";
                cin >> a;
                sum += a;        
                ans = max(ans, -sum);

            }
        }
        else
        {while (k--)
            {int a;
                // cout << "So tien: ";
                cin >> a;
                sum -= a;
                ans = max(ans, -sum);
            }
        }
    }
    cout << ans;
}