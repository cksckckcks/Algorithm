#include <iostream>
 
using namespace std;
 
int main() 
	{
    double n = 0, sum = 0;
    
    for (int i = 0; i < 20; i++) {
        string name, grade;
        double credit;
        
        cin >> name >> credit >> grade;
 
        if (grade == "P")
            continue;
        else if (grade == "A+") {
            sum += credit * 4.5;
            n += credit;
        }
        else if (grade == "A0") {
            sum += credit * 4.0;
            n += credit;
        }
        else if (grade == "B+") {
            sum += credit * 3.5;
            n += credit;
        }
        else if (grade == "B0") {
            sum += credit * 3.0;
            n += credit;
        }
        else if (grade == "C+") {
            sum += credit * 2.5;
            n += credit;
        }
        else if (grade == "C0") {
            sum += credit * 2.0;
            n += credit;
        }
        else if (grade == "D+") {
            sum += credit * 1.5;
            n += credit;
        }
        else if (grade == "D0") {
            sum += credit * 1.0;
            n += credit;
        }
        else if (grade == "F")
            n += credit;
    }
    
    double ans = sum / n;
    
    cout << ans;
}