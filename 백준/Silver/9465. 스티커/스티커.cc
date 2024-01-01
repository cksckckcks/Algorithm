#include <iostream>
using namespace std;

int main() {
	int T;

	cin >> T;

	while (T--) {
		int n;

		cin >> n;

		int** arr = new int* [2];
		for (int i = 0; i < 2; ++i)
			arr[i] = new int[n];

		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];

		if(n != 1) {
			arr[0][1] += arr[1][0];
			arr[1][1] += arr[0][0];
		}

		for (int i = 2; i < n; i++) {
			arr[0][i] += max(arr[1][i - 1], arr[1][i - 2]);
			arr[1][i] += max(arr[0][i - 1], arr[0][i - 2]);
		}
		
		int result = max(arr[0][n - 1], arr[1][n - 1]);
		cout << result << "\n";

		for (int i = 0; i < 2; ++i)
			delete[] arr[i];
		delete[] arr;
	}
}
