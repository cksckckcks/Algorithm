#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	multimap<int, string> mm;
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int age;
		string name;

		cin >> age >> name;
		mm.insert(make_pair(age, name));
	}
	
	for (auto it : mm )
		cout << it.first << " " << it.second << '\n';
}