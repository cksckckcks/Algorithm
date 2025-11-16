#include <iostream>
#include <algorithm>

using namespace std;
 
int graph[100001][3];
int dp[100001][3];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int cnt = 1;
    
    while (true) {
        int N;

        cin >> N;
 
        if (N == 0)
            break;
 
        for (int i = 0; i < N; i++)
            cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
 
        dp[0][0] = 987654321;
        dp[0][1] = min(graph[0][1], dp[0][0] + graph[0][1]);
        dp[0][2] = graph[0][1] + graph[0][2];
 
        for (int i = 1; i < N; i++) {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + graph[i][0];
            dp[i][1] = min(min(dp[i - 1][0], dp[i - 1][1]), min(dp[i - 1][2], dp[i][0])) + graph[i][1];
            dp[i][2] = min(min(dp[i - 1][1], dp[i - 1][2]), dp[i][1]) + graph[i][2];
        }
 
        cout << cnt++ << ". " << dp[N - 1][1] << '\n';
    }
}
