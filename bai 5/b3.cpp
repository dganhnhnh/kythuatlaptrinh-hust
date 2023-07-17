#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
 
int par(string str){
    int a = str.length();
    stack<char> S;
    char x; 
    for (int i=0; i<a; i++){
        // đẩy từng kí tự vào stack nếu là dấu mở ngoặc
        x = str[i];
        if (x == '(' || x == '[' || x == '{'){
            S.push(x);
        }
        // nếu là dấu đóng ngoặc thì kiểm tra xem nó có đóng ngoặc mở tương ứng hay không
        else {
            // thêm: nếu không có gì trong stack mà gặp kí tự đóng ngoặc thì trả về 0 
            if (S.size() == 0) return 0;
            if (x == ')') {
                if (S.top() == '('){
                    S.pop();
                }
                else return 0;
            }
            else if (x == ']') {
                if (S.top() == '['){
                    S.pop();
                }
                else return 0;
            }
            else if (x == '}') {
                if (S.top() == '{'){
                    S.pop();
                }
                else return 0;
            }
        }
    }
    // if (S.top() != NULL){
    // sửa: so sánh độ dài stack có bằng 0 không, thay vì so sánh đầu stack với con trỏ null 
    if(S.size() != 0){
        return 0;
    }
    else return 1;
}
 
int main(){
    int n;
    string str;
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str;
        cout << par(str) << endl;
    }
    
    return 0;
}