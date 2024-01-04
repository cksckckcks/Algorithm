#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;

	cin >> n;

	int* arr = new int[n];
	int* dp = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = arr[2] + max(arr[0], arr[1]);
	for (int i = 3; i < n; i++)
		dp[i] = max({ arr[i] + dp[i - 2], arr[i] + arr[i - 1] + dp[i - 3]});

	int answer = dp[n - 1];
	cout << answer;

	delete[] arr;
	delete[] dp;
}