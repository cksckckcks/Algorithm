#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector <pair <int, int>> v[10001];
bool visited[10001] = { 0, };
int n, maxLength = -1, maxTreeLength = 0; // n을 기준으로 first = 가장 긴 경로

void dfs(int n, int cnt) {
	visited[n] = 1;
	for (int i = 0; i < v[n].size(); i++) {
		if (!visited[v[n][i].first]) {
			if (maxTreeLength < cnt + v[n][i].second)
				maxTreeLength = cnt + v[n][i].second;
			dfs(v[n][i].first, cnt + v[n][i].second);
		}
	}
}

int main() {
	cin >> n;

	for (int i = 1; i < n; i++) {
		int a, b, c; // a : 부모 노드, b : 자식 노드, c : 노드 간 거리

		cin >> a >> b >> c;

		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		maxTreeLength = 0;
		dfs(i, 0);
		if (maxLength < maxTreeLength)
			maxLength = maxTreeLength;
	}

	cout << maxLength;
}