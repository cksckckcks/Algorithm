#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;

    cin >> t;

    while (t--) {
        vector<int> v, v1;
        int n, m;

        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            int num;

            cin >> num;

            v.push_back(num);
        }
        for (int i = 0; i < m; i++) {
            int num;

            cin >> num;

            v1.push_back(num);
        }

        sort(v.begin(), v.end());
        sort(v1.begin(), v1.end());

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int left = 0;
            int right = m - 1;
            int cnt = 0;

            while (left <= right) {
                int mid = (left + right) / 2;

                if (v1[mid] < v[i]) {
                    cnt = mid + 1;
                    left = mid + 1;
                }
                else 
                    right = mid - 1;
            }

            ans += cnt;
        }

        cout << ans << '\n';
    }
}