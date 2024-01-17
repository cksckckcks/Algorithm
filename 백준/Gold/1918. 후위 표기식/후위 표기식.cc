#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	stack <char> st;
	string s;

	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		char c = s[i];

		if (c >= 'A' && c <= 'Z')
			cout << c;
		else if (st.empty() || c == '(')
			st.push(c);
		else if (c == ')') {
			while (st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.pop();
		}
		else if (c == '*' || c == '/') {
			if (st.top() == '+' || st.top() == '-' || st.top() == '(')
				st.push(c);
			else {
				while (st.top() == '*' || st.top() == '/') {
					cout << st.top();
					st.pop();
					if (st.empty())
						break;
				}
				st.push(c);
			}
		}
		else if (c == '+' || c == '-') {
			if (st.top() == '(')
				st.push(c);
			else {
				while (st.top() == '*' || st.top() == '/' || st.top() == '+' || st.top() == '-') {
					cout << st.top();
					st.pop();
					if (st.empty())
						break;
				}
				st.push(c);
			}
		}
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}