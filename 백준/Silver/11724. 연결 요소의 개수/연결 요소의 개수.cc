#include <iostream>
using namespace std;

int arr[1001][1001] = { 0, };
bool visited[1001] = { 0, };
int N, M;

bool dfs(int x) {
	if (visited[x] == 0) {
		visited[x] = 1;
		for (int i = 0; i <= N; i++)
			if (arr[x][i] == 1 && visited[i] == 0)
				dfs(i);
		return true;
	}
	else
		return false;
}

int main() {
	cin >> N >> M;

	while (M--) {
		int n1, n2;

		cin >> n1 >> n2;

		arr[n1][n2] = arr[n2][n1] = 1;
	}
	
	int answer = 0;
	for (int i = 1; i <= N; i++)
		if (dfs(i))
			answer++;

	cout << answer;
}