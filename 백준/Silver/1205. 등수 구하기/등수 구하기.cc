#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v;
    int n, score, p, ans = 0;
    
    cin >> n >> score >> p;
    
    if (n == 0)
    {
        cout << "1";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        int n;
        
        cin >> n;
        v.push_back(n);
    }
    sort(v.rbegin(), v.rend());
    if (v.back() >= score && v.size() == p)
        cout << "-1";
    else
    {
        v.push_back(score);
        sort(v.rbegin(), v.rend());
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == score)
            {
                ans = i;
                break;
            }
        }
        cout << ans + 1;
    }
}