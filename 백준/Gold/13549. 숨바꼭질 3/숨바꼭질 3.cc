#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, K, now;
int ans[100001];

int bfs() {
    fill(ans, ans + 100001, -1);
    queue<int> q;

    q.push(N);
    ans[N] = 0;

    while (!q.empty()) {
        now = q.front();
        q.pop();

        if (now == K)
            return ans[K];

        if (now * 2 <= 100000 && (ans[now * 2] == -1 || ans[now * 2] > ans[now])) {
            ans[now * 2] = ans[now];
            q.push(now * 2);
        }
        if (now + 1 <= 100000 && (ans[now + 1] == -1 || ans[now + 1] > ans[now] + 1)) {
            ans[now + 1] = ans[now] + 1;
            q.push(now + 1);
        }
        if (now - 1 >= 0 && (ans[now - 1] == -1 || ans[now -  1] > ans[now] + 1)) {
            ans[now - 1] = ans[now] + 1;
            q.push(now - 1);
        }
    }
    return ans[K];
}

int main() {
    cin >> N >> K;

    cout << bfs();
}