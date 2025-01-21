#include <iostream>

using namespace std;

int main() {
	int dp[10001];
	int T;
	
	cin >> T;
	
	fill_n(dp, 10001, 1);
	
	for (int i = 2; i <= 10000; i++)
		dp[i] += dp[i - 2];
	for (int i = 3; i <= 10000; i++)
		dp[i] += dp[i - 3];

    for (int i = 0; i < T; i++) {
	    int n;
	    
	    cin >> n;
	    
	    cout << dp[n] << '\n';
    }
}