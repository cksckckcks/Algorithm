#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<int> tangerine) {
    vector<int> v(10000001);
    int answer = 0;
    
    for(auto i : tangerine)
        v[i]++;
    
    sort(v.begin(), v.end(), greater<int>());

    for(auto it : v) {
        k -= it;
        answer++;
        if(k <= 0)
            break;
    }
    
    return answer;
}