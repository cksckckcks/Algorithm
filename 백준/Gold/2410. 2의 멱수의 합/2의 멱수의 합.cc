#include <iostream>

using namespace std;

int dp[1000001];

int main() {
    int N;

    cin >> N;

    dp[1] = 1; dp[2] = 2;

    for (int i = 3; i <= N; i++) {
        if (i % 2)
            dp[i] = dp[i - 1] % 1000000000;
        else
            dp[i] = (dp[i - 1] + dp[i / 2]) % 1000000000;
    }

    cout << dp[N];
}