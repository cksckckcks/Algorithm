#include <iostream>
#include <string>
#include <map>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    
    int n, m;
    map<string, int> num;
    string name[100001];

	cin >> n >> m;
    
	for (int i = 1; i <= n; i++) {
        string s;
        
		cin >> s;
        
		num.insert({ s, i });
		name[i] = s;
	}
    
    
	for (int i = 1; i <= m; i++) {
        string s;
        
		cin >> s;
        
		if (isdigit(s[0]))
			cout << name[stoi(s)] << '\n';
		else
			cout << num.find(s)->second << '\n';
	}
}