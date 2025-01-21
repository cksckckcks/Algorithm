#include <iostream>
#include <string>

using namespace std;

char map[21][21];
bool visited[21][21];
bool alpha[28];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int R, C, ans;

void dfs(int x, int y, int cnt) {
    bool check = 0;
    visited[x][y] = 1;
    alpha[map[x][y] - 'A'] = 1;

    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx > 0 && xx <= R && yy > 0 && yy <= C && !visited[xx][yy] && !alpha[map[xx][yy] - 'A']) {
            check = 1;
            dfs(xx, yy, cnt + 1);
            visited[xx][yy] = 0;
            alpha[map[xx][yy] - 'A'] = 0;
        }
    }

    if (!check && ans < cnt)
        ans = cnt;
}

int main() {
    cin >> R >> C;
    
    for (int i = 1; i <= R; i++) {
        string s;

        cin >> s;
        for (int j = 0; j < C; j++)
            map[i][j + 1] = s[j];
    }

    dfs(1, 1, 1);
    cout << ans;
}