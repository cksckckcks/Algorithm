#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, K;
int ans[100001];
int road[100001];

void bfs() {
    queue<int> q;
    fill(road, road + 100001, -1);
    fill(ans, ans + 100001, -1);
    q.push(N);

    ans[N] = 0;
    road[N] = 0;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (now - 1 >= 0 && ans[now - 1] == -1) {
            ans[now - 1] = ans[now] + 1;
            road[now - 1] = now;
            q.push(now - 1);
        }
        if (now + 1 <= 100000 && ans[now + 1] == -1) {
            ans[now + 1] = ans[now] + 1;
            road[now + 1] = now;
            q.push(now + 1);
        }
        if (now * 2 <= 100000 && ans[now * 2] == -1) {
            ans[now * 2] = ans[now] + 1;
            road[now * 2] = now;
            q.push(now * 2);
        }
    }
}

void print_load(int n) {
    if (n == N)
        return;
    print_load(road[n]);
    cout << road[n] << ' ';
}

int main() {
    cin >> N >> K;

    bfs();

    cout << ans[K] << '\n';
    print_load(K);
    cout << K << ' ';
}