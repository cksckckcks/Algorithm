#include <iostream>
#include <queue>
using namespace std;

int N, M, V;
int arr[1001][1001] = { 0, }; // 인접행렬
bool visited_dfs[1001] = { 0, }; // 모두 방문 X
bool visited_bfs[1001] = { 0, }; // 모두 방문 X
queue <int> q;

// 깊이 우선 탐색
void dfs(int x) {
	visited_dfs[x] = 1; // 방문 처리
	cout << x << " "; // 출력

	// 자식 노드들 다 탐색 (방문 확인 후 안했다면 재귀)
	for (int i = 0; i <= N; i++)
		if (arr[x][i] == 1 && visited_dfs[i] == 0) // 방문 확인 후 안했다면 재귀
			dfs(i);
}

// 너비 우선 탐색
void bfs(int start) {
	q.push(start); // 시작 노드를 먼저 큐에 push

	while (q.empty() == 0) {
		// 방문 처리, 출력, pop 진행
		int next = q.front(); 
		visited_bfs[next] = 1;
		cout << next << " ";
		q.pop();

		// pop한 노드와 연결된 노드 모두 큐에 push
		for (int i = 0; i <= N; i++)
			if (arr[next][i] == 1 && visited_bfs[i] == 0) { // 방문 확인 후 안했다면 큐에 push
				q.push(i);
				visited_bfs[i] = 1; // 안하면 중복으로 방문될 수 있음
			}
	}
}

int main() {
	cin >> N >> M >> V;
	
	while (M--) {
		int n, n2;

		cin >> n >> n2;
		arr[n][n2] = arr[n2][n] = 1;
	}

	dfs(V); 
	cout << '\n';
	bfs(V);
}