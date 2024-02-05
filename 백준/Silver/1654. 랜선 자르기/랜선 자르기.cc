#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector <long long> v;
	long long K, N, maxLength = -1, answer = -1;

	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		long long n;
		
		cin >> n;
		
		v.push_back(n);
		maxLength = max(n, maxLength); // max의 길이를 넘을 수 없음을 이용
	}

	long long left = 1, right = maxLength, mid = 0; // 이진탐색 초기 위치 세팅

	while (left <= right) {
		mid = (left + right) / 2;

		int cnt = 0;

		// 나오는 랜선 개수 카운트
		for (int i = 0; i < K; i++)
			cnt += v[i] / mid;

		// 이진탐색
		if (cnt < N)
			right = mid - 1;
		else {
			left = mid + 1;
			answer = max(mid, answer);
		}
	}

	cout << answer;
}