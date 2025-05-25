#include <iostream>
#include <algorithm>

using namespace std; 

int dp[501][501];

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> dp[i][j];


    int ret = dp[0][0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == j)
                dp[i][j] = dp[i][j] + dp[i - 1][j - 1];
            else if (j == 0)
                dp[i][j] = dp[i][j] + dp[i - 1][j];
            else
                dp[i][j] = dp[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);

            if(i == n - 1)
                ret = max(ret, dp[i][j]);
        }
    }
    
    cout << ret;
}