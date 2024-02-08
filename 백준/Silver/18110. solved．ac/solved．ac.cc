#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<int> v;

    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int num;

        cin >> num;

        v.push_back(num);
    }

    int t = round(n * 0.15);
    sort(v.begin(), v.end());
    

    double average = 0;
    for (int i = t; i < n - t; i++)
        average += v[i];

    average /= (n - 2 * t);
   
    cout << round(average);
}