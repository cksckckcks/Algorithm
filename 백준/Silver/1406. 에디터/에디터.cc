#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(int argc, char**argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	list<char> L;
    int N;

	cin >> s;
	
	for(int i = 0; i < s.size(); i++)
		L.push_back(s.at(i));
		
	auto cur = L.end();
	
	cin >> N;
	
	for(int i = 0; i < N; i++) {
		char c;
        
		cin >> c;
		
		if(c=='L') { 
			if(cur!=L.begin())
                cur--;
		}			
		else if(c=='D') {
			if(cur!=L.end())
                cur++;
		}
		else if(c == 'B') {
			if(cur!=L.begin())
				cur = L.erase(--cur);
		}
		
		else if(c == 'P') {
			char s;
			cin >> s;
			L.insert(cur,s);
		}
		
	}

	for(auto it = L.begin(); it != L.end(); it++)
		cout << *it;
    
}