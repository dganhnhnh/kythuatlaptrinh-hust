#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;
void dfs(vector< list<int> > adj) {
    stack<int> S;
    vector<bool> visited(adj.size());
    S.push(1); // Bắt đầu từ đỉnh số 1
    
    /*****************
    # YOUR CODE HERE #
    *****************/
}

// int main() {
//     int n = 9;
//     vector< list<int> > adj(n);
//     auto add_edge = [&adj] (int u, int v, int w) {
//         adj[u].push_back({v, w});
//         adj[v].push_back({u, w});
//     };

//     vector<int> distance = dfs(adj);
//     for (int i = 0; i < distance.size(); ++i) {
//         cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
//     }

//     return 0;
// }