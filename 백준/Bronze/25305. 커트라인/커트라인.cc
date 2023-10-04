#include <stdio.h>

int main() {
	int k, N, n, arr[1001] = { 0, };

	scanf("%d %d", &N, &k);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i] > arr[j]) {
				n = arr[i];
				arr[i] = arr[j];
				arr[j] = n;
			}
		}
	}

	printf("%d", arr[k-1]);
}