#include <iostream>
#include <string>
using namespace std;

int main() {
	int firstAlpha[26];
	string s;
	
	for (int i = 0; i < 26; i++)
		firstAlpha[i] = -1;

	cin >> s;
	
	for (int i = 0; i < s.length(); i++)
		if (firstAlpha[s[i] - 'a'] == -1)
			firstAlpha[s[i] - 'a'] = i;

	for (int i = 0; i < 26; i++)
		cout << firstAlpha[i] << ' ';
}