#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    vector<int> v;
    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int n;

        cin >> n;

        v.push_back(n);
    }

    sort(v.begin(), v.end());

    long long ans = 0;
    for (int i = 1; i <= N; i++)
        ans += abs(v[i - 1] - i);

    cout << ans;
}