#include <iostream>
#include <string>
using namespace std;

int main() {
	string A, B, C, D;

	cin >> A >> B >> C >> D;

	A.append(B);
	C.append(D);

	long long answer = stoll(A) + stoll(C);

	cout << answer;
}