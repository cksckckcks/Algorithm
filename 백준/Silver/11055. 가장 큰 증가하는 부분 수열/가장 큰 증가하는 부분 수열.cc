#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;

    cin >> N;

    int* arr = new int[N];
    int* dp = new int[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N; i++) {
        int n = 0;
        dp[i] = arr[i];
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + arr[i]);
    }

    int result = 0;
    for (int i = 0; i < N; i++)
        if (result < dp[i])
            result = dp[i];
    cout << result;

    delete[] arr;
    delete[] dp;
}