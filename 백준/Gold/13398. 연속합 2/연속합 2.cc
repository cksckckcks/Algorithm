#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v;
    int n, ans;
    int dp[100001][2];

    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;

        cin >> num;
        v.push_back(num);
    }

    dp[0][0] = v[0];
    dp[0][1] = 0;
    ans = v[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0] + v[i], v[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + v[i]);
        ans = max(max(ans, dp[i][0]), dp[i][1]);
    }
    
    cout << ans;
}
