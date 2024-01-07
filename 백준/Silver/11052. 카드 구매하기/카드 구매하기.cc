#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;

	cin >> N;

	int *price = new int[N];
	int* dp = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> price[i];
		dp[i] = price[i];
	}

	for (int i = 1; i < N; i++)
		for (int j = 1; j <= i; j++)
			dp[i] = max(dp[i], dp[i - j] + price[j - 1]);

	cout << dp[N - 1];

	delete[] price;
	delete[] dp;
}