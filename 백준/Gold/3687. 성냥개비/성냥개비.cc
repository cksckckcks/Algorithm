#include <iostream>
#include <string>

using namespace std;

// 1 2 3 4 5 6 7 8 9 0
// 2 5 5 4 5 6 3 7 6 6

int main() {
    int T;
    string min[101];
    string max[101];
    string minNum[] = {"", "", "1", "7", "4", "2", "0", "8"};

    min[0] = ""; min[1] = "";
    min[2] = "1"; min[3] = "7";
    min[4] = "4"; min[5] = "2";
    min[6] = "6"; min[7] = "8";
    
    for (int i = 8; i <= 100; i++) {
        min[i] = min[i - 2] + minNum[2];
        for (int j = 3; j <= 7; j++) {
            if (i - j < 2)
                continue;
            string a = min[i - j] + minNum[j];
            if (min[i].size() > a.size())
                min[i] = a;
            if (min[i].size() == a.size() && min[i] > a)
                min[i] = a;
        }
    }
    
    max[0] = ""; max[1] = "";
    max[2] = "1"; max[3] = "7";
    
    for (int i = 3; i <= 100; i++) {
        string a = "1" + max[i - 2];
        string b = "7" + max[i - 3];
        if (a.size() > b.size())
            max[i] = a;
        else
            max[i] = b;
    }
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int n;
        
        cin >> n;
        
        cout << min[n] << ' ' << max[n] << '\n';
    }
}