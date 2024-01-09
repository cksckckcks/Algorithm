#include <iostream>
#include <set>
using namespace std;

int main() {
    // c++의 입출력 속도 증가 (버퍼 사용 X)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int N;
	int arr[10001] = { 0, };
	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
	    int n;
	    
	    cin >> n;
	    arr[n]++;
	}
	
	for (int i = 1; i < 10001; i++) {
	    while (arr[i]--)
	        cout << i << '\n';
	}
	
}