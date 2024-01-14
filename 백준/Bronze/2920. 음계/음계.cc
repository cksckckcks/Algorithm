#include <iostream>
using namespace std;

int main() {
	int n;

	cin >> n;

	if (n == 1) {
		for (int i = 2; i < 9; i++) {
			cin >> n;
			if (i != n) {
				cout << "mixed" << '\n';
				return 0;
			}
		}
		cout << "ascending" << '\n';
	}
	else if (n == 8) {
		for (int i = 7; i > 0; i--) {
			cin >> n;
			if (i != n) {
				cout << "mixed" << '\n';
				return 0;
			}
		}
		cout << "descending" << '\n';
	}
	else
		cout << "mixed" << '\n';
}