#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M, answer;
	vector <int> v;
	
    cin >> N >> M;
	answer = M;

	for (int i = 0; i < N; i++) {
		int n;

		cin >> n;

		v.push_back(n);
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				int sum = v[i] + v[j] + v[k];
				if (M - sum < answer && M - sum >= 0)
					answer = M - sum;
			}
		}
	}

	cout << M - answer;
}