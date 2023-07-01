// Nguyen Duong Anh 20210082
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;
void bfs(vector< list<int> > adj) {
    queue<int> S;
    vector<bool> visited(adj.size());
    // vector<list<int>>::iterator it=adj.begin();
    // while (it != adj.end()){
    //     reverse(it->begin(), it->end());
    //     it++;
    // }
    S.push(1); // Bắt đầu từ đỉnh số 1
    cout<< "1\n";
    visited[0] = true;
    while(!S.empty()){
        int current = S.front();

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
int main(){
    int n = 7;
    vector< list<int> > adj;
    adj.resize(n + 1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);
    bfs(adj);
}
// Nguyen Duong Anh 20210082