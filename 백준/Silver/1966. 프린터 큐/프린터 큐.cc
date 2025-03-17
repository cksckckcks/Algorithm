#include<iostream>
#include<queue>
using namespace std;

int main(void)
{
	int t;

	cin >> t;
    
	for (int i = 0; i < t; i++) {
        queue<pair<int, int>> q;
	    priority_queue<int> printer;
        int n, m, cnt = 0;
		
		cin >> n >> m;
        
		for (int j = 0; j < n; j++) {
            int num;
            
			cin >> num;
            
			q.push({ j, num });
			printer.push(num);
		}
        
		while (!printer.empty()) {
			int idx = q.front().first;
			int prior = q.front().second;
			q.pop();
            
			if (printer.top() == prior) {
				cnt++;
				printer.pop();
				if (idx == m) {
					cout << cnt << '\n';
					break;
				}
			}
			else
				q.push({idx,prior});
		}
	}
}