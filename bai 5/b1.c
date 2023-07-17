#include <stdio.h>

int x[100];     // mảng chứa hoán vị
int mark[100];  // mảng đánh dấu phần tử đã sử dụng  
int n;

void print_sol(){
    // in ra hoán vị tìm được
    for (int i = 1; i <= n; ++i) printf("%d ", x[i]);
    // print("\n");
    printf("\n");
}

void process(int i) {
    if (i > n){
        print_sol();
        return;
    }
    for (int j = 1; j <= n; ++j)
        // nếu phần tử đó dùng được, đánh dấu nó rồi đưa vào mảng x, thử với pt tiếp theo 
        if (!mark[j]){
            mark[j] = 1;
            x[i] = j;
            process(i+1);
            // khôi phục đánh dấu 
            mark[j] = 0;
        }
}

int main() {
    n = 5;
    process(1);
    return 0;
}