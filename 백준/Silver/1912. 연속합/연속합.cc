#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;

	cin >> n;

	int* arr = new int[n];
	int* dp = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}

	for (int i = 1; i < n; i++)
			dp[i] = max(dp[i], dp[i] + dp[i - 1]);

	int answer = -1001;
	for (int i = 0; i < n; i++)
		if (answer < dp[i])
			answer = dp[i];
	cout << answer;

	delete[] arr;
	delete[] dp;
}