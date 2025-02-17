#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][1001];
int candy[1001][1001];

int main() {
	int N, M;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int n;
			
			cin >> n;

			candy[i][j] = n;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] += max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + candy[i][j];
		}
	}

	cout << dp[N][M];
}
