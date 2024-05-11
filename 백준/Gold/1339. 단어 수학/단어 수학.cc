#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main() {
  vector<string> v;
  set<pair<int, char>> ps;
  map<char, int> m;
  int alpha[26] = {0, };
  int N;

  cin >> N;
  
  for (int i = 0; i < N; i++) {
    string s;

    cin >> s;
    v.push_back(s);

    int priority = 1;
    for (int j = s.length() - 1; j >= 0; j--) {
      alpha[(s[j] - 'A')] += priority;
      priority *= 10;
    }
  }

  for (int i = 0; i < 26; i++)
    if(alpha[i] != 0)
      ps.insert(make_pair(alpha[i], 'A' + i));

  int num = 10 - ps.size();
  for (const auto& it : ps) {
    m.insert(make_pair(it.second, num));
    num++;
  }
  
  int sum = 0;
  for (int i = 0; i < N; i++){
    int sSum = 0;
    for (int j = 0; j < v[i].length(); j++)
      sSum = sSum * 10 + m.at(v[i][j]);
    sum += sSum;
  }
  
  cout << sum;
 }