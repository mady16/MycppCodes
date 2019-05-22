#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
#define foreq(i, a, b) for (int i = a; i <= b; i++)

#define printA(A, n)                            \
    foreq(p, 0, n - 1) { cout << " " << A[p]; } \
    cout << endl;
#define print(s) cout << s << endl

#define sq(a) (a) * (a)

// ios::sync_with_stdio(0);
// cin.tie(0);

#define S 1001

int main() {
    int spiral[S][S] = {0};
    int count = 1;
    int h = 0, v = 0;
    int loop_count = -1;
    spiral[(S / 2) + v][(S / 2) + h] = count;
    count++;
    loop_count++;

    foreq(i, 0, loop_count) {
        h++;
        spiral[(S / 2) + v][(S / 2) + h] = count;
        count++;
    }

    while (true) {
        foreq(i, 0, loop_count) {
            v++;
            spiral[(S / 2) + v][(S / 2) + h] = count;
            count++;
        }

        loop_count++;
        foreq(i, 0, loop_count) {
            h--;
            spiral[(S / 2) + v][(S / 2) + h] = count;
            count++;
        }

        foreq(i, 0, loop_count) {
            v--;
            spiral[(S / 2) + v][(S / 2) + h] = count;
            count++;
        }
        loop_count++;
        foreq(i, 0, loop_count) {
            h++;
            spiral[(S / 2) + v][(S / 2) + h] = count;
            count++;
        }
        if (loop_count == S - 1) {
            break;
        }
    }

    // foreq(i, 0, S - 1) { printA(spiral[i], S); }

    ll ans = 0;
    foreq(i, 0, S - 1) {
        foreq(j, 0, S - 1) {
            if (i == j || i == S - j - 1) ans += spiral[i][j];
        }
    }

    print(ans);

    return 0;
}