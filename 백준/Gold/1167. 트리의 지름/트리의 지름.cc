#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector <pair <int, int>> v[100001];
bool visited[100001] = { 0, };
int n, maxLength = -1, dfsNode = -1;

void dfs(int n, int cnt) {
    visited[n] = 1;
    for (int i = 0; i < v[n].size(); i++) {
        if (!visited[v[n][i].first]) {
            if (maxLength < cnt + v[n][i].second) {
                dfsNode = v[n][i].first;
                maxLength = cnt + v[n][i].second;
            }
            dfs(v[n][i].first, cnt + v[n][i].second);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c; // a : 부모 노드, b : 자식 노드, c : 노드 간 거리

        cin >> a;
        while (1) {
            cin >> b;

            if (b == -1) break;

            cin >> c;

            v[a].push_back(make_pair(b, c));
        }
    }

    dfs(1, 0);
    memset(visited, 0, sizeof(visited));    
    maxLength = -1;
    // cout << "dfsNode : " << dfsNode << endl;
    dfs(dfsNode, 0);

    cout << maxLength;
}

// 자식이 없는 노드로 진행 >> X 
// 최대 긴 경로를 찾고 그 마지막 노드에서 dfs >> X 생각해보니 이건 당연히 아니네요?
// root에서 시작하여 가장 큰 값을 가지는 경로에서 검색하는 방법