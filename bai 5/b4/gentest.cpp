#include <bits/stdc++.h>
using namespace std;

int random(int L, int H)
{
    return (rand() << 16 | rand()) % (H - L + 1) + L;
}

void printFullPath(int n, int amax, int amin)
{
    int m = n * (n - 1);
    cout << n << " " << m << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
                cout << i << " " << j << " " << random(amin, amax) << endl;
        }
    }
}

void printRandPath(int n, int amax)
{
    int m = random(1, n * (n - 1));
    cout << n << " " << m << endl;
    for (int i = 1; i <= m; i++)
    {
        cout << random(1, n) << " " << random(1, n) << " " << random(1, amax) << endl;
        // chưa xét trùng
    }
}

int main(int argc, char **argv)
{
    if (argc > 1)
        srand(atoi(argv[1]));
    else
        srand(time(NULL));
    freopen("tsm2.inp", "w", stdout);

    int n = random(2, 5);
    int amax = 10000000;
    int amin = 1000;

    printFullPath(n, amax, amin);
}