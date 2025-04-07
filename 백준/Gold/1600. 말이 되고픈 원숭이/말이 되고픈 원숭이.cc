#include <iostream>
#include <queue>

using namespace std;

int map[201][201];
bool visited[201][201][30];
int K, H, W;
int night_x[8] = {-2, -1, -2, -1, 2, 1, 2, 1};
int night_y[8] = {-1, -2, 1, 2, -1, -2, 1, 2};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


bool check_x_y(int x, int y, int k) {
    if (x < 0 || x >= H || y < 0 || y >= W)
        return true;
    else
        return (map[x][y] == 1 || visited[x][y][k]);
}

int bfs() {
    // 좌표 좌표 카운트 말 횟수
    queue <pair<pair<int, int>, pair<int, int>>> q;

    q.push({{0, 0}, {0, 0}});

    while (!q.empty()) {
        auto[pos, info] = q.front();
        auto[x, y] = pos;
        auto[cnt, k] = info;

        q.pop();

        if (x + 1 == H && y + 1 == W)
            return cnt;

        if (K > k) {
            for (int i = 0; i < 8; i++) {
                int xx = x + night_x[i];
                int yy = y + night_y[i];

                if (check_x_y(xx, yy, k + 1))
                    continue;
                
                q.push({{xx, yy}, {cnt + 1, k + 1}});
                visited[xx][yy][k + 1] = 1;
            }
        }

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (check_x_y(xx, yy, k))
                continue;
            
            q.push({{xx, yy}, {cnt + 1, k}});
            visited[xx][yy][k] = 1;
        }
    }

    return -1;
}

int main() {
    cin >> K >> W >> H;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> map[i][j];
    
    cout << bfs();
}