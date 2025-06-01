#include <string>
#include <vector>
#include <algorithm>

using namespace std;
 
int Gcd(int a , int b) {
    int A = a > b ? a : b;
    int B = a < b ? a : b;
    
    while(A % B != 0) {
        int R = A % B;
        A = B;
        B = R;
    }
    return B;
}
 
// 최소공배수 -> a * b / 최대공약수
int solution(vector<int> arr) {
    int answer = arr[0];
    
    for(int i = 1; i < arr.size(); i++)
    {
        int GCD = Gcd(answer, arr[i]);
        int LCM = answer * arr[i] / GCD;
        answer = LCM;
    }
    
    return answer;
}