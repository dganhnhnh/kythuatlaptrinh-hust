// Nguyen Duong Anh 20210082
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    // khai báo val1, val2 và nhập từ bàn phím 
    int val1, val2;
    cin >> val1 >> val2;
    // vector 2 chiều a
    vector< vector<int> > a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };
// sắp xếp vector a theo thứ tự lấy từ giá trị boolean trả về từ hàm nặc danh [](vector<int> x, vector<int> y)
sort(a.begin(), a.end(), [](vector<int> x, vector<int> y){
            int sum1 = 0;
            // tính tổng các phần tử của vecotr x
            for (unsigned int i=0; i<x.size(); i++){
               sum1+= x[i];
            }
            // tính tổng các phần tử của vecotr x
            int sum2 = 0;
            for (unsigned int i=0; i<y.size(); i++){
               sum2+= y[i];
            }
            // so sánh tổng sum1 với sum2, nếu sum1 > sum2 thì giữ nguyên vị trí 2 phần tử của a, ngược lại đổi chỗ chúng cho nhau
            return sum1 > sum2;
         }
);
// duyệt vector a 
    for (const auto &v : a) {
        // duyệt từng vector trỏ tới bởi v 
        for (int it : v) {
        //   in ra phần tử của vector 
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// Nguyen Duong Anh 20210082