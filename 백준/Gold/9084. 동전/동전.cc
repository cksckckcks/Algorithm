#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
    int T;
    
    cin >> T;

    for (int i = 0; i < T; i++) {
      vector<int> v;  
      int dp[10001] = {0, };
      int N, M;
      
      cin >> N;
      
       for (int j = 0; j < N; j++) {
         int n;

         cin >> n;
         v.push_back(n);
       }
      
      cin >> M;

      for (int i = 0; i < N; i++) {
        dp[v[i]]++;
        for (int j = v[i] + 1; j <= M; j++)
          dp[j] += dp[j - v[i]];
      }
       
        cout << dp[M] << '\n';
    }
 }