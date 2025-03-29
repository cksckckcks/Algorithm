#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    
    for (int i = 1; i < n; i++) {
        int sum = 0, num = i;
        while (sum < n) {
            sum += num;
            num++;
        }
        if (sum == n)
            answer++;
    }
    
    return answer;
}