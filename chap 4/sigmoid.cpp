#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include<iostream>
using namespace std;
// khai báo các biến LIMIT, NUM_ITER(số lần chạy), NUM_INPUTS(số đầu vào)
const int LIMIT = 100;
const int NUM_ITER = 100000;
const int NUM_INPUTS = NUM_ITER * 100;
// hàm tính chậm sigmoid 
double sigmoid_slow(double x) {
    return 1.0 / (1.0 + exp(-x));
}
double x[NUM_INPUTS];
// chuẩn bị đầu vào
void prepare_input() {
    const int PRECISION = 1000000;
    const double RANGE = LIMIT / 20.0;
    for (int i = 0; i < NUM_INPUTS; ++i) {
        x[i] = RANGE * (rand() % PRECISION - rand() % PRECISION) / PRECISION;
    }
}

//# BEGIN fast code

//# khai báo các biến phụ trợ cần thiết
#define MAX_N 100000
#define denta 0.0001
double sigmoid[MAX_N];
const double start = -5.0;
const double stop = 5.0;

//# hàm chuẩn bị dữ liệu
void precalc() {
    double foo = start;
    for(int i=0; i<MAX_N; i++){
        sigmoid[i] = sigmoid_slow(foo);
        foo += denta;
    }
}

//# hàm tính sigmoid(x) nhanh sigmoid_fast(x)
inline double sigmoid_fast(double x) {
    if(x < start) return 0.0;
    if(x > stop) return 1.0;

    int i = floor((x - start) / denta);

    return sigmoid[i] + ((sigmoid[i+1] - sigmoid[i]) * (x - start - i*denta)) / (denta);

}

int main() {
    prepare_input();
    precalc();

    vector<double> a, b;

    double xval;
    scanf("%lf", &xval);
    printf("%.2f \n", sigmoid_fast(xval));

    return 0;
}