#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int map[21][21];
int ans = 2147483647;
int zone_popul[5];

bool line_check(int x, int y, int d1, int d2) {
    return (x + d1 <= N && y - d1 > 0 && \
        x + d2 <= N && y + d2 <= N && \
        x + d1 + d2 <= N && y + d2 - d1 > 0);
}

void zone_setting(int x, int y, int d1, int d2) {

    for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (r < x + d1 && c <= y && !(r >= x && c >= y - (r - x)))
				zone_popul[0] += map[r][c];
			else if (r <= x + d2 && c > y && !(r >= x && c <= y + (r - x)))
				zone_popul[1] += map[r][c];
			else if (r >= x + d1 && c < y - d1 + d2 && !(r <= x + d1 + d2 && c >= (y - d1 + d2 - (x + d1 + d2 - r))))
				zone_popul[2] += map[r][c];
			else if (r > x + d2 && c >= y - d1 + d2 && !(r <= x + d1 + d2 && c <= (y - d1 + d2 + (x + d1 + d2 - r))))
				zone_popul[3] += map[r][c];
			else
				zone_popul[4] += map[r][c];
		}
    }

    sort(zone_popul, zone_popul + 5);
    ans = min(ans, zone_popul[4] - zone_popul[0]);
}

void make_line() {
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            for (int d1 = 1; d1 <= N; d1++) {
                for (int d2 = 1; d2 <= N; d2++) {
                    if (line_check(x, y, d1, d2)) {
                        zone_setting(x, y, d1, d2);
                        zone_popul[0] = 0; zone_popul[1] = 0; zone_popul[2] = 0; zone_popul[3] = 0; zone_popul[4] = 0; // memset || fill
                    }
                }
            }
        }
    }
    
}

int main() {
    

    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> map[i][j];

    make_line();

    cout << ans;
}