#include <iostream>

using namespace std;

int main() {
    int T, W;
    int tree[1001];
    int dp[31][2][1001];

    cin >> T >> W;

    for (int i = 1; i <= T; i++)
        cin >> tree[i];
    
    
        
        for (int i = 0; i <= W; i++) {
            for (int j = 1; j <= T; j++) {
                if (i == 0)
                    dp[i][0][j] = dp[i][0][j - 1] + (tree[j] == 1);
                else {
                    dp[i][0][j] = max(dp[i][0][j - 1] + (tree[j] == 1), dp[i - 1][1][j - 1] + (tree[j] == 1));
                    dp[i][1][j] = max(dp[i][1][j - 1] + (tree[j] == 2), dp[i - 1][0][j - 1] + (tree[j] == 2));
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < 2; i++)
            for (int j = 0; j <= W; j++)
                ans = max(ans, dp[j][i][T]);

        cout << ans;
}