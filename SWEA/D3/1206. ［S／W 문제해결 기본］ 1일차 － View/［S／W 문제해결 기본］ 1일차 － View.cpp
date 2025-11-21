#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    for (int i = 1; i <= 10; i++) {
        int n;

        cin >> n;

        int arr[1001];
        int sum = 0;

        memset(arr, 0, sizeof(arr));

        for (int j = 0; j < n; j++)
            cin >> arr[j];

        for (int j = 2; j < n - 2; j++) {
            int maxValue = max({arr[j - 2], arr[j - 1], arr[j + 1], arr[j + 2]});

            int viewCnt = arr[j] - maxValue;

            if (viewCnt > 0)
                sum += viewCnt;
        }

        cout << '#' << i << ' ' << sum << '\n';
    }
}