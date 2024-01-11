#include <iostream>
#include <string>
using namespace std;

int main() {

	string s;
	while (getline(cin, s)) {
		int rowcnt = 0, uppcnt = 0, numcnt = 0, spacecnt = 0;
		
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z')
				rowcnt++;
			else if (s[i] >= 'A' && s[i] <= 'Z')
				uppcnt++;
			else if (s[i] >= '0' && s[i] <= '9')
				numcnt++;
			else if (s[i] == ' ')
				spacecnt++;
		}

		cout << rowcnt << ' ' << uppcnt << ' ' << numcnt << ' ' << spacecnt << '\n';
	}
}