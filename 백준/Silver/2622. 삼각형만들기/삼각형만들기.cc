#include <iostream>

using namespace std;

int main() {
	
	int N, ans = 0;
	
	cin >> N;

	for(int i = 1; i <= N; i++) {
		for(int j = i; j <= N; j++) {
			int n = N - (i + j);		

			if (i < j + n && j < i + n && n < i + j && j <= n)
                ans++;
            if (j > n)
                break;
		}
	}
	
	cout << ans;
}