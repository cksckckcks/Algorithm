#include <string>
#include <vector>

using namespace std;

bool visited[201];

void dfs(int n, vector<vector<int>> computers, int computer) {
    visited[computer] = 1;
    
    for (int i = 0; i < n; i++) {
        if (computers[computer][i] && !visited[i]) {
            dfs(n, computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(n, computers, i);
            answer++;
        }
    }
    
    return answer;
}