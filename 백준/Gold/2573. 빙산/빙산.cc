#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int map[301][301];
bool visited[301][301];
int tmp[301][301];
int N, M, year;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    
    q.push({x, y});
    visited[x][y] = 1;

    while (!q.empty()) {
        auto[x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if ( xx <= 0 || yy <= 0 || xx > N || yy > M || visited[xx][yy]) 
                continue;

            if (map[xx][yy] > 0) {
                q.push({xx, yy});
                visited[xx][yy] = 1;
            }
        }
    }
}

void bfs2(int x, int y) {
    queue<pair<int, int>> q;
    
    q.push({x, y});
    visited[x][y] = 1;

    while (!q.empty()) {
        auto[x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (visited[xx][yy] || xx <= 0 || yy <= 0 || xx > N || yy > M) 
                continue;

            if (map[xx][yy] == 0) {
                q.push({xx, yy});
                visited[xx][yy] = 1;
            } else {
                tmp[xx][yy]++;
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> map[i][j];
  
    int cnt = 1;
    while (1) {
        cnt = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (!visited[i][j] && map[i][j] > 0) {
                    cnt++;
                    bfs(i, j);
                }
            }
        }

        if (cnt >= 2 || cnt == 0)
            break;
        
        memset(visited, 0, sizeof(visited));

        year++;

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                if (!visited[i][j] && map[i][j] == 0)
                    bfs2(i, j);


        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                map[i][j] = map[i][j] - tmp[i][j] >= 0 ? map[i][j] - tmp[i][j] : 0;


        memset(visited, 0, sizeof(visited));
        memset(tmp, 0, sizeof(tmp));
        // cout << endl;
        // for (int i = 1; i <= N; i++) {
        //     for (int j = 1; j <= M; j++) {
        //         cout << map[i][j] << ' ';
        //     }
        //     cout << endl;
        // }

    }

    if (cnt == 0)
        cout << 0;
    else
        cout << year;

}