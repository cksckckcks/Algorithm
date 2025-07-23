#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int N, M;
int first[10], arr[10];
bool visited[10];
set<vector<int>> s;

void dfs(int k) {
    if(k == M) {
        vector<int> v;

        for(int i = 0; i < M; i++)
            v.push_back(arr[i]);
        s.insert(v);
    }


    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            visited[i] = 1;
            arr[k] = first[i];
            dfs(k + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> N >> M;

    for(int i = 0; i < N; i++)
        cin >> first[i];
    
    sort(first, first+N);

    dfs(0);

    for(auto it:s) {
        for(auto it2:it)
            cout << it2 << " ";
        cout << '\n';
    }
}