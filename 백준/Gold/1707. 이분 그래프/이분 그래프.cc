#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int K, V, E;
vector <int>v[20001]; // vector로 인접 리스트
bool visited[20001] = { 0, };
int color[20001] = { 0, };
bool check = true;

void dfs (int x) {
    int myColor;
    int nextColor;

    if(visited[x])
        return;

    visited[x] = 1;
    myColor = color[x];
    if (myColor == 0) {
        color[x] = 1;
        myColor = 1;
        nextColor = 2;
    }
    else if (myColor == 1)
        nextColor = 2;
    else
        nextColor = 1;

    for (int i = 0; i < v[x].size(); i++) {
        if (color[v[x][i]] == 0)
            color[v[x][i]] = nextColor;
        if (color[v[x][i]] == myColor) {
            check = false;
            return;
        }
        if (!visited[v[x][i]])
            dfs(v[x][i]);
    }
}

int main () {
    cin >> K;

    while (K--) {
        cin >> V >> E;

        for (int i = 0; i < E; i++) {
        int a, b;

        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        }

        for (int i = 1; i <= V; i++)
            dfs(i);
        if(check)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';

        for (int i = 1; i <= V; i++)
            v[i].clear();
        memset(visited, 0, sizeof(visited));
        memset(color, 0, sizeof(color));
        check = true;
    }
}
