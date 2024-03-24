#include <iostream>
using namespace std;

int main() {
    int n, k;
    
    cin >> n >> k;
    int *dp = new int[k + 1];
    
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int coin;
        cin >> coin;
        
        for (int i = 1; i <= k; i++)
            if (i - coin >= 0)
                dp[i] += dp[i - coin];
    }
    
    cout << dp[k];
    
    delete[] dp;
}