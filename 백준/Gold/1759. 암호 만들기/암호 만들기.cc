#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int L, C;
vector <char> v;
bool visited[15];

bool check(string s) {
    int cons = 0; // 자음
    int vowel = 0; // 모음
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' )
            vowel++;
        else
            cons++;
    }
    
    return (vowel && cons >= 2);
}

void password(string s, int n) {
    //cout << s << n << endl;
    if (n == L) {
        if (check(s))
            cout << s << '\n';
        return ;
    }
    
    for (int i = n; i < C; i++) {
        if (visited[i] || s[s.size() - 1] >= v[i])
            continue;
        visited[i] = 1;
        char c = v[i];
        password(s + c, n + 1);
        visited[i] = 0;
    }
}

int main() {
    cin >> L >> C;
    
    for (int i = 0; i < C; i++) {
        char c;
        
        cin >> c;
        
        v.push_back(c);
    }
    
    sort(v.begin(), v.end());
    
    password("", 0);
}
