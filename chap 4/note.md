# Chương 4: Tối ưu mã nguồn
## các kĩ thuật
- dư thừa tính toán
- inline function
    + thông thường: gọi chương trình con tốn overhead vì cất/khôi phục ngữ cảnh và chuyển hướng đk
    + inline thường dùng cho hàm nhỏ
    + compiler chèn code của hàm đó vào địa chỉ nó đc gọi 
    + tránh dùng stack
    + khai triển
- macros
- biến tĩnh trong chương trình con 
    + giúp tránh side effects 
- static, stack, heap 
- lính canh 
- vd tính sigmoid
    + //# hàm tính sigmoid(x) nhanh sigmoid_fast(x)
    ```
    inline double sigmoid_fast(double x) {
        if(x < start) return 0.0;
        if(x > stop) return 1.0;

        int i = floor((x - start) / denta);

        return sigmoid[i] + ((sigmoid[i+1] - sigmoid[i]) * (x - start - i*denta)) / (denta);
    }
    ```
- số thực dấu phẩy động 
    + float thay vì double
    + x*0.5 thay vì x/2.0
    + tránh dùng sin, exp, log
    + mảng 1 chiều > nhiều chiều
    + tránh dùng đệ quy
- khác
    + kích thước mảng = bội của 2
    + switch: các giá trị case trong phạm vi hẹp; case thường gặp lên trên
    + switch lồng nhau
    + biến cục bộ: hạn chế; khai báo trong phạm vi nhỏ nhất có thể
    + hạn chế số tham số hàm
    + tham chiếu nếu > 4 byte
    + void 
    + khởi tạo biến thay vì gán
    + dùng ds khởi tạo trong hàm khởi tạo 

## quy tắc
- tăng tốc độ
- lặp
    + đưa code ra ngoài vòng lặp
    + loop fusion 
    + thay đổi đk kết thúc vòng lặp (lính gác,... ); càng ít kiểm tra càng tốt 
