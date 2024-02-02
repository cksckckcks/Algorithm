#include <iostream>
#include <vector>
using namespace std;

vector <int> v[100001];
bool visited[100001] = { 0, };
int answerArr[100001] = { 0, };
int N;

void dfs(int n) {
    visited[n] = 1;
    for (int i = 0; i < v[n].size(); i++) {
        if (!visited[v[n][i]]) {
            answerArr[v[n][i]] = n;
            dfs(v[n][i]);
        }
    }
}
int main() {
    cin >> N;

    for (int i = 1; i < N; i++) {
        int a, b;

        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);

    for (int i = 2; i <= N; i++)
        cout << answerArr[i] << '\n';
}