#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
	if (a.size() != b.size())
		return a.size() < b.size();
	else {
		int sumA = 0;
		for (int i = 0; i < a.size(); ++i)
			if (a[i] - '0' <= 9 && a[i] - '0' >= 0)
				sumA += a[i] - '0';

		int sumB = 0;

		for (int i = 0; i < b.size(); ++i)
			if (b[i] - '0' <= 9 && b[i] - '0' >= 0)
				sumB += b[i] - '0';

		if (sumA != sumB)
			return sumA < sumB;
		else
			return a < b;
	}
}

int main() {
    int N;
	vector<string> v;

	cin >> N;

	for(int i = 0; i < N; ++i) {
		string s;

		cin >> s;

		v.push_back(s);
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); ++i)
        cout << v[i] << endl;
}