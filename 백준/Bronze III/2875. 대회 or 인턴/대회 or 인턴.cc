#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M, K;

	cin >> N >> M >> K;

	int answer = min(N / 2, M);
	answer = min(answer, (N + M - K) / 3);
	cout << answer;
}