#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

queue <pair<int, int>> q;
int arr[101][101] = { 0, };
bool visited[101][101] = { 0, };
int path[101][101] = { 0, };
int N, M, minPath = 100000;

void bfs(int x, int y) {
	q.push(make_pair(x, y));
	visited[x][y] = 1;
	path[x][y]++;

	while (q.empty() != 1) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		if (x == N && y == M) return;

		if (arr[x - 1][y] == 1 && !visited[x - 1][y]) {
			q.push(make_pair(x - 1, y));
			visited[x - 1][y] = 1;
			path[x - 1][y] = path[x][y] + 1;
		}
		if (arr[x + 1][y] == 1 && !visited[x + 1][y]) {
			q.push(make_pair(x + 1, y));
			visited[x + 1][y] = 1;
			path[x + 1][y] = path[x][y] + 1;
		}
		if (arr[x][y - 1] == 1 && !visited[x][y - 1]) {
			q.push(make_pair(x, y - 1));
			visited[x][y - 1] = 1;
			path[x][y - 1] = path[x][y] + 1;
		}
		if (arr[x][y + 1] == 1 && !visited[x][y + 1]) {
			q.push(make_pair(x, y + 1));
			visited[x][y + 1] = 1;
			path[x][y + 1] = path[x][y] + 1;
		}


	}
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string s;

		cin >> s;
		
		for (int j = 1; j <= M; j++)
			arr[i][j] = s[j - 1] - '0';
	}
	
	bfs(1, 1);
	cout << path[N][M];
}