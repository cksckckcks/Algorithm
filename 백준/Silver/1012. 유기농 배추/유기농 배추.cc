#include <iostream>
#include <queue>
#include <utility>
#include <string.h>

using namespace std;

bool field[51][51];
bool visited[51][51];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int M, N, cnt;
queue <pair<int, int>> q;

void bfs(int x, int y) {
    q.push({x, y});

    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        visited[xx][yy] = 1;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int dxx = xx + dx[i];
            int dyy = yy + dy[i];
            
            if (dxx >= 0 && dxx < M && dyy >= 0 && dyy < N && !visited[dxx][dyy] && field[dxx][dyy]) {
                q.push({dxx, dyy});
                visited[dxx][dyy] = 1;
            }

        }
    }
}

int main() {
    int T;
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int K;
        
        cin >> M >> N >> K;
        
        cnt = 0;
        for (int j = 0; j < K; j++) {
            int x, y;
            
            cin >> x >> y;
            
            field[x][y] = 1;
        }
        
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                if (field[j][k] && !visited[j][k]) {
                    cnt++;
                    bfs(j, k);
                }
            }
        }
        
        while (!q.empty()) q.pop();
        memset(field, 0, sizeof(field));
        memset(visited, 0, sizeof(visited));
        
        cout << cnt << '\n';
    }
}