#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n1, n2, n3;

	while (1) {
		cin >> n1 >> n2 >> n3;

		if (n1 == 0 && n2 == 0 && n3 == 0)
			break;

		int tri = n1 * n1 + n2 * n2 + n3 * n3 - max({ n1, n2, n3 }) * max({ n1, n2, n3 });
		if (tri == max({ n1, n2, n3 }) * max({n1, n2, n3}))
			cout << "right" << '\n';
		else
			cout << "wrong" << '\n';
	}
}