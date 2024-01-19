#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string s1, string s2) {
	if (s1.length() > s2.length())
		return 0;
	else if (s1.length() < s2.length())
		return 1;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] > s2[i])
			return 0;
		else if (s1[i] < s2[i])
			return 1;
	}
}

int main() {
	vector <string> v;
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		
		cin >> str;
		if(find(v.begin(), v.end(), str) == v.end()) // v에 없다면 end값을 return하므로 if를 통해 판별
			v.push_back(str);
	}
	
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';
}