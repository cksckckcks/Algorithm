#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int T;

    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;

        cin >> N;

        vector <pair<int, int>> v;

        for (int j = 0; j < N; j++) {
            int a, b;

            cin >> a >> b;

            v.push_back({a, b});
        }

        sort(v.begin(), v.end());

        int tmp = 0, cnt = 1;
        for (int j = 1; j < N; j++) {
            if (v[tmp].second > v[j].second) {
                cnt++;
                tmp = j;
            }
        }
        
        cout << cnt << '\n';
    }
}