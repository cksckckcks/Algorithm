#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	map<long long, int> m;
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		long long n;

		cin >> n;
		
		m[n]++;
	}


	long long maxKey = -1; 
	long long maxValue = -1;
	for (const auto& pair : m) {
		if (pair.second > maxValue) {
			maxKey = pair.first;
			maxValue = pair.second;
		}
	}

	cout << maxKey;
}