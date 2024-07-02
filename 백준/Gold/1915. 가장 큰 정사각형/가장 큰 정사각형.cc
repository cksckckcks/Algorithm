#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int v[1001][1001];
    int n, m, check = 0;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string s;

        cin >> s;

        for (int j = 1; j <= m; j++) {
            v[i][j] = s[j - 1] - '0';
        }
    }

    int maxSize = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!v[i][j])
                continue;
            v[i][j] = min({v[i][j - 1], v[i - 1][j], v[i - 1][j - 1]}) + 1;
            maxSize = max(maxSize, v[i][j]);
        }
    }

    cout << maxSize * maxSize;
}