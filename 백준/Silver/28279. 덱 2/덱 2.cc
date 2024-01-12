#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	deque <int> dq;

	cin >> N;

	while (N--) {
		int input;

		cin >> input;

		if (input == 1) {
			int n;

			cin >> n;
			dq.push_front(n);
		}
		else if (input == 2) {
			int n;

			cin >> n;
			dq.push_back(n);
		}
		else if (input == 3) {
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (input == 4) {
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (input == 5)
			cout << dq.size() << '\n';
		else if (input == 6)
			if (dq.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		else if (input == 7) {
			if (dq.empty())
				cout << -1 << '\n';
			else
				cout << dq.front() << '\n';
		}
		else if (input == 8) {
			if (dq.empty())
				cout << -1 << '\n';
			else 
				cout << dq.back() << '\n';
		}
		
	}
}