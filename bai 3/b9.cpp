// Nguyễn Dương Ánh 20210082
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

int n,k1,k2;
int *schedule;  // mảng để chứa giá trị ngày làm việc (1) và ngày nghỉ (0)
int streak = 0; // chuỗi ngày làm việc liên tiếp

void print_sol(){
    for(int i=0; i<n;i++){
        cout<<schedule[i]<<" ";
    }
    cout<<"\n";
}

bool check(int prev, int current, int dayNumber){
    if (prev == 0 && current == 0 ) return false;                               // không được có 2 ngày nghỉ liên tiếp 
    else if (prev == 1 && streak < k1 && current == 0) return false;            // chưa đủ số ngày làm tối thiểu
    else if (streak >= k2 && current ==1) return false;                         // quá số ngày làm tối đa
    else if (dayNumber == n-1 && current == 1 && streak <k1-1) return false;    // đến ngày cuối nhưng chưa đủ số ngày làm tối thiểu
    return true;
}
// ## Thuật toán quay lui
void TRY(int k){
    for(int i = 0; i < 2; i++){
        int current = i;
        int prevStreak = streak;

        // cout<< "dayNumber: "<<k<<" current: "<< current << " streak: "<<streak<<"\n";
        if(check(schedule[k-1],current, k)){
            if(i==1) streak ++;
            else if(i==0) streak =0;
            // cout<< "dayNumber: "<<k<<" current: "<< current << " streak: "<<streak<<"\n";

            schedule[k] = current;
            if(k==n-1) print_sol();     // nếu thử đến cuối rồi thì in ra 
            else TRY(k+1);

            // khôi phục chuỗi trước đó 
            streak = prevStreak;
        }
    }
}

int main(){
    cin>> n>>k1>>k2;
    // cấp phát động cho schedule[]
    schedule=(int*)malloc(n * sizeof(int));

    for (int i=0; i<=1; i++){
        schedule[0] = i;
        streak = i;
        TRY(1);
    }
    return 0;
}
// Nguyễn Dương Ánh 20210082