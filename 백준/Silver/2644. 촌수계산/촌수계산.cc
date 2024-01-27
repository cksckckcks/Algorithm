#include <iostream>
#include <vector>
using namespace std;

vector <int> v[101];
bool visited[101] = { 0, };
int N, p1, p2, T, answer = -1;

void dfs(int x, int cnt) {
    if (x == p2) {
            answer = cnt;
            return;
    }
    
    visited[x] = 1;
    
    for (int i = 0; i < v[x - 1].size(); i++)
        if (!visited[v[x-1][i]])
            dfs(v[x - 1][i], cnt + 1);
}

int main() {
    cin >> N >> p1 >> p2 >> T;
    
    while(T--) {
        int a, b;
        
        cin >> a >> b;
        
        v[a - 1].push_back(b);
        v[b - 1].push_back(a);
    }
    
    dfs(p1, 0);
    
    cout << answer;
}