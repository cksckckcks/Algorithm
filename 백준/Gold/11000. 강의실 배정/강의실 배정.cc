#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    vector<pair<int, int>> v;
    
    int N;


    cin >> N;

    for (int i = 0; i < N; i++) {
        int s, t;

        cin >> s >> t;

        v.push_back({s, t});
    }

    sort(v.begin(), v.end());

    priority_queue <int, vector<int>, greater<int>> pq;
    for (int i = 0; i < v.size(); i++) {
        pq.push(v[i].second);
        if (pq.top() <= v[i].first)
            pq.pop();
    }

    cout << pq.size();
}