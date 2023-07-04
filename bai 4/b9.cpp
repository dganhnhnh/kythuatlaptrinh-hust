#include <iostream>
#include <queue>
#include <climits>
using namespace std;


struct compare{
    bool operator() (pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

vector<int> dijkstra(const vector<vector<pair<int, int>>> &adj)
{
    // Khởi tạo hàng đợi ưu tiên (priority_queue) q, sử dụng cặp (pair) để lưu đỉnh và khoảng cách từ đỉnh 0 đến đỉnh đó
    // Sắp xếp hàng đợi ưu tiên theo khoảng cách ngắn nhất
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
    // Khởi tạo vector dist để lưu khoảng cách ngắn nhất từ đỉnh 0 đến các đỉnh còn lại
    vector<int> dist(adj.size());

    // Lấy kích thước của dist để sử dụng trong vòng lặp
    int dist_size = dist.size();

    // Khởi tạo tất cả các khoảng cách ban đầu với giá trị vô cùng (INT_MAX)
    for (int i = 0; i < dist_size; i++)
    {
        dist[i] = INT_MAX;
    }

    // Khoảng cách từ đỉnh 0 đến chính nó là 0
    dist[0] = 0;

    // Đưa tất cả các đỉnh và khoảng cách từ đỉnh 0 đến hàng đợi ưu tiên
    for (int i = 0; i < dist_size; i++)
    {
        q.push({i, dist[i]});
    }

    // Tiến hành thuật toán Dijkstra
    while (!q.empty())
    {
        // Lấy đỉnh u có khoảng cách ngắn nhất từ đỉnh 0 trong hàng đợi ưu tiên
        pair<int, int> u_pair = q.top();
        q.pop();
        int u = u_pair.first;

        // Duyệt qua tất cả các đỉnh v kề với u
        for (auto v_pair : adj[u])
        {
            int v = v_pair.first;
            int weight = v_pair.second;

            // Nếu khoảng cách từ đỉnh 0 đến v thông qua u nhỏ hơn khoảng cách hiện tại, cập nhật khoảng cách và đưa v vào hàng đợi
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                q.push({v, dist[v]});
            }
        }
    }

    // Trả về vector chứa khoảng cách ngắn nhất từ đỉnh 0 đến tất cả các đỉnh
    return dist;
}

int main()
{
    int n = 9;
    vector<vector<pair<int, int>>> adj(n);
    // lambda function
    auto add_edge = [&adj](int u, int v, int w)
    {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    add_edge(0, 1, 4);
    add_edge(0, 7, 8);
    add_edge(1, 7, 11);
    add_edge(1, 2, 8);
    add_edge(2, 3, 7);
    add_edge(2, 8, 2);
    add_edge(3, 4, 9);
    add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);

    vector<int> distance = dijkstra(adj);
    for (int i = 0; i < distance.size(); ++i)
    {
        cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
    }

    return 0;
}
