#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	int T;
	multiset<int> ms; // set과 동일 하지만 키 값 중복 가능

	cin >> T;

	for (int i = 0; i < T; i++) {
		int k;

		cin >> k;
		for (int j = 0; j < k; j++) {
			char c;
			int input;

			cin >> c >> input;

			if (c == 'I') {
				ms.insert(input); // set은 자동 정렬
			}	
			if (c == 'D' && input == 1 && ms.size()) {
				auto last = ms.end(); // iterator 반환 > auto 사용
				ms.erase(--last);
			}
			if (c == 'D' && input == -1 && ms.size())
				ms.erase(ms.begin());
		}

		if (ms.size() == 0)
			cout << "EMPTY" << '\n';
		else {
			auto max = ms.end();
			auto min = ms.begin();
			cout << *--max << " " << *min << '\n'; // 가장 큰 수를 출력할 때 마지막 -1을 해줘야 하므로 --max
		}
		ms.clear();
	}
}