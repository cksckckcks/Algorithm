#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;

	cin >> T;

	while (T--) {
		string s;
		
		cin >> s;

		cout << s[0] << s[s.length() - 1] << '\n';
	}
}