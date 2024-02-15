#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M;

	cin >> N >> M;
	
	int answer;
	if (N == 1)
		answer = 1;
	else if (N == 2)
		answer = min(4, (M + 1) / 2);
	else if (M >= 7)
		answer = M - 2;
	else
		answer = min(4, M);

	cout << answer;
}