#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K, index;
	vector <int> v;

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		v.push_back(i);

	index = K - 1;
	cout << '<';
	while (N--) {
		cout << v[index];
		v.erase(v.begin() + index);
		if (N > 0) {
			cout << ", ";
			index = (index + K - 1) % N;
		}
	}
	cout << '>';
}