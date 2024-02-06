#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector <long long> v;
	long long N, M, maxHight = -1;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		long long n;

		cin >> n;

		v.push_back(n);

		if (maxHight < n)
			maxHight = n;
	}

	long long left = 1, right = maxHight, mid, answer = 0;

		while (left <= right) {
		mid = (left + right) / 2;
		
		long long sum = 0;
		for (int i = 0; i < v.size(); i++)
			if (v[i] / mid != 0)
				sum += v[i] - mid; // % 연산 시 mid 의 2배 이상일 경우 짤리므로 -연산 사용

		if (M <= sum && answer < mid) { // M보다 크고, 최대값을 찾기 위해 mid와 answer과 비교
			answer = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << answer;
}