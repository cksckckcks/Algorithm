#include <iostream>

using namespace std;

int map[51][51];
int N, M, robotX, robotY, d, ans;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};


bool range_check(int x, int y) { return !(x < 0 || x >= N || y < 0 || y >= M); }

void clean() {
    while (1) {
        bool check_clean = 0;

        if (map[robotX][robotY] == 0) {
            map[robotX][robotY] = -1;
            ans++;
        }
        for (int i = 0; i < 4; i++) {
            int x = robotX + dx[i];
            int y = robotY + dy[i];

            if (!range_check(x, y))
                continue;
            
            if (map[x][y] == 0) {
                check_clean = 1;
                break;
            }
        }

        if (!check_clean) {
            int x = robotX + dx[(d + 2) % 4];
            int y = robotY + dy[(d + 2) % 4];
            
            if (range_check(x, y) && map[x][y] != 1) {
                robotX = x;
                robotY = y;
                continue;
            }
            else
                return;
        }
        else {
            for (int i = 0; i < 4; i++) {
                d = (d + 3) % 4;
                int x = robotX + dx[d];
                int y = robotY + dy[d];

                if (!range_check(x, y))
                    continue;

                if (map[x][y] == 0) {
                    robotX = x;
                    robotY = y;
                    break;
                }
            }
        }
    }
}


int main() {
    cin >> N >> M;

    cin >> robotX >> robotY >> d;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    clean();

    cout << ans;
}