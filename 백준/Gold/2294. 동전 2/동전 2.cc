#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int main(){
    vector<int> v;
    int n, k;

    cin >> n >> k;

    int *dp = new int[k + 1];
    
    for (int i = 0; i <= k; i++) // memset에서 -1, 0으로 초기화하는게 아니라면 오버플로우 발생 가능
      dp[i] = 10001;
    for (int i = 0; i < n; i++) {
      int num;

      cin >> num;
      v.push_back(num);
      dp[num] = 1;
    }

  for (int i = 0; i < v.size(); i++)
    for (int j = v[i]; j <= k; j++)
      dp[j] = min(dp[j], dp[j - v[i]] + 1);

  if (dp[k] == 10001)
    cout << -1;
  else
    cout << dp[k];
}