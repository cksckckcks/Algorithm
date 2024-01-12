#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	stack <int> s;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int input;
		
		cin >> input;

		if (input == 1) {
			int n;

			cin >> n;

			s.push(n);
		}
		else if (input == 2) {
			if (s.empty())
				cout << -1 << '\n';
			else {
				cout << s.top() << '\n';
				s.pop();
			}

		}
		else if (input == 3)
			cout << s.size() << '\n';
		else if (input == 4)
			if (s.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		else if (input == 5)
			if (s.empty())
				cout << -1 << '\n';
			else
				cout << s.top() << '\n';
	}
}