// Nguyen Duong Anh 20210082
#include <iostream>
#include <set>

using namespace std;

// T: kiểu dữ liệu của các phần tử
template <typename T>
set<T> set_union(const set<T> &a, const set<T> &b)
{
    set<T> c;
    // chèn toàn bộ a vào c
    c.insert(a.begin(), a.end());    
    // chèn toàn bộ b vào c
    c.insert(b.begin(), b.end());
    return c;
}

template <class T>
set<T> set_intersection(const set<T> &a, const set<T> &b)
{
    set<T> d;
    for( auto el:a){
        if(b.find(el) != b.end()) d.insert(el);
        // nếu không tìm được phần tử cần tìm thì trả về con trỏ tới cuối set
    }
    return d;
}

template <class T>
void print_set(const std::set<T> &a)
{
    for (const T &x : a)
    {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::set<int> a = {1, 2, 3, 5, 7};
    std::set<int> b = {2, 4, 5, 6, 9};
    std::set<int> c = set_union(a, b);
    std::set<int> d = set_intersection(a, b);

    std::cout << "Union: ";
    print_set(c);
    std::cout << "Intersection: ";
    print_set(d);

    return 0;
}// Nguyen Duong Anh 20210082