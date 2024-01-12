#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int index, n;
    
    cin >> s;
    
    
    index = 0; n = 0;
    for(int i = 0; i < s.length() % 3; i++) {
        n *= 2;
        n += s[index++] - '0';
    }
    if (n != 0 || s[0] == '0')
        cout << n;
    
    while (index < s.length()) {
        n = 0;
        for(int i = 0; i < 3; i++) {
            n *= 2;
            n += s[index++] - '0';
        }
        cout << n;
    }

}