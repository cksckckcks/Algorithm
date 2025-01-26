#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int max_value[3];
int min_value[3];

int main() {
    int N;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        int tmp[3];
        tmp[0] = max_value[0]; tmp[1] = max_value[1]; tmp[2] = max_value[2];

        max_value[0] = a + max(tmp[0], tmp[1]);
        max_value[1] = b + max(tmp[0], max(tmp[1], tmp[2]));
        max_value[2] = c + max(tmp[1], tmp[2]);

        tmp[0] = min_value[0]; tmp[1] = min_value[1]; tmp[2] = min_value[2];
        min_value[0] = a + min(tmp[0], tmp[1]);
        min_value[1] = b + min(tmp[0], min(tmp[1], tmp[2]));
        min_value[2] = c + min(tmp[1], tmp[2]);
    }

    cout << max(max_value[0], max(max_value[1], max_value[2])) << ' ' << min(min_value[0], min(min_value[1], min_value[2]));
}