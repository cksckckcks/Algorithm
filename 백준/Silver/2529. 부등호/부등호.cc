#include <iostream>
#include <algorithm>

using namespace std;
   
int k;
vector<bool> v; // 0 : >, 1 : <
vector<int> ans;
bool visited[10];
bool max_check, min_check;

void max_dfs() {
    if (max_check)
        return;
    if (ans.size() == k + 1) {
        for (int i = 0; i <= k; i++)
            cout << ans[i];
        cout << '\n';
        max_check = 1;
        return;
    }

    for (int i = 9; i >= 0; i--) {
        if (!visited[i]) {
            if (v[ans.size() - 1] && ans[ans.size() - 1] > i)
                continue;
            if (!v[ans.size() - 1] && ans[ans.size() - 1] < i)
                continue;
            ans.push_back(i);
            visited[i] = 1;
            max_dfs();
            ans.pop_back();
            visited[i] = 0;
        }
    }
}

void min_dfs() {
    if (min_check)
        return;
    if (ans.size() == k + 1) {
        for (int i = 0; i <= k; i++)
            cout << ans[i];
        cout << '\n';
        min_check = 1;
        return;
    }
    for (int i = 0; i <= 9; i++) {
        if (!visited[i]) {
            if (v[ans.size() - 1] && ans[ans.size() - 1] > i)
                continue;
            if (!v[ans.size() - 1] && ans[ans.size() - 1] < i)
                continue;
            ans.push_back(i);
            visited[i] = 1;
            min_dfs();
            ans.pop_back();
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> k;

    for (int i = 0; i < k; i++) {
        char c;

        cin >> c;
        if (c == '>')
            v.push_back(0);
        else
            v.push_back(1);
    }

    for (int i = 9; i >= 0; i--) {
        if (max_check)
            break;
        ans.clear();
        ans.push_back(i);
        visited[i] = 1;
        max_dfs();
        visited[i] = 0;
    }
    fill(visited, visited + 10, 0);
    for (int i = 0; i <= 9; i++) {
        if (min_check)
            break;
        ans.clear();
        visited[i] = 1;
        ans.push_back(i);
        min_dfs();
        visited[i] = 0;
    }
}