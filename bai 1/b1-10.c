// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <numeric>

// using namespace std;

// int main() {
//     int val1, val2;
//     cin >> val1 >> val2;
//     vector< vector<int> > a = {
//         {1, 3, 7},
//         {2, 3, 4, val1},
//         {9, 8, 15},
//         {10, val2},
//     };
    
// int sum[a.size()];
// int index[a.size()] ;
// for(int i=0 ; i< a.size();i++){
//    sum[i] = 0;
//    for(int j=0 ; j< a[i].size();j++){
//       sum[i] += a[i][j];
//    }
// }
// int tmp=0;
// vector<int> *ptr=NULL;
// for(int i=0; i<a.size()-1; i++){
//    for (int j = 0; j <a.size() - i - 1; j++) {
//             if (sum[j] < sum[j+1]) {
//                 tmp = sum[j];
//                 sum[j] = sum[j+1];
//                 sum[j+1] = tmp;
                
//                //  *ptr = *(*(a)+j); 
//                //  *(*(a)+j) = *(*(a)+j+1);
//                //  *(*(a)+j+1) = *ptr;
//             }
//         }
// }
// for(int i=0; i<a.size(); i++){
//    cout<< sum[i]<<" ";
// }cout<<"\n";

//     for (const auto &v : a) {
//         for (int it : v) {
           
//             cout << it << ' ';
//         }
//         cout << endl;
//     }
//     return 0;
// }