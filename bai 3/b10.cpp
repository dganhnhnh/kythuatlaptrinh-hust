// Nguyễn Dương Ánh 20210082
#include<iostream>
using namespace std;
const int MAX = 20;
int N, H;
int x[MAX];
int S[MAX]; // Xâu gốc để so sánh
int count = 0;

void input(){
    cin >> N >> H;
    for(int i=0; i<N; i++) S[i] = 0;
    for(int i=0; i<N; i++) x[i] = 0;
}

// Kiểm tra khoảng cách Hamming của 2 xâu
int check(int str1[], int str2[]){
    int lens = N;
    int count = 0;
    for(int i=0; i<lens; i++){
        if(str1[i] != str2[i]) count++;
    }
    return count;
}

bool check(int a, int i){
    return true;
}

void solution(){
    if(check(x,S) == H){
        for(int i=0; i<N; i++) cout << x[i];
        cout << endl;
    }
}

void TRY(int a){
    for(int i=0; i<=1; i++){
        x[a] = i;
        if(a == N-1) solution();
        else
            TRY(a+1);
    }
}

int main(){
    int k;
    cin >> k;
    while(k > 0){
        input();
        TRY(0);
        k--;
    }
}
// Nguyễn Dương Ánh 20210082