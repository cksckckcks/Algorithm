#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, ans = 0;
	int rope[100000];

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> rope[i];

	sort(rope, rope + N);

	for (int i = 0; i < N; i++)
		ans = max(ans, (N - i)*rope[i]);

	cout << ans;
}