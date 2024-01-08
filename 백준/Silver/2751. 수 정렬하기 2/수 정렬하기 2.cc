#include <iostream>
#include <set>
using namespace std;

int main() {
	set<int> s;
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;

		cin >> n;
		s.insert(n);
	}

	for (const auto& e : s) 
		cout << e << '\n';
}