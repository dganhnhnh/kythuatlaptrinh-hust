#include <iostream>
#include <map>

using namespace std;

template <class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b)
{
    map<T, double> c;

    double aKey, bKey, aValue, bValue;
    for (auto itA = a.begin(); itA != a.end(); itA++)
    {
        // 2 tập hợp chưa chắc cùng số phần tử
        aKey = itA->first;
        aValue = itA->second;
        for(auto itB = b.begin(); itB != b.end(); itB++){
            bKey = itB->first;
            bValue = itB->second;
            if(bKey == aKey){
                c[aKey] = max(aValue,bValue);
                break;
            }else if(c.find(bKey) == c.end()){
                c[bKey] = bValue;
            }
        }
        if(b.find(aKey) == b.end()){
            c[aKey] = aValue;
        }
    }
    // for (auto itB = b.begin(); itB != b.end(); itB++){
    //     bKey = itB->first;
    //     bValue = itB->second;
    //     if(c.find(bKey) == c.end()){
    //         c[bKey] = bValue;
    //     }
    // }
    // for (auto itA = a.begin(); itA != a.end(); itA++){
    //     aKey = itA->first;
    //     aValue = itA->second;
    //     if(c.find(aKey) == c.end()){
    //         c[aKey] = aValue;
    //     }
    // }
    return c;
}

template <class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b)
{
    map<T, double> d;

    double aKey, bKey, aValue=0, bValue=0;
    for (auto itA = a.begin(); itA != a.end(); itA++)
    {
        aKey = itA->first;
        aValue = itA->second;
        for(auto itB = b.begin(); itB != b.end(); itB++){
            bKey = itB->first;
            bValue = itB->second;
            if(bKey == aKey){
                d[aKey] = min(aValue,bValue);
                break;
            }
        }
    }
    return d;
}

template <class T>
void print_fuzzy_set(const std::map<T, double> &a)
{
    cout << "{ ";
    for (const auto &x : a)
    {
        std::cout << "(" << x.first << ", " << x.second << ") ";
    }
    cout << "}";
    std::cout << std::endl;
}

int main()
{
    std::map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
    std::map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
    std::cout << "A = ";
    print_fuzzy_set(a);
    std::cout << "B = ";
    print_fuzzy_set(b);
    std::map<int, double> c = fuzzy_set_union(a, b);
    std::map<int, double> d = fuzzy_set_intersection(a, b);
    std::cout << "Union: ";
    print_fuzzy_set(c);
    std::cout << "Intersection: ";
    print_fuzzy_set(d);
}