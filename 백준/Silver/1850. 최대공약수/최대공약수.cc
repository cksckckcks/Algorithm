#include <iostream>
using namespace std;

// 최대공약수 (유클리드 호제법 사용)
long long gcd(long long a, long long b) {
	long long r = a % b;

	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}

	return b;
}

int main() {
	long long a, b;

	cin >> a >> b;

	for (long long i = 0; i < gcd(a, b); i++)
		cout << 1;
}