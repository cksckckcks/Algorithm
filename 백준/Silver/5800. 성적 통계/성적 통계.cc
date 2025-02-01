#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int K;

    cin >> K;

    for (int i = 0; i < K; i++) {
        int N;
        vector<int> v;

        cin >> N;

        for (int j = 0; j < N; j++) {
            int n;

            cin >> n;
            v.push_back(n);
        }
        sort(v.begin(), v.end());

        int gap = 0;
        for (int i = 0; i < v.size() - 1; i++) {
            if (gap < v[i + 1] - v[i])
                gap = v[i + 1] - v[i];
        }
        
        cout << "Class " << i + 1 << '\n';
        cout << "Max " << v[v.size() - 1] << ", Min " << v[0] << ", Largest gap " << gap << '\n';
    }
}