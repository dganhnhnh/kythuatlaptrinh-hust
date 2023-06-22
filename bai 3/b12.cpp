// Nguyễn Dương Ánh 20210082
#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
int n, k;
int m;
vector<vector<int> > vt; 
int x[MAX];
bool visited[MAX];
int res;

void input(){
    cin >> n >> k;
    cin >> m;
    vt.resize(n+1);
    for(int i=0; i<m; i++){
        int t1, t2;
        cin >> t1 >> t2;

        vt[t1-1].push_back(t2-1); 
        vt[t2-1].push_back(t1-1); 
    }

    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    res = 0;
}

bool check(int a, int i){
    if(a == 0) return true;
    if(visited[i]) return false;

    int index = 0;
    for(int j=0; j<vt[x[a-1]].size(); j++){
        if(i == vt[x[a-1]][j]) index++;
    }
    if(index == 0) return false;


    return true;
}

void solution(){
    res++;
}

void TRY(int a){
    for(int i=0; i<n; i++){
        if(check(a, i)){
            visited[i] = true;
            x[a] = i;

            if(a == k) solution();
            else TRY(a+1);

            visited[i] = false;
        }
    }
}

int main(){
    input();
    TRY(0);
    cout << res / 2;
}
// Nguyễn Dương Ánh 20210082