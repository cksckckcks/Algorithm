#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

int main() {
    priority_queue <int, vector<int>, greater<int>> pq;
    vector <pair<int, int>> v;

    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int num, start, end;

        cin >> num >> start >> end;

        v.push_back({start, end});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        pq.push(v[i].second);
        if (pq.top() <= v[i].first)
            pq.pop();
    }

    cout << pq.size();
}