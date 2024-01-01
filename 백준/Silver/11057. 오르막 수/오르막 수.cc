#include <iostream>
using namespace std;

int main() {
	int N;

	cin >> N;

	int** arr = new int*[N];
	for (int i = 0; i < N; i++)
		arr[i] = new int[10];

	for (int i = 0; i < 10; i++)
		arr[0][i] = 1;
	
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			int sum = 0;
			for (int k = j; k < 10; k++)
				sum = (sum + arr[i - 1][k]) % 10007;
			arr[i][j] = sum;
		}
	}

	int sum = 0;
	for (int i = 0; i < 10; i++)
		sum = (sum + arr[N - 1][i]) % 10007;

	cout << sum;
	for (int i = 0; i < N; ++i)
		delete[] arr[i];
	delete[] arr;
}