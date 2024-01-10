#include <iostream>
#include <string>
using namespace std;

int main() {
    int alphaCnt[26] = { 0, };
    string s;
    
    cin >> s;
    
    for(int i = 0; i < s.length(); i++)
        alphaCnt[s[i] - 'a']++;
        
    for(int i = 0; i < 26; i++)
        cout << alphaCnt[i] << " ";
}