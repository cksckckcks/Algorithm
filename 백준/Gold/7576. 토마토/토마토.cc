#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[1001][1001] = { 0, };
int xx[4] = { 0, 1, -1, 0 };
int yy[4] = { 1, 0, 0, -1 };
bool visited[1001][1001] = { 0, };
queue <pair<int, int>> q;
int M, N;

void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + xx[i];
            int ny = y + yy[i];

            if (nx == 0 || nx > N || ny == 0 || ny > M) continue;
            if (arr[nx][ny] == 0 || arr[nx][ny] == 1 && !visited[nx][ny]) {
                q.push(make_pair(nx, ny));
                arr[nx][ny] = arr[x][y] + 1;
                visited[nx][ny] = 1;
            }
        }
    }

}

int main() {
    cin >> M >> N;

    bool zero = false;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int n;

            cin >> n;

            arr[i][j] = n;

            if (n == 1) {
                q.push(make_pair(i, j));
                visited[i][j] = 1;
            }
            else if (n == 0)
                zero = true;
        }
    }

    if (!zero) {
        cout << 0;
        return 0;
    }
    
    bfs();
    int answer = -1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (arr[i][j] == 0) {
                cout << -1;
                return 0;
            }
            answer = max(answer, arr[i][j]);
        }
    }

    cout << answer - 1;
}