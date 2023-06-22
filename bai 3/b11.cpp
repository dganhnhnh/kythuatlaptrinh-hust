// Nguyễn Dương Ánh 20210082
#include<bits/stdc++.h>
using namespace std;
const int MAX = 10000;
int n, r;
int cost[MAX][MAX];
int x[MAX];
bool visited[MAX];
vector<int> vt;
int min_cost;
int sum_cost;
int start, destination, numberOfPoint;

void input(){
    cin >> n >> r;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> cost[i][j];
        }
}

bool check(int a, int i){
    if(visited[vt[i]]) return false;
    if(cost[x[a-1]][vt[i]] == 0) return false;
    return true;
}

void solution(){
    if(cost[x[numberOfPoint-2]][destination] == 0) return;
    min_cost = min(min_cost, sum_cost + cost[x[numberOfPoint-2]][destination]);
}

void TRY(int a){
    for(int i=1; i<numberOfPoint-1; i++){
        if(check(a, i)){
            visited[vt[i]] = true;
            sum_cost += cost[x[a-1]][vt[i]];

            x[a] = vt[i];
            if(a == numberOfPoint-2) solution();
            else TRY(a+1);

            visited[vt[i]] = false;
            sum_cost -= cost[x[a-1]][vt[i]];
        }
    }
}

int main(){
    string str;
    input(); getline(cin,str);

    while(r > 0){
        min_cost = INT_MAX;
        sum_cost = 0;

        getline(cin, str);

        while (!str.empty()){
            stringstream convert(str.substr(0, str.find(" ")));
            int tmp = 0;
            convert >> tmp;
            vt.push_back(tmp - 1);

            if (str.find(" ") > str.size()){
                break;
            } else {
                str.erase(0, str.find(" ") + 1);
            }
        }

        start = vt[0]; 
        destination = vt[vt.size()-1]; 
        numberOfPoint = vt.size(); 
        x[0] = start; x[numberOfPoint-1] = destination;
        for(int i=0; i<n; i++)
            visited[i] = false;

        TRY(1);

        if(min_cost == INT_MAX) cout << "0" << endl;
        else cout << min_cost << endl;

        vt.erase(vt.begin(), vt.end());
        r--;
    }
}
// Nguyễn Dương Ánh 20210082