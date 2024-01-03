#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;

    cin >> N;

    int* arr = new int[N];
    int* dp = new int[N];
    int* dp2 = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        dp[i] = 1;
        dp2[i] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        for (int j = N - 1; j > N - i - 1; j--)
            if (arr[N - i - 1] > arr[j])
                dp2[N - i - 1] = max(dp2[N - i - 1], dp2[j] + 1);
    }

    int max = 0;
    for (int i = 0; i < N; i++)
        if (max < dp[i] + dp2[i] - 1)
            max = dp[i] + dp2[i] - 1;
    cout << max;

    delete[] arr;
    delete[] dp;
    delete[] dp2;
}