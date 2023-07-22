#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    long total=100, x, *arr;
    printf("Nhap n = "); scanf("%d",&n);
    arr = new long [n];
    if (arr==NULL) {
        printf("Cap phat khong thanh cong\n");
        exit(1);
    }
    for (int i=0; i < n; i++){
        printf("\n Vao so thu %d: ", i+1 );
        scanf("%d", &arr[i] );
    }
    printf("Danh sach cac so: \n");
    for (int i=0; i < n; i++) printf("%d ", arr[i]);
    delete [] arr;
    return 0;
}
