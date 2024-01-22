#include <iostream>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	multiset <int> s;
	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N + M; i++) {
		int n;

		cin >> n;

		s.insert(n);
	}

	for (auto& it : s)
		cout << it << " ";
}