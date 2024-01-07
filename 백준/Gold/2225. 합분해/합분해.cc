#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K;

    cin >> N >> K;
    if (K == 1) {
        cout << 1;
        return 0;
    }
 
    long long** dp = new long long* [K + 1];
    for (int i = 0; i <= K; i++)
        dp[i] = new long long[N + 1];
    for (int i = 0; i <= N; i++) {
        dp[0][i] = 0;
        dp[1][i] = 1;
        dp[2][i] = 1;
    }

    for (int i = 3; i <= K; i++) {
        for (int j = 0; j <= N; j++) {
            long long sum = 0;
            for (int k = j; k <= N; k++) {
                sum += dp[i - 1][k] % 1000000000;
            }
            dp[i][j] = sum % 1000000000;
        }
    }

    long long answer = 0;
    for (int i = 0; i <= N; i++)
        answer += dp[K][i];
    cout << answer % 1000000000;

    for (int i = 0; i <= K; ++i)
        delete[] dp[i];
    delete[] dp;
}