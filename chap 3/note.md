- truyền tham chiếu theo 2 cách
- tham số ngầm định
- đa năng hóa hàm 
- đa năng hóa toán tử
    + không thể định nghĩa toán tử mới
    + một số toán tử không thể đa năng hóa
    + không thể thay đổi số lượng toán hạng của toán tử
    + không thể thay đổi ưu tiên của toán tử
- con trỏ hàm
    + seqSwap.cpp (đa năng hóa hàm nữa?)
- khái quát hóa hàm
```
template <typename T>
T maxval (T a, T b) {
    return (a > b) ? a : b;
}
```
- auto
- lamnda
    + mệnh đề bắt giữ: lamdba truy cập vào biến trong khối lệnh chứa nó
    + ds tham số
    + tính bền vững
    + ngoại lệ
    + kiểu trả về
    + phần thân 