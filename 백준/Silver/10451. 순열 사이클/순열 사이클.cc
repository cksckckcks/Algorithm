#include <iostream>
#include <string.h>
using namespace std;

int arr[1001] = { 0, };
bool visited[1001] = { 0, };


void dfs(int x) {
    visited[x] = 1;
    
    if (!visited[arr[x]])
        dfs(arr[x]);
    else
        return;
}

int main() {
    int T, cnt = 0;
    
    cin >> T;
    while (T--){
        int N;
        
        cin >> N;
        for (int i = 1; i <= N; i++) {
            int n;
            
            cin >> n;
            arr[i] = n;
        }
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                dfs(i);
                cnt++;
            }
        }
        
        cout << cnt << '\n';
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        cnt = 0;
    }
}