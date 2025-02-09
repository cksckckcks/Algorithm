#include <iostream>

using namespace std;

int M, N;
int map[500][500];
int dp[500][500];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int dfs(int x, int y) {
    if (x == N - 1 && y == M - 1)
        return 1;

    if (dp[x][y] == -1) {
        dp[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && xx < N && yy >= 0 && yy < M && map[x][y] > map[xx][yy])
                dp[x][y] += dfs(xx, yy);
        }
    }

    return dp[x][y];
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }

    cout << dfs(0, 0);
}
