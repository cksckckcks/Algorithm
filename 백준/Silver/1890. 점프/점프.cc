#include <iostream>

using namespace std;

int map[101][101];
unsigned long long dp[110][110];

int main() {
    int N;

    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> map[i][j];

    dp[1][1] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] == 0)
                continue;
            
            int n = map[i][j];

            dp[i][j + n] += dp[i][j];
            dp[i + n][j] += dp[i][j];
        }
    }

    cout << dp[N][N];
}
