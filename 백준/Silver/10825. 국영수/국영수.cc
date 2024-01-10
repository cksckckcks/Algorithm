#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// sort에서 사용자 지정으로 정렬하기 위해 만든 compare
bool compare(const pair<string, pair<int, pair<int, int>>>& v1, const pair<string, pair<int, pair<int, int>>>& v2) {
    if (v1.second.first == v2.second.first)
        if (v1.second.second.first == v2.second.second.first)
            if (v1.second.second.second == v2.second.second.second)
                return v1.first < v2.first;
            else
                return v1.second.second.second > v2.second.second.second;
        else
            return v1.second.second.first < v2.second.second.first;
    return v1.second.first > v2.second.first;
}

int main() {
    int N;
    vector <pair<string, pair<int, pair<int, int>>>> v;

    cin >> N;

    for (int i = 0; i < N; i++) {
        string name;
        int kor, eng, math;

        cin >> name >> kor >> eng >> math;

        v.push_back(make_pair(name, make_pair(kor, make_pair(eng, math))));
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < v.size(); i++)
        cout << v[i].first << '\n';
}