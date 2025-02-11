#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    map<string, string> m;

    int N, M;
    
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string site, pw;

        cin >> site >> pw;

        m.insert(make_pair(site, pw));
    }

    for (int i = 0; i < M; i++) {
        string site;

        cin >> site;

        cout << m[site] << '\n';
    }
}