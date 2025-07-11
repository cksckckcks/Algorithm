#include <stdio.h>
int arr[100][100] = {};
int main() {
	int x, y, N;
	int A = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x, &y);
		for (int j = x - 1; j < x - 1 + 10; j++)
			for (int k = y - 1; k < y - 1 + 10; k++)
				arr[j][k] = 1;
	}

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (arr[i][j] == 1)
				A += 1;

	printf("%d", A);
}