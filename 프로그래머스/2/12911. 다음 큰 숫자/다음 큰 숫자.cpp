#include <string>
#include <vector>

using namespace std;


int one_cnt(int n)
{
    int ret = 0;
    
    for(int i = 0; n > 0; i++)
    {
        if(n % 2 == 1)
            ret++;
        n /= 2;
    }
    
    return ret;
}
 
int solution(int n) 
{
    int N = one_cnt(n);
    
    while(1)
    {
        n++;
        
        if(one_cnt(n) == N)
            break;
    }
    
    return n;
}