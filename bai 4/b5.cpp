// Nguyen Duong Anh 20210082
#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;
void dfs(vector< list<int> > adj) {
    stack<int> S;
    vector<bool> visited(adj.size());
    vector<list<int>>::iterator it=adj.begin();
    while (it != adj.end()){
        reverse(it->begin(), it->end());
        it++;
    }
    S.push(1); // Bắt đầu từ đỉnh số 1
    visited[0] = true;
    while(!S.empty()){
        int current = S.top();

        if(!visited[current]){
            visited[current] = true;
            std::cout<< current<<"\n";
        }
        S.pop();
        list<int>::iterator it = adj[current].begin();

        // duyệt danh sách kề của đỉnh đang xét
        while(it != adj[current].end()){
            if(!visited[*it]){
                S.push(*it);
            }
            it++;
        }
    }

}
// Nguyen Duong Anh 20210082