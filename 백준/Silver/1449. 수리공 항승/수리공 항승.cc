#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v;
    int N, L;

    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        int n;

        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());

    int ans = 1;
    int left = v[0];

    for (int i = 1; i < N; i++) {
        if (v[i] - left + 1 > L) {
            left = v[i];
            ans++;
        }
    }

    cout << ans;
}