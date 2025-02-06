#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    vector<int> v;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int n;

        cin >> n;

        v.push_back(n);
    }

    sort(v.begin(), v.end());

    int left = 0, right = 1, ans = 2000000001;

    while (left < N && right < N) {
        int tmp = v[right] - v[left];

        if (tmp >= M) {
            ans = min(ans, tmp);
            left++;
        } 
        else
            right++;
    }

    cout << ans;
}