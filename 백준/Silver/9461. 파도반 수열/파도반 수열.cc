#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;

		long long* dp = new long long[n]; // 값이 int를 넘어감 (오버플로우) > long long
		dp[0] = 1; dp[1] = 1; dp[2] = 1;

		for (int j = 3; j < n; j++)
			dp[j] = dp[j - 3] + dp[j - 2];

		cout << dp[n - 1] << '\n';
		delete[] dp;
	}
}