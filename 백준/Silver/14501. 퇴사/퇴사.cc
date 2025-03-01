#include <iostream>
#include <algorithm>

using namespace std;


int dp[17];

int main() {
    int T[17], P[17], N;

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> T[i] >> P[i];

    for (int i = N; i > 0; i--) {
        if (i + T[i] <= N + 1)
            dp[i] = max(dp[i + T[i]] + P[i], dp[i + 1]);
        else
            dp[i] = dp[i + 1];
    }

    sort(dp, dp + N + 1);

    cout << dp[N];
}