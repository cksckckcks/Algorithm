#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int B, answer = 0;
    
    cin >> s >> B;
    
    for (int i = 0; i < s.length(); i++) {
       
        if(s[i] >= '0' && s[i] <= '9')
            answer = answer * B + s[i] - '0';
        else
            answer = answer * B + s[i] - 'A' + 10;
    }
    
    cout << answer;
}