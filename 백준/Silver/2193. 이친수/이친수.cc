#include <iostream>
using namespace std;

int main() {
	int N;

	cin >> N;

	long long* arr = new long long[N + 1];

	arr[0] = 0; arr[1] = 1;
	for (int i = 2; i <= N; i++)
		arr[i] = arr[i - 1] + arr[i - 2];

	cout << arr[N];
	delete[] arr;
}