#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int money = 5000000;
	int T, n;
	long long ans;
	vector<int> v;

	cin >> T;

	for (int i = 0; i < T; i++) {
		ans = 0; n = -1;

		while (1) {
			cin >> n;
			if (n == 0)
				break;
			v.push_back(n);
		}

		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());

		for (int j = 0; j < v.size(); j++) {
			ans += (2 * pow(v[j], j + 1));
		}

		if (ans > money)
			cout << "Too expensive" << endl;
		else
			cout << ans << endl;

		v.clear();
	}
}