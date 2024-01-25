#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector <int> v;
int visited[100001] = { 0, };
bool finished[100001] = { 0, }; // 검색으로 도움 받음. 시간 지나고 다시 풀어보자!
int answer;

void dfs(int x) {
	visited[x] = 1;
    
	if (!visited[v[x - 1]])
		dfs(v[x - 1]);
	else if (!finished[v[x - 1]]) {
	    for (int i = v[x - 1]; i != x; i = v[i - 1])
	        answer++;
	    answer++;
	}
	finished[x] = 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;

	cin >> T;

	while (T--) {
		int n;

		cin >> n;

		for (int i = 0; i < n; i++) {
			int num;

			cin >> num;

			v.push_back(num);
		}

		answer = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i])
			    dfs(i);
		}

		cout << n - answer << '\n';
		
		memset(visited, 0, sizeof(visited));
		memset(finished, 0, sizeof(finished));
		v.clear();
	}
}