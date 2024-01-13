#include <stdio.h>
#include <string.h>

int main() {
	int N = -1, cnt = 1, answer, temp, n;
	char name_1[21][11];
	char name_2[21][11];
	int int_arr[21];

	while (1) {
		scanf("%d", &N);
		if (N == 0)
			break;

		for (int i = 0; i < N; i++) {
			scanf("%s %s", &name_1[i], &name_2[i]);
		}

		answer = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (strcmp(name_1[i], name_2[j]) == 0) {
					int_arr[j] = i;
				}	
			}
		}

		

		
		for (int i = 0; i < N; i++) {
			if (int_arr[i] == -1)
				continue;
			n = int_arr[i];
			for (int j = 0; j < N; j++) {
				if (i == int_arr[n]) {
					answer++;
					int_arr[n] = -1;
					break;
				}
				else{
					temp = int_arr[n];
					int_arr[n] = -1;
					n = temp;
				}
			}
		}
		printf("%d %d\n", cnt++, answer);
	}
}