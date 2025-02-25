#include <iostream>
#include <queue>
#include <deque>
#include <utility>
#include <string>
#include <cstring>

using namespace std;

int R, C, swanX = -1, swanY = -1;
char lake[1501][1501];
bool visited[1501][1501];
int ice_level[1501][1501];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int ans;

void print_ice() {
    cout << endl;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << ice_level[i][j] << ' ';
        }
        cout << endl;
    }
}

void bfs(int x, int y) {
    deque<pair<pair <int, int>, int>> dq;
    
    dq.push_front({{x, y}, 1});
    visited[x][y] = 1;

    while (!dq.empty()) {
        auto [locate, cost] = dq.front();
        auto [x, y] = locate;
        dq.pop_front();
        
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx < 0 || xx >= R || yy < 0 || yy >= C || visited[xx][yy] == 1)
                continue;

            if (lake[xx][yy] == 'L') {
                ans = cost;
                return;
            }
            visited[xx][yy] = 1;

            int new_cost = max(ice_level[xx][yy], cost);
            if (ice_level[xx][yy] <= cost) 
                dq.push_front({{xx, yy}, new_cost});
            else
                dq.push_back({{xx, yy}, new_cost});
        }
    }
}

void ice_level_check() {
    queue<pair<int, int>> q;
    queue<pair<int, int>> ice;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (lake[i][j] == '.' || lake[i][j] == 'L') {
                q.push({i, j});
                visited[i][j] = 1;
                ice_level[i][j] = 1;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx < 0 || xx >= R || yy < 0 || yy >= C || visited[xx][yy])
                continue;
            if (lake[xx][yy] == '.' || lake[xx][yy] == 'L') {
                visited[xx][yy] = 1;
                ice_level[xx][yy] = 1;
                q.push({xx, yy});
            }
            else if (lake[xx][yy] == 'X') {
                visited[xx][yy] = 1;
                ice_level[xx][yy] = (ice_level[xx][yy] == 0) ? ice_level[x][y] + 1 : min(ice_level[xx][yy], ice_level[x][y] + 1);
                q.push({xx, yy});
            }
        }
    }
}

int main() {
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        string s;

        cin >> s;

        for (int j = 0; j < C; j++) {
            lake[i][j] = s[j];

            if (swanX == -1 && lake[i][j] == 'L') {
                swanX = i;
                swanY = j;
            }
        }
    }

    ice_level_check();
    memset(visited, 0, sizeof(visited));

    //print_ice();

    bfs(swanX, swanY);

    cout << ans - 1;
}