#include <iostream>
using namespace std;

// 최대공약수 (유클리드 호제법 사용)
int gcd(int a, int b) {
	int r = a % b;

	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}

	return b;
}

// 최대공약수 * 최소 공배수 = 두 수의 곱
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		int a, b;
		cin >> a >> b;

		cout << a * b / gcd(a, b) << '\n';
	}
}