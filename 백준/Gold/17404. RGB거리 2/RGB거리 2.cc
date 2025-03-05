#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    int color[1001][3];
    int r[1001][3];
    int g[1001][3];
    int b[1001][3];

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> color[i][0] >> color[i][1] >> color[i][2];
    }

    r[2][0] = min(color[1][1], color[1][2]) + color[2][0];
    r[2][1] = color[1][2] + color[2][1];
    r[2][2] = color[1][1] + color[2][2];

    g[2][0] = color[1][2] + color[2][0];
    g[2][1] = min(color[1][0], color[1][2]) + color[2][1];
    g[2][2] = color[1][0] + color[2][2];
   
    b[2][0] = color[1][1] + color[2][0];
    b[2][1] = color[1][0] + color[2][1];
    b[2][2] = min(color[1][0], color[1][1]) + color[2][2];

    // r로 끝나는 상황 / g로 끝나는 상황 / b로 끝나는 상황
    for (int i = 3; i <= N; i++) {
        r[i][0] = color[i][0] + min(r[i - 1][1], r[i - 1][2]);
        r[i][1] = color[i][1] + min(r[i - 1][0], r[i - 1][2]);
        r[i][2] = color[i][2] + min(r[i - 1][0], r[i - 1][1]);

        g[i][0] = color[i][0] + min(g[i - 1][1], g[i - 1][2]);
        g[i][1] = color[i][1] + min(g[i - 1][0], g[i - 1][2]);
        g[i][2] = color[i][2] + min(g[i - 1][0], g[i - 1][1]);

        b[i][0] = color[i][0] + min(b[i - 1][1], b[i - 1][2]);
        b[i][1] = color[i][1] + min(b[i - 1][0], b[i - 1][2]);
        b[i][2] = color[i][2] + min(b[i - 1][0], b[i - 1][1]);
    }

    cout << min({r[N][0], g[N][1], b[N][2]});
}