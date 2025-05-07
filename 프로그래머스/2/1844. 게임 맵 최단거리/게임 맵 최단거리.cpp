#include <queue>
#include <vector>
#include <utility>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int visited[101][101];

int solution(vector<vector<int> > maps)
{
    int maxX = maps.size();
    int maxY = maps[0].size();
    queue <pair<int, int>> q;
    
    q.push({0, 0});
    visited[0][0] = 1;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if (x == maxX - 1 && y == maxY - 1)
            return visited[maxX - 1][maxY - 1];
        
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if (xx >= maxX || xx < 0 || yy >= maxY || yy < 0 || visited[xx][yy] || maps[xx][yy] == 0)
                continue;
            
            q.push({xx, yy});
            visited[xx][yy] = visited[x][y] + 1;
        }
    }
    
    return -1;
}