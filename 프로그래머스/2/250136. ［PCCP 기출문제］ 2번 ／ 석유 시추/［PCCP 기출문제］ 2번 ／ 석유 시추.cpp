#include <string>
#include <vector>
#include <utility>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

bool visited[501][501];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int N, M;
int ans;
bool check[501];
int sum[501];

void bfs(vector<vector<int>> *land, int x, int y) {
    queue<pair<int, int>> q;
    set<int> s;
    int cnt = 1;
    
    memset(check, 0, sizeof(check));
    
    q.push({x, y});
    visited[x][y] = 1;
    s.insert(y);
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if (xx >= N || xx < 0 || yy < 0 || yy >= M || visited[xx][yy])
                continue;
            
            if ((*land)[xx][yy] == 1) {
                q.push({xx, yy});
                visited[xx][yy] = 1;
                if (check[yy] == 0) {
                    check[yy] = 1;
                    s.insert(yy);
                }
                cnt++;
            }   
        }
    }
    
    for (auto it : s) {
        sum[it] += cnt;
        ans = max(ans, sum[it]);
    }
}

int solution(vector<vector<int>> land) {
    N = land.size();
    M = land[0].size();
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (visited[i][j] == 0 && land[i][j])
                bfs(&land, i, j);

 
    
    return ans;
}