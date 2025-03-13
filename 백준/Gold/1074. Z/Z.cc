#include <iostream>

using namespace std;

int N, r, c, ans = 0, n = 2;

void Z(int x, int y, int max){
    if (r==y && c==x){
        cout << ans;
        return;
    }
    else if (c < x + max && c >= x && r < y + max && r >= y) {
        Z(x, y, max / 2);
        Z(x + max / 2, y, max / 2);
        Z(x, y + max / 2, max / 2);
        Z(x + max / 2, y + max / 2, max / 2);
    }
    else
        ans += max * max;
}

int main(){
    cin >> N >> r >> c;
    
    for (int i = 0; i < N; i++)
           n *= 2;
    
    Z(0, 0, n);
}