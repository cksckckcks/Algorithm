#include <iostream>
#include <algorithm>

using namespace std;


int dp[1500001],  T[1500001], P[1500001];

int main() {
    int N;

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> T[i] >> P[i];

    for (int i = 1; i <= N; i++) {
        if(dp[i] < dp[i - 1])
            dp[i] = dp[i - 1];
        
        dp[i + T[i] - 1] = max(dp[i - 1] + P[i], dp[i + T[i] - 1]);
    }

    cout << dp[N];
}