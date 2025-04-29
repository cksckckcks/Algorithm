#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool visited[501];
vector<int> v[501];
int n, m, cnt;


void bfs() {
    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1] = true;

    while (!q.empty()) {
        auto [a, b] = q.front();
        q.pop();

        if (b == 2) {
            continue;
        }

        for (int i = 0; i < v[a].size(); i++) {
            int n = v[a][i];
            if (visited[n])
                continue;
            visited[n] = true;
            cnt++;

            q.push({n, b + 1});
        }
    }
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;

        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs();

    cout << cnt;
}