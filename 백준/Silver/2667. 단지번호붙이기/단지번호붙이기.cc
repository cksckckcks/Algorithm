#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int arr[26][26] = { 0, };
bool visited[26][26] = { 0, };
vector <int> v;
int cnt;

int dfs(int x, int y) {
	visited[x][y] = 1;
	cnt++;

	if (arr[x - 1][y] == 1 && !visited[x - 1][y])
		dfs(x - 1, y);
	if (arr[x + 1][y] == 1 && !visited[x + 1][y])
		dfs(x + 1, y);
	if (arr[x][y - 1] == 1 && !visited[x][y - 1])
		dfs(x, y - 1);
	if (arr[x][y + 1] == 1 && !visited[x][y + 1])
		dfs(x, y + 1);
	return cnt;
}

int main() {
	int N;
	
	cin >> N;

	for (int i = 1; i <= N; i++) {
		string s;

		cin >> s;

		for (int j = 1; j <= N; j++)
			arr[i][j] = s[j - 1] - '0';
	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] && !visited[i][j]) {
				answer++;
				cnt = 0;
				v.push_back(dfs(i, j));
			}
		}

	sort(v.begin(), v.end());
	cout << answer << '\n';
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';
}