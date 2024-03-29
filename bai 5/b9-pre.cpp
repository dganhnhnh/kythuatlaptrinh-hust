#include <bits/stdc++.h>
using namespace std;
typedef struct {
    int x, y, z;
} block;
int n;
block a[100];
int maxh[100];

void input(){
    cin >> n;
    if (n == 0) exit(0);
    int x, y, z;
    for (int i = 1; i <= n; i++){
        cin >> x >> y >> z;
        a[3 * i - 2].x = x;
        a[3 * i - 2].y = y;
        a[3 * i - 2].z = z;
        a[3 * i - 1].x = y;
        a[3 * i - 1].y = z;
        a[3 * i - 1].z = x;
        a[3 * i].x = z;
        a[3 * i].y = x;
        a[3 * i].z = y;
    }
}

int dp(int i){//Tim chieu cao cua toa thap voi dinh la vien i
    cout<< "maxh[" << i << "] = " << maxh[i] << endl;
    if (maxh[i] != 0) return maxh[i];
    maxh[i] = a[i].z;
    for(int j = 1; j <= n; j++){
        // nếu viên j lót được vào dưới viên i
        if (a[i].x < a[j].x && a[i].y < a[j].y || 
            a[i].x < a[j].y && a[i].y < a[j].x){

            maxh[i] = max (maxh[i], a[i].z + dp(j));
            // cout<< "maxh[" << i << "] = " << maxh[i] << endl;
        }
    }
    return maxh[i];
}
 
int main(){
    int cnt = 1;
    while(1){
        int res = 0;
        input();
        // // in để kiểm tra dữ liệu đã được nhập đúng chưa
        // for(int i = 1; i <= 3 * n; i++){
        //     cout<< a[i].x << " " << a[i].y << " " << a[i].z << endl;
        // }
        for(int i = 1; i <= 3 * n; i++){
            res = max(res, dp(i));
        }
        printf("Case %d: maximum height = %d\n", cnt++, res);
    }
    return 0;
}