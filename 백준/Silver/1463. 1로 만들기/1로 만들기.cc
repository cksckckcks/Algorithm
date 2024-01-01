#include <iostream>
using namespace std;

int main() {
	int n;

	cin >> n;

	int* arr = new int[n + 1];
	for (int i = 0; i <= n; i++) {
		if (i == 0 || i == 1) {
			arr[i] = 0;
			continue;
		}
		arr[i] = arr[i - 1] + 1;
		if (i % 3 == 0)
			arr[i] = arr[i] > arr[i / 3] ? arr[i / 3] + 1 : arr[i];
		if (i % 2 == 0)
			arr[i] = arr[i] > arr[i / 2] ? arr[i / 2] + 1 : arr[i];
	}

	cout << arr[n];
	delete[] arr;
}