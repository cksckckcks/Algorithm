#include <iostream>

using namespace std;

int arr[1025][1025];
int sum[1025][1025];

int main() {
    ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int n;
            
            cin >> n;
            arr[i][j] = n;
        }
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];

    for (int i = 0; i < M; i++) {
        int x1, x2, y1, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        cout << sum[x2][y2] - sum[x2][y1 - 1]  - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1] << '\n';
    }
}