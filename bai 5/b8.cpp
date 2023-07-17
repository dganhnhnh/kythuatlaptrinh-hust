#include <bits/stdc++.h>

using namespace std;

int w, h;
int table[601][601];    // mảng chứa giá trị lãng phí nhỏ nhất khi cắt tại vị trí i, j

void init() {
    for (int i=1; i<=h; i++) {
        for (int j=1; j<=w; j++) {
            table[i][j] = i*j;
            // lãng phí = diện tích miếng cắt đi 
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();

    // int w, h, m;
    // không khai báo lại w,h vì init không cập nhật biến cục bộ của main
    int m;
    cin >> w >> h;
    cin >> m;
    init();

    for (int i=0; i<m; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        // miếng khớp chiều dài và rộng nên không bị phí  
        table[tmp2][tmp1] = 0;
    }

    //dp
    // duyệt chiều dài và chiều rộng của miếng gạch
    for (int i=1; i<=h; i++) {
        for (int j=1; j<=w; j++) {
            int minWaste = table[i][j];
            // horizonal cut
            for(int k=1; k<=i; k++) {
                minWaste = min(minWaste, table[k][j] + table[i-k][j]);
            }
            // vertical cut
            for (int k=1; k<=j; k++) {
                minWaste = min(minWaste, table[i][k] + table[i][j-k]);
            }
            table[i][j] = minWaste;
        }
    }
    // tổng lãng phí nhỏ nhất = lãng phí nhỏ nhất khi cắt miếng gạch h*w
    cout << table[h][w] << endl;
}
