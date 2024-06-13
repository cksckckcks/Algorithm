#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int dp[101][100001];

int main() {
    int N, K;
    vector <pair<int, int>> v;

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int W, V;

        cin >> W >> V;
        v.push_back({W, V});
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (v[i - 1].first > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1].first] + v[i - 1].second);
        }
    }

    cout << dp[N][K];
}