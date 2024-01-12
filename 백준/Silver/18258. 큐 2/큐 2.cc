#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	queue <int> q;

	cin >> N;

	for (int i = 0; i < N; i++) {
		string input;

		cin >> input;

		if (input == "push") {
			int n;

			cin >> n;

			q.push(n);
		}
		else if (input == "pop") {
			if (q.empty())
				cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (input == "size")
			cout << q.size() << '\n';
		else if (input == "empty")
			cout << q.empty() << '\n';
		else if (input == "front") {
			if (q.empty())
				cout << -1 << '\n';
			else 
				cout << q.front() << '\n';
		}
		else if (input == "back") {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
	}
}