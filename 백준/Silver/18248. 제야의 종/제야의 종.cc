#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<vector<int>> v;
    int N, M;
    
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        vector<int> vv;

        for (int j = 0; j < M; j++) {
            int n;

            cin >> n;
            
            vv.push_back(n);
        }

        v.push_back(vv);
    }

    sort(v.begin(), v.end());

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i - 1][j] > v[i][j]) {
                cout << "NO";

                return 0;
            }
        }
    }

    cout << "YES";
}