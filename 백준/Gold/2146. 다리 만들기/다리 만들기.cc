#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;


int arr[101][101] = { 0, };
int visited[101][101] = { 0, };
int xx[4] = { 0, 1, 0, -1 };
int yy[4] = { 1, 0, -1, 0 };
int N, minRoute = 101, islandNum = -1, answer = 10001; // 섬 번호는 -1부터, answer은 최대 값 +1

// 섬을 구분하기 위해 번호를 매기는 코드
void islandSetNum(int x, int y) {
    queue <pair <int, int>> iq;
    visited[x][y] = 1;
    arr[x][y] = islandNum;
    iq.push(make_pair(x, y));
    while (!iq.empty()) {
        int x = iq.front().first;
        int y = iq.front().second;
        iq.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + xx[i];
            int ny = y + yy[i];

            if (nx == 0 || nx > N || ny == 0 || ny > N || arr[nx][ny] == 0) continue;
            if (!visited[nx][ny]) {
                iq.push(make_pair(nx, ny));
                visited[nx][ny] = 1;
                arr[nx][ny] = islandNum;
            }
        }
    }
}


void bfs(int n) {
    queue <pair <int, pair <int, int>>> q;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] == n) {
                visited[i][j] = 1;
                q.push(make_pair(i, make_pair(j, 0)));
                //cout << "q push : " << i << " " << j << endl;
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().first; // x 좌표
        int y = q.front().second.first; // y 좌표
        int z = q.front().second.second; // 경로 cnt
        q.pop();



        for (int i = 0; i < 4; i++) {
            int nx = x + xx[i];
            int ny = y + yy[i];

            if (nx == 0 || nx > N || ny == 0 || ny > N) continue; // 범위 체크
            if (arr[nx][ny] < 0 && arr[nx][ny] != n) // 섬이지만 탐색하는 섬과 같은 번호가 아니라면
                answer = min(answer, z); // 최소 경로 체크
            if (!visited[nx][ny]) {
                q.push(make_pair(nx, make_pair(ny, z + 1)));
                visited[nx][ny] = 1;
            }
        }
    }
}

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int n;

            cin >> n;

            arr[i][j] = n;
        }
    }

    // 섬 번호 매기기 (island 함수 이용) -1 ~ 섬의 갯수 만큼
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] == 1) {
                islandSetNum(i, j);
                islandNum--;
            }
        }
    }

    while (++islandNum != 0) {
        memset(visited, 0, sizeof(visited)); // 탐색 전 visited 초기화
        //cout << "N : " << islandNum << endl;
        bfs(islandNum); // 섬 번호로 탐색
    }
        

    cout << answer;

}