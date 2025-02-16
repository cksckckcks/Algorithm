#include <iostream>
#include <string>

using namespace std;

int check[9];

int main() {
    string s;

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] - '0' == 9 || s[i] - '0' == 6)
            check[6]++;
        else
            check[s[i] - '0']++;
    }

    int ans = -1;
    
    
    if (check[6] % 2)
        check[6]++;

        check[6] /= 2;

    for (int i = 0; i < 9; i++)
        if (ans < check[i])
            ans = check[i];

    cout << ans;
}