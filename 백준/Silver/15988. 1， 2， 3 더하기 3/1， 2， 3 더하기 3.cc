#include <iostream>

using namespace std;

int main() {
    int n;
    long long dp[1000001];
    
    dp[0] = 0; dp[1] = 1; dp[2] = 2; dp[3] = 4;

    for (int i = 4; i <= 1000000; i++)
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int N;
        
        cin >> N;
        
        cout << dp[N] << '\n';
    }
}