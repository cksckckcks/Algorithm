#include <iostream>
#include <queue>
#include <utility>

using namespace std;

queue<pair<pair<int, int>, int>> q;
int map[1001][1001];
int visited[1001][1001][11];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M, K;

int bfs() {
    visited[1][1][0] = 1;
    q.push({{1, 1}, 0});
    
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int sign = q.front().second;
        
        q.pop();
        
        if (x == N && y == M)
            return visited[x][y][sign];
        
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if (xx >= 1 && xx <= N && yy >= 1 && yy <= M) {
                if (map[xx][yy] == 0 && visited[xx][yy][sign] == 0) {
                    q.push({{xx, yy}, sign});
                    visited[xx][yy][sign] = visited[x][y][sign] + 1;
                }
                else if (map[xx][yy] == 1 && sign+1 <= K && visited[xx][yy][sign+1] == 0) {
                    q.push({{xx, yy}, sign + 1});
                    visited[xx][yy][sign + 1] = visited[x][y][sign] + 1;
                }
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
    
    cout << bfs() << '\n';
}