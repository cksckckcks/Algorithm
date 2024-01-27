#include <iostream>
#include <vector>
using namespace std;

vector <int> v[101];
bool visited[101] = { 0, };
int answer = 0;

void dfs(int x) {
    answer++;
    visited[x] = 1;
    for (int i = 0; i < v[x - 1].size(); i++)
        if (!visited[v[x-1][i]])
            dfs(v[x - 1][i]);
}

int main() {
    int N, T;
    
    cin >> N >> T;
    
    while(T--) {
        int a, b;
        
        cin >> a >> b;
        
        v[a - 1].push_back(b);
        v[b - 1].push_back(a);
    }
    
    dfs(1);
    
    cout << answer - 1; // 1 제외
}