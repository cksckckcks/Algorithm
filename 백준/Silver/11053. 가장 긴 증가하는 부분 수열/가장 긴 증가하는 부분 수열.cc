#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;

    cin >> N;

    int* arr = new int[N];
    int* dp = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }

    for (int i = 1; i < N; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);

    int max = 0;
    for (int i = 0; i < N; i++)
        if (max < dp[i])
            max = dp[i];

    cout << max;
    delete[] arr;
    delete[] dp;
}