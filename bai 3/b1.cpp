// Nguyen Duong Anh 20210082
int lucas(int n) {
    if(n == 0) return 2;
    else if(n==1) return 1;
    return lucas(n-1) + lucas(n-2);
}
// Nguyen Duong Anh 20210082