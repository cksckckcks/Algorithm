#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001];

int main() {
    int n, ans = 1;
    int input[1001];

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> input[i];
    
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        dp[i] = 1;

        for (int j = 0; j < i; j++)
            if (input[i] > input[j])
                dp[i] = max(dp[i], dp[j] + 1);

        ans = max(ans, dp[i]);
    }

    cout << ans;
}   