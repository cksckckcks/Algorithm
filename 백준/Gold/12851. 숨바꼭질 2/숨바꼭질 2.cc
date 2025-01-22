#include <iostream>
#include <queue>

int N, K, now;
int minTime[100001];
int cnt[100001];

using namespace std;

void bfs() {
    queue<int> q;

    q.push(N);

    minTime[N] = 0;

    fill(cnt, cnt + 100001, 1);

    while(!q.empty()) {
        now = q.front();
        q.pop();

        if (now == K)
            return;
        
        if (now - 1 >= 0 && minTime[now - 1] == 0) {
            minTime[now - 1] = minTime[now] + 1;
            cnt[now - 1] = cnt[now];
            q.push(now - 1);
        }
        else if(now - 1 >= 0  && minTime[now - 1] == minTime[now] + 1)
            cnt[now - 1] += cnt[now];
        if (now + 1 <= 100000 && minTime[now + 1] == 0) {
            minTime[now + 1] = minTime[now] + 1;
            cnt[now + 1] = cnt[now];
            q.push(now + 1);
        }
        else if(now + 1 <= 100000 && minTime[now + 1] == minTime[now] + 1)
            cnt[now + 1] += cnt[now];
        if (now != 0 && now * 2 <= 100000 && minTime[now * 2] == 0) {
            minTime[now * 2] = minTime[now] + 1;
            cnt[now * 2] = cnt[now];
            q.push(now * 2);
        }
        else if(now != 0 && now * 2 <= 100000 && minTime[now * 2] == minTime[now] + 1)
            cnt[now * 2] += cnt[now];
    }
}


int main() {
    cin >> N >> K;

    bfs();

    cout << minTime[K] << '\n' << cnt[K];    
}