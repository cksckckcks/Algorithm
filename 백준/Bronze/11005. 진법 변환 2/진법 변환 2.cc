#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, B;
	vector <char> v;

	cin >> N >> B;

	if (N == 0)
		cout << 0;

	while (N != 0) {
		int n = N % B;
		
		if (n > 9) {
			char c = 'A' + n - 10;
			v.push_back(c);
		}
		else
			v.push_back('0' + n);
		N /= B;
	}

	for (int i = v.size() - 1; i >= 0; i--)
		cout << v[i];
}