#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, ans = 0;
    vector<int> v;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int n;

        cin >> n;
        
        v.push_back(n);
    }
    
    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++) {
        int n = v[i];
        int left = 0, right = N - 1;

        while (left < right) {
            if (left == i) {
                left++;
                continue;
            }
            if (right == i) {
                right--;
                continue;
            }

            int sum = v[left] + v[right];

            if (sum == n) {
                ans++;
                break;
            }
            else if (sum < n)
                left++;
            else
                right--;
        }
    }

    cout << ans;
}