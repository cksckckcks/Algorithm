#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	
	cin >> n;

	int* dp = new int[n + 1];
	for (int i = 0; i <= n; i++)
		dp[i] = i;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j * j <= i; j++)
			dp[i] = min(dp[i], dp[i - j * j] + 1);

	cout << dp[n];

	delete[] dp;
}