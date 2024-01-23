#include <iostream>
using namespace std;

int arr[27][2] = { 0, };

void preorder(int n) {
	char c = 'A' + n - 1;

	cout << c;
	if (arr[n][0])
		preorder(arr[n][0]);
	if (arr[n][1])
		preorder(arr[n][1]);
}

void inorder(int n) {
	char c = 'A' + n - 1;

	if (arr[n][0])
		inorder(arr[n][0]);
	cout << c;
	if (arr[n][1])
		inorder(arr[n][1]);
}

void postorder(int n) {
	char c = 'A' + n - 1;

	if (arr[n][0])
		postorder(arr[n][0]);
	if (arr[n][1])
		postorder(arr[n][1]);
	cout << c;
}

int main() {
	int N;

	cin >> N;

	while (N--) {
		char a, b, c;

		cin >> a >> b >> c;

		if(b != '.')
			arr[a - 'A' + 1][0] = b - 'A' + 1;
		if (c != '.')
			arr[a - 'A' + 1][1] = c - 'A' + 1;
	}
    
	preorder(1);
	cout << '\n';
	inorder(1);
	cout << '\n';
	postorder(1);
}