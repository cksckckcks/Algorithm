#include <iostream>
#include <vector>

using namespace std;

int dp[41];
bool fix[41];

int main() {
    int N, M;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int n;

        cin >> n;

        fix[n] = 1;
    }

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= N; i++) {
        if (fix[i] || fix[i - 1])
            dp[i] = dp[i - 1];
        else
            dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[N];
}