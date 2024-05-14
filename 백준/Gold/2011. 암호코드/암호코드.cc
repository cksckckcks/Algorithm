#include <iostream>
#include <vector>
using namespace std;

int main() {
  string s;
  long long dp[5001] = { 0, };
  
  cin >> s;

  if (s[0] == '0') { // 0으로 시작하는 암호 X >> 0출력
    cout << 0;
    return 0;
  }

  dp[0] = 1;
  dp[1] = 1;
  
  for (int i = 2; i <= s.length(); i++) {
    int n = (s[i - 2] - '0') * 10 + s[i - 1] - '0';

    if (n == 0 || (n > 20 && n % 10 == 0)) {
      cout << 0;
      return 0;
    }
    
    if (s[i - 1] == '0') // 현재 보고있는 친구가 0이면
      dp[i] = dp[i - 2] % 1000000; // 이전 결과가 상관 없어진다. (0이 꼭 앞 숫자에 붙게 된다.)
    else if (n >= 10 && n <= 26)
      dp[i] = (dp[i - 2] + dp[i - 1]) % 1000000;
    else
      dp[i] = dp[i - 1] % 1000000;
    
  }
  
  cout << dp[s.length()];
}
