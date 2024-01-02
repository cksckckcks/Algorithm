#include <iostream>
#include <algorithm> // max 헤더파일 max에 여러 값을 넣을 때 {}안에 넣기.
using namespace std;

int main() {
	int n;

	cin >> n;

	int* arr = new int[n + 1];
	int* dp = new int[n + 1];

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[0] = 0; dp[1] = arr[1]; dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; i++)
		dp[i] = max({ dp[i - 1],(arr[i] + arr[i - 1] + dp[i - 3]), (arr[i] + dp[i - 2]) });

	cout << dp[n];
	delete[] arr;
	delete[] dp;
}