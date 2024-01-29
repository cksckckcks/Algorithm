#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[101][101][101] = { 0, };
int xx[6] = { 1, -1, 0, 0, 0, 0};
int yy[6] = { 0, 0, 1, 0, 0, -1 };
int zz[6] = { 0, 0, 0, 1, -1, 0 };
bool visited[101][101][101] = {0,};
queue <pair<int,  pair<int, int>>> q;
int M, N, H;

void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second.first;
        int z = q.front().second.second;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nx = x + xx[i]; 
            int ny = y + yy[i];
            int nz = z + zz[i];

            if (nx == 0 || nx > H || ny == 0 || ny > N|| nz == 0 || nz > M) continue;
            if (arr[nx][ny][nz] == 0 || arr[nx][ny][nz] == 1 && !visited[nx][ny][nz]) {
                q.push(make_pair(nx, make_pair(ny, nz)));
                arr[nx][ny][nz] = arr[x][y][z] + 1;
                visited[nx][ny][nz] = 1;
            }
        }
    }

}

int main() {
    cin >> M >> N >> H;

    bool zero = false;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= M; k++) {
                int n;

                cin >> n;

                arr[i][j][k] = n;

                if (n == 1) {
                    q.push(make_pair(i, make_pair(j, k)));
                    visited[i][j][k] = 1;
                }
                else if (n == 0)
                    zero = true;
            }
        }
    }

    if (!zero) {
        cout << 0;
        return 0;
    }

    bfs();

    int answer = -1;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= M; k++) {
                if (arr[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }
                answer = max(answer, arr[i][j][k]);
            }
        }
    }

    cout << answer - 1;
}