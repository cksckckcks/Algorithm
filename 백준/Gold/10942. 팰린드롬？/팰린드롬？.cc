#include <iostream>

using namespace std;

int board[2001];
bool dp[2001][2001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> board[i];
    
    cin >> M;

    for (int i = 1; i <= N; i++) {
        if (board[i] == board[i + 1])
            dp[i][i + 1] = 1;
        dp[i][i] = 1;
    }
    
    for (int i = N; i > 0; i--)
        for (int j = i + 2; j <= N; j++)
            if (board[i] == board[j] && dp[i + 1][j - 1])
                dp[i][j] = 1;

    for (int i = 0; i < M; i++) {
        int S, E;

        cin >> S >> E;

        cout << dp[S][E] << '\n';
    }
}