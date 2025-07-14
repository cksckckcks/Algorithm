#include <iostream>

using namespace std;

void hanoi(int n, int start, int mid, int end) {
    if (n == 1) {
       cout << start << ' ' << end << '\n';
       
       return;
    }

    hanoi(n - 1, start, end, mid);

    cout << start << ' ' << end << '\n';

    hanoi(n - 1, mid, start, end);
}

int honoi_min_cnt(int n) {
    int ret = 1;

    while (--n) 
        ret = ret * 2 + 1;

    return ret;
}

int main() {
    int N;

    cin >> N;

    cout << honoi_min_cnt(N) << '\n';
    hanoi(N, 1, 2, 3);
}