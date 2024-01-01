#include <iostream>
using namespace std;

int main() {
	int N;

	cin >> N;

	int** arr = new int*[N];
	for (int i = 0; i < N; i++)
		arr[i] = new int[10];

	arr[0][0] = 0;
	for (int i = 1; i < 10; i++)
		arr[0][i] = 1;
	
	for (int i = 1; i < N; i++) {
		arr[i][0] = arr[i - 1][1];
		arr[i][9] = arr[i - 1][8];
		for (int j = 1; j < 9; j++)
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % 1000000000;
	}

	int sum = 0;
	for (int i = 0; i < 10; i++)
		sum = (sum + arr[N - 1][i]) % 1000000000;

	cout << sum;
	for (int i = 0; i < N; ++i)
		delete[] arr[i];
	delete[] arr;
}