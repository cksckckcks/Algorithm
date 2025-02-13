#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int T, h, w, ans;
bool keys[26];
bool visited[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<string> v;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;

    while (!q.empty()) {
        auto [x, y] = q.front(); // 구조 분해 할당
        q.pop();

        if (v[x][y] == '$')
            ans++;

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx < 0 || xx >= h || yy < 0 || yy >= w)
                continue;    
            if (visited[xx][yy] || v[xx][yy] == '*')
                continue;

            if (v[xx][yy] == '.') {
                visited[xx][yy] = 1;
                q.push({xx, yy});
            }
            else if (v[xx][yy] >= 'A' && v[xx][yy] <= 'Z' && keys[v[xx][yy] - 'A']) {
                visited[xx][yy] = 1;
                q.push({xx, yy});
            }
            else if (v[xx][yy] >= 'a' && v[xx][yy] <= 'z') {
                visited[xx][yy] = 1;
                keys[v[xx][yy] - 'a'] = 1;
                q.push({xx, yy});
            }
            else if (v[xx][yy] == '$') {
                visited[xx][yy] = 1;
                q.push({xx, yy});
            }
        }
    }
}

bool side_check(int x, int y) {

    if (x == 0 || x == h - 1 || y == 0 || y == w - 1)
        return 1;
    for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx < 0 || xx >= h || yy < 0 || yy >= w)
                continue;

            if (visited[xx][yy])
                return 1;
    }
    return 0;
}

int main() {
    cin >> T;

    for (int i = 0; i < T; i++) {
        v.clear();
        ans = 0;
        fill(keys, keys + 26, 0);
        for (int i = 0; i < 101; i++)
            fill(visited[i], visited[i] + 101, 0);

        cin >> h >> w;

        for (int j = 0; j < h; j++) {
            string s;

            cin >> s;

            v.push_back(s);
        }

        string s;

        cin >> s;
        
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '0')
                break;
            keys[s[j] - 'a'] = 1;
        }
        
        for (int j = 0; j < h; j++) {
            if (j == 0 || j == (h - 1)) {
                for (int k = 0; k < w; k++) {
                    if (visited[j][k] || v[j][k] == '*')
                        continue;
                    
                    if (v[j][k] == '.' || v[j][k] == '$' || (v[j][k] >= 'A' && v[j][k] <= 'Z' && keys[v[j][k] - 'A']))
                        bfs(j, k);
                    else if(v[j][k] >= 'a' && v[j][k] <= 'z') {
                        keys[v[j][k] - 'a'] = 1;
                        bfs(j, k);
                    }
                }
            }
            else {
                int tmp[2] = {0, w - 1};

                for (int k : tmp) {
                    if (visited[j][k] || v[j][k] == '*')
                        continue;
                    
                    if (v[j][k] == '.' || v[j][k] == '$' || (v[j][k] >= 'A' && v[j][k] <= 'Z' && keys[v[j][k] - 'A']))
                        bfs(j, k);
                    else if(v[j][k] >= 'a' && v[j][k] <= 'z') {
                        keys[v[j][k] - 'a'] = 1;
                        bfs(j, k);
                    }
                }
            }
        }

        int cnt = 1;
        while (cnt) {
            cnt = 0;

            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (!visited[i][j] && v[i][j] >= 'A' && v[i][j] <= 'Z' && keys[v[i][j] - 'A'] && side_check(i, j)) {
                        bfs(i, j);
                        cnt++;
                    }
                }
            }
        }

        cout << ans << '\n';

    }
}