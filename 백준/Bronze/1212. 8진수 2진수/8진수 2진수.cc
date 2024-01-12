#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    int index, n;
    vector <int> v;
    
    cin >> s;

    if(s[0] == '0')
        cout << 0;
    index = 0; n = s[index++] - '0';
    for (int i = 0; i < 3; i++) {
        v.push_back(n % 2);
        n /= 2;
    }
    
    for (int i = 2; i >= 0; i--) {
        if(v[i] == 1)
            break;
        v.erase(v.begin() + i);
    }
    
    for (int i = v.size() - 1; i >= 0; i--)
        cout << v[i];
    v.clear();
    
    while (index < s.length()) {
        n = s[index++] - '0';
        for(int i = 0; i < 3; i++) {
            v.push_back(n % 2);
            n /= 2;
        }
        for (int i = 2; i >= 0; i--)
            cout << v[i];
        v.clear();
    }

}