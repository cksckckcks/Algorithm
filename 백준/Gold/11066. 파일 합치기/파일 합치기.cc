#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    int T;

    cin >> T;

    while (T--) {
        int chapter[501], dp[501][501], sum[501], K;

        cin >> K;
    
        memset(dp, 0, sizeof(dp));
        sum[0] = 0;

        for (int i = 1; i <= K; i++) {
            cin >> chapter[i];

            sum[i] = sum[i - 1] + chapter[i];
        }

        for (int i = 1; i < K; i++) {
            int x = 1;
            int y = i + 1;
            for (int j = 0; j < K - i; j++) {
                dp[x][y] = 2147483647;
                for(int k = y - i; k <= y - 1; k++)
                    dp[x][y] = min(dp[x][y], dp[x][k] + dp[k + 1][y] + sum[y] - sum[x - 1]);
                x++;
                y++;
            }
        }
        cout << dp[1][K] << '\n';
    }
}