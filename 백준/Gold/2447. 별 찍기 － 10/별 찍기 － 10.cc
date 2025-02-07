#include <iostream>

using namespace std;

void print_star(int x, int y, int n) {
    if (x / n % 3 == 1 && y / n % 3 == 1) // 둘 다 나머지가 1이면 가운데
        cout << ' ';
    else if (n / 3 == 0)
        cout << '*';
    else
        print_star(x, y, n / 3);
}

int main() {
    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            print_star(i, j, N);
        cout << '\n';
    }
}