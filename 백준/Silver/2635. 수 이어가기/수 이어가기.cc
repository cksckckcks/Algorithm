#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    vector<int> ans;

    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        vector<int> tmp;
        
        tmp.push_back(N);
        tmp.push_back(i);
        
        for (int j = 1; ; j++) {
            if (tmp[j - 1] - tmp[j] < 0)
                break;
            tmp.push_back(tmp[j - 1] - tmp[j]);
        }
        if (tmp.size() > ans.size())
            ans = tmp;
    }
    
    cout << ans.size() << '\n';
        
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
}