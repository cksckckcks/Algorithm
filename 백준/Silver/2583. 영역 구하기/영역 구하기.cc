#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector <int> ans;
int M, N, K, cnt, width;
bool visited[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int x, int y) {
    queue <pair<int, int>> q;

    width = 0;
    q.push({x, y});
    visited[x][y] = 1;

    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        width++;

        for (int i = 0; i < 4; i++) {
            int dxx = xx + dx[i];
            int dyy = yy + dy[i];

            if (dxx >= 0 && dyy >= 0 && dxx < M && dyy < N && !visited[dxx][dyy]) {
                q.push({dxx, dyy});
                visited[dxx][dyy] = 1;
            }
        }
    }
    ans.push_back(width);
}

void set() {
    int x, y, xx, yy;

    cin >> x >> y >> xx >> yy;

    for (int i = y; i < yy; i++) {
        for (int j = x; j < xx; j++) {
            visited[i][j] = 1;
        }
    }
}

int main() {

    cin >> M >> N >> K;
    
    for (int i = 0; i < K; i++)
        set();

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << cnt << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
}
