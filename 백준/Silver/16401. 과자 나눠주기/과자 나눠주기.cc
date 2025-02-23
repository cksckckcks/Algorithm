#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int M, N;
    vector<int> v;

    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        int n;

        cin >> n;

        v.push_back(n);
    }

    sort(v.begin(), v.end());

    int ans = 0, low = 1, high = v[N - 1];

    while (low <= high) {
        int mid = (low + high) / 2;

        int cnt = 0;
        for (int i = 0; i < N; i++)
            cnt += v[i] / mid;
        
        if (cnt >= M) {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    cout << ans;
}