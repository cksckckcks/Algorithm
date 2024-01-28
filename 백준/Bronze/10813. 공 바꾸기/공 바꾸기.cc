#include <iostream>
using namespace std;

int main() {
	int N, M;
	int arr[101] = { 0, };

	cin >> N >> M;
	
	for (int i = 1; i <= N; i++)
		arr[i] = i;

	for (int i = 1; i <= M; i++) {
		int a, b;

		cin >> a >> b;

		int tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;
	}

	for (int i = 1; i <= N; i++)
		cout << arr[i] << " ";
}