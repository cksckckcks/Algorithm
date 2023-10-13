#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int N;
	long long X;
	int arr[63] = { 0, };

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> X;
		if (X != 0)
			arr[(int)log2(X)]++;
	}
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		if (arr[i] >= 2)
			arr[i + 1] += (int)arr[i] / 2;
	}
	for (int i = sizeof(arr) / sizeof(arr[0]) - 1; i >= 0; i--) {
		if (arr[i] != 0) {
			cout << (long long)pow(2, i);
			return 0;
		}
	}
}