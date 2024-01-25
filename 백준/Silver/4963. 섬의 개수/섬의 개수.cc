#include <iostream>
#include <vector>
#include <cstring> // 앞으로 string.h 대신 사용하자
using namespace std;

vector<int> v[51];
int visited[51][51] = {0,};
int xarr[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int yarr[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int w, h, answer = 0;

void dfs(int x, int y) {
    visited[x][y] = 1;

    for (int i = 0; i < 8; i++) {
        int xx = x + xarr[i];
        int yy = y + yarr[i];

        if (xx >= 0 && yy >= 0 && xx < h && yy < w && !visited[xx][yy] && v[xx][yy])
            dfs(xx, yy);
    }
}

int main() {
    while (1) {
        cin >> w >> h;

        if (w == 0 && h == 0)
            break;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int n;

                cin >> n;
                v[i].push_back(n);
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!visited[i][j] && v[i][j]) {
                    answer++;
                    dfs(i, j);
                }
            }
        }

        cout << answer << '\n';
        answer = 0;
        for (int i = 0; i < h; i++)
            v[i].clear();
        memset(visited, 0, sizeof(visited));
    }
}
