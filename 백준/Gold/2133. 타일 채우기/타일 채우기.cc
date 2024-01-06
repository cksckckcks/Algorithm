#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    
    cin >> N;
    
    if(N % 2) {
        cout << 0;
        return 0;
    }
    
    int *dp = new int[N + 1];
    dp[0] = 1; dp[1] = 0; dp[2] = 3;
    
    for(int i = 4; i <= N; i+=2) {
        dp[i] = dp[i - 2] * 3;
        for(int j = 4; j <= i; j+=2)
            dp[i] += dp[i - j] * 2;
    }
    
    cout << dp[N];
    delete[] dp;
}