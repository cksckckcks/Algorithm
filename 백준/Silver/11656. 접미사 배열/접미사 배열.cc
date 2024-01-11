#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	set <string> s;
	string S;

	cin >> S;

	for (int i = 0; i < S.length(); i++) {
		string word = "";
		for (int j = i; j < S.length(); j++)
			word += S[j];
		s.insert(word);
	}

	for (const auto& word : s)
		cout << word << '\n';
}