
#include <iostream>
#include <stack>
#include <string>

using namespace std;
 
int main() {
    while (1) {
        string S;

        getline(cin, S);
 
        if (S == ".")
            break;
 
        stack<char> s;
        bool flag = 0;
        for (int i = 0; i < S.length(); i++) {
            if ((S[i] == '(') || (S[i] == '['))
                s.push(S[i]);
            else if (S[i] == ')') {
                if (!s.empty() && s.top() == '(')
                    s.pop();
                else {
                    flag = 1;
                    break;
                }
            }
            else if (S[i] == ']') {
                if (!s.empty() && s.top() == '[')
                    s.pop();
                else {
                    flag = 1;
                    break;
                }
            }
        }
 
        if (flag==0 && s.empty())
            cout << "yes\n";
        else
            cout << "no\n";
    }
}