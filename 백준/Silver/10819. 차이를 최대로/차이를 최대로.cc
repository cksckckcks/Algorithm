#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int N, ans = -10000;
vector<int> v;
bool check[8];

void search_max(vector<int>& vv, int depth) {
    if (depth == N) {
        int value = 0;
        for (int i = 0; i < N - 1; i++) {
            value += abs(vv[i] - vv[i + 1]); 
        }
        ans = max(ans, value);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!check[i]) {
            check[i] = true;
            vv.push_back(v[i]);

            search_max(vv, depth + 1);

            vv.pop_back();
            check[i] = false;
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int n;

        cin >> n;

        v.push_back(n);
    }

    vector<int> vv;
    search_max(vv, 0);

    cout << ans;
}