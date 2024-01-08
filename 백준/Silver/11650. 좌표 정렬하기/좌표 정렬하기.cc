#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<pair<int, int>> v;
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int n, n2;

		cin >> n >> n2;
		v.push_back(make_pair(n, n2));
	}

	sort(v.begin(), v.end());
	
	for (int i = 0; i < N; i++)
		cout << v[i].first << " " << v[i].second << '\n';
}