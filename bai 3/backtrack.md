#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

void print_sol(){
    
}

bool check(current_choice){

    return true;
}

//# Thuật toán quay lui
void TRY(int k){
    for(choice : choices){
        make choice 
        if(check){
            save choice
            if(no more choices) print_sol();
            else TRY(k+1);
            undo choice
        }
    }
}

<!-- cách 2 -->
void TRY(int k){
    if(k==n) print_sol();

    for(choice : choices){
        make choice 
        if(check){
            save choice
            
            TRY(k+1);
            undo choice
        }
    }
}

int main(){
        
    return 0;
}

sao để chọn ra k
lưu kết quả vào đâu: xâu, mảng, ..?