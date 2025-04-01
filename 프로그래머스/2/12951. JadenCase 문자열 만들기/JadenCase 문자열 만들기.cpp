#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool check = false;
    
    for(auto c : s) {
        if (c == ' ') {
            answer += ' ';
            check = false;
        }
        else if (!check) {
            answer += toupper(c);
            check = true;
        }
        else 
            answer += tolower(c);
    }
    
    return answer;
}