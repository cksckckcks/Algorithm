#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    map<string, int> human;
    int N, M;
    vector<string> ans;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;

        cin >> s;
        human.insert(make_pair(s, 1));
    }

    for (int i = 0; i < M; i++) {
        string s;

        cin >> s;
        if (human.count(s))
            ans.push_back(s);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';
}