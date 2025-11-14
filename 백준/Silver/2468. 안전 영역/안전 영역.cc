#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int arr[101][101];
bool visited[101][101];
int water = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans = 0;
int maxValue = 0;

void dfs(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if (xx <= 0 || xx > N || yy <= 0 || yy > N || visited[xx][yy] || water >= arr[xx][yy])
            continue;
        
        dfs(xx, yy);
    }
}

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];

            maxValue = max(maxValue, arr[i][j]);
        }
    }

    while (water < maxValue) {
        int cnt = 0;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (!visited[i][j] && water < arr[i][j]) {
                    cnt++;

                    dfs(i, j);
                }
            }
        }

        ans = max(cnt, ans);
        water++;

        memset(visited, 0, sizeof(visited));
    }

    cout << ans;
    
}