#include <iostream>
#include <string>
using namespace std;

int main() {
	while (1) {
		string s;

		cin >> s;

		if (s == "0")
			break;
		
		int check = 1;
		for (int i = 0; i < s.length() / 2; i++) {
			if (s[i] != s[s.length() - 1 - i]) {
				check = 0;
				cout << "no" << '\n';
				break;
			}
		}
		if (check)
			cout << "yes" << '\n';
	}
}