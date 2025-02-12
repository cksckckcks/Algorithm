#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <tuple>

using namespace std;
int N, M, K;
int map[1001][1001];
bool visited[1001][1001][11];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs() {
    int cnt = 0;
    queue<tuple<int, int, int, int>> q;
    
    q.push({1, 1, 0, 1});
    visited[1][1][0] = 1;

    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int well = get<2>(q.front());
        int cnt = get<3>(q.front());

        q.pop();

        if (x == N && y == M)
            return cnt;

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx <= 0 || xx > N || yy <= 0 || yy > M)
                continue;

            if (map[xx][yy] == 0 && visited[xx][yy][well] == 0) {
                visited[xx][yy][well] = 1;
                q.push({xx, yy, well, cnt + 1});
            }
            if (map[xx][yy] == 1 && well + 1 <= K && visited[xx][yy][well + 1] == 0) {
                    if (cnt % 2) {
                        visited[xx][yy][well + 1] = 1; 
                        q.push({xx, yy, well + 1, cnt + 1});
                    }
                    else
                        q.push({x, y, well, cnt + 1});
            }
        }
    }
    return -1;
}


int main() {
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        string s;
        
        cin >> s;
        
        for (int j = 1; j <= M; j++) 
            map[i][j] = s[j - 1] - '0';
    }

    cout << bfs();
}
