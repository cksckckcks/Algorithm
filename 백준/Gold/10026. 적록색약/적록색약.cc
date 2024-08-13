#include <iostream>

using namespace std;

char color[101][101];
int visited[101][101];
int N, cnt;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


void dfs(int x, int y, char c) {
    visited[x][y] = 1;
    
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
        if (visited[nx][ny] == 1 || color[nx][ny] != c)
            continue;
        dfs(nx, ny, c);
    }
}

void dfs2(int x, int y, int sign) {
    visited[x][y] = 0;
    
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
        if (sign == 0) {
            if (visited[nx][ny] == 0 || color[nx][ny] == 'B')
                continue;
        }
        else {
            if (visited[nx][ny] == 0 || color[nx][ny] != 'B')
                continue;
        }
        dfs2(nx, ny, sign);
    }
}

int main()
{
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string str;
        
        cin >> str;
        
        for (int j = 0; j < N; j++)
            color[i][j] = str[j];
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 0) {
                dfs(i, j, color[i][j]);
                cnt++;
            }
        }
    }
    
    cout << cnt << '\n';
    
    cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 1) {
                if (color[i][j] == 'B')
                    dfs2(i, j, 1);
                else
                    dfs2(i, j, 0);
                cnt++;
            }
        }
    }
    
    cout << cnt;
}