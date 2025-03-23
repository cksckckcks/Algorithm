#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";

    vector<int> v;
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            tmp += s[i];
        } else {
            v.push_back(stoi(tmp));
            tmp.clear();
        }
    }
    
    v.push_back(stoi(tmp));

    sort(v.begin(), v.end());

    answer = to_string(v[0]) + " " + to_string(v[v.size() - 1]);

    return answer;
}