#include <iostream>
#include <algorithm>

using namespace std;

int art[501][501];
int visited[501][501];
int n, m, artCnt, maxSize = -1;

int dfs(int x, int y) {
    visited[x][y] = 1;
    int cnt = 1;

    if (x + 1 < n && art[x + 1][y] == 1 && visited[x + 1][y] == 0)
        cnt += dfs(x + 1, y);
    if (x - 1 >= 0 && art[x - 1][y] == 1 && visited[x - 1][y] == 0)
        cnt += dfs(x - 1, y);
    if (y + 1 < m && art[x][y + 1] == 1 && visited[x][y + 1] == 0)
        cnt += dfs(x, y + 1);
    if (y - 1 >= 0 && art[x][y - 1] == 1 && visited[x][y - 1] == 0)
        cnt += dfs(x, y - 1);
    
    return cnt;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> art[i][j];

    artCnt = 0;
    maxSize = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (art[i][j] == 1 && visited[i][j] == 0) {
                int tmp = dfs(i, j);
                maxSize = max(maxSize, tmp);
                artCnt++;
            }
        }
    }
    
    cout << artCnt << '\n' << maxSize << '\n';
}
