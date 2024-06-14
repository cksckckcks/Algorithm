#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int dp[1001][10001];

int main() {
    int N, K;
    vector<pair<int, int>> v;

    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        int I, T;

        cin >> I >> T;
        v.push_back({I, T});
    }

    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            if (j < v[i - 1].second)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1].second] + v[i - 1].first);
        }
    }

    cout << dp[K][N];
}