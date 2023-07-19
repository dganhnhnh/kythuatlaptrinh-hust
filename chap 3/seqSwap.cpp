#include <iostream>
using namespace std;

bool ascending(int l, int r){
    return l<r;
}

bool descending(int l, int r){
    return l>r;
}

// truyền con trỏ hàm vào làm tham số
void selectionSort(int *arr, int length, bool (*compare)(int, int)){
    for(int i=0; i<length; i++){
        int minIndex= i;
        for(int j=i+1; j<length; j++){
            // con trỏ hàm được gọi ở đây, cú pháp như gọi hàm 
            if(compare(arr[minIndex], arr[j]))
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main(){
    int arr[] = {3,2,1,4,5};
    selectionSort(arr, 5, ascending);
    for(int i=0; i<5; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    selectionSort(arr, 5, descending);
    for(int i=0; i<5; i++)
        cout<<arr[i]<<" ";
    return 0;
}