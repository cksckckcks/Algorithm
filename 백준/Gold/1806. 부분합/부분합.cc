#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, S, ans = 100001;
    vector <int> v;

    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        int n;

        cin >> n;

        v.push_back(n);
    }

    int left = 0, right = 0, sum = 0;

    while (right <= N) {
        if (sum >= S) {
            ans = min(ans, right - left);
            sum -= v[left++];
        }
        else
            sum += v[right++];
    }

    cout << ((ans == 100001) ? 0 : ans);
}