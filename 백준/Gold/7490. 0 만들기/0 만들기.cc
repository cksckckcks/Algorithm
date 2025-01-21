#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<string> ans;

bool check(string s) {
    vector<string> v;
    string tmp = "";
    int sum = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '+' || s[i] == '-') {
            v.push_back(tmp);
            v.push_back(string(1, s[i]));
            tmp = "";
        }
        else if (s[i] == ' ')
            continue;
        else
            tmp += s[i];
    }
    if (!tmp.empty())
        v.push_back(tmp);

    sum = stoi(v[0]);
    for (int i = 1; i < v.size(); i += 2) {
        if (v[i] == "+")
            sum += stoi(v[i + 1]);
        else if (v[i] == "-")
            sum -= stoi(v[i + 1]);
    }

    return (sum == 0);
}

void zero(string s, int n) {
    s += to_string(n);

    if (n >= N) {
        if (check(s))
            ans.push_back(s);
        
        return;
    }

    zero(s + ' ', n + 1);
    zero(s + '-', n + 1);
    zero(s + '+', n + 1);
}

int main() {
    int T;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        
        zero("", 1);
        
        sort(ans.begin(), ans.end());
        
        for (auto it : ans)
            cout << it << '\n';
        
        cout << '\n';
        
        ans.clear();
    }

    return 0;
}
