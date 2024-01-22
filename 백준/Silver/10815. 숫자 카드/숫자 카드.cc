#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	map <int, int> m;
	int N, M;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;

		cin >> n;

		m[n] = 1;
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		int n;

		cin >> n;

		cout << m[n] << " ";
	}
}