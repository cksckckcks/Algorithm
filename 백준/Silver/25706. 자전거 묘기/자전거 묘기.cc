#include <iostream>
using namespace std;

int main() {
	int n, cnt;
		cin >> n;

	int* arr = new int[n];
	int* ans = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	

	//DP 식 구하기?
	ans[n - 1] = 1;
	// DP = ans[arr[i] + i + 1] + 1
	for (int i = n - 2; i >= 0; i--) {
		if ((arr[i] + i + 1) > (n - 1))
			ans[i] = 1;
		else
			ans[i] = ans[arr[i] + i + 1] + 1;
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}

	/* 시간초과 뜬 코드.
	for (int i = 0; i < n; i++) {
		cnt = 0;
		for (int j = i; j < n;) {
			j += (1 + arr[j]);
			cnt++;
		}
		cout << cnt << " ";
	}
	*/
	delete[] arr;
	delete[] ans;
}