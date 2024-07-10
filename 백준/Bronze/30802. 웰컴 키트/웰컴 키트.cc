#include <iostream>

using namespace std;

int main() {
    int N, T, P, cnt = 0, sum = 0;
    int size[6] = {0, };
    
    cin >> N;
    for (int i = 0; i < 6; i++) {
        cin >> size[i];
        sum += size[i];
    }

    cin >> T >> P;

    for (int i = 0; i < 6; i++) {
        cnt += size[i] / T;
        if (size[i] % T > 0)
            cnt++;
    }
    
    cout << cnt << '\n' << sum / P << " " << sum % P;
}