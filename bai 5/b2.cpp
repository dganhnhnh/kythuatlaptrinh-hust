#include <iostream>
using namespace std;

int n, M;
int m[100], v[100]; // m: trong luong, v: gia tri
int x[100], best;
int sumV, sumM; // sumV: tong gia tri, sumM: tong trong luong
int all[100]; // all[i]: tong gia tri cua cac do vat tu i den n

void init(){
    for (int i = n; i >= 1; --i){
        all[i] = all[i+1] + v[i];
    }
}

void print() {
    cout << best;
}

void process(int i){
    // nếu tổng giá trị nhỏ hơn kỉ lục cũ hoặc tổng trọng lượng > giới hạn túi thì không cập nhật kỉ lục
    if (sumV + all[i] <= best || sumM > M) return;
    // nếu dòng if trên không đúng và đủ số lượng đồ vật thì cập nhật kỉ lục 
    if (i > n){
        best = sumV;
        return;
    }
    // chuyển sang xét đồ vật tiếp theo mà không lấy đồ vật hiện tại
    process(i+1);
    // chuyển sang xét đồ vật tiếp theo sau khi lấy đồ vật hiện tại
    sumM += m[i];
    sumV += v[i];
    process(i+1);
    // khôi phục lại trạng thái trước khi lấy đồ vật hiện tại 
    sumM -= m[i];
    sumV -= v[i];
}

int main() {
    cin >> n >> M;
    for (int i = 1; i <= n; ++i)
        cin >> m[i] >> v[i];
    init();
    process(1);
    print();
    return 0;
}