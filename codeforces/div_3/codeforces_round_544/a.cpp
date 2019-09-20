#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
#define foreq(i, a, b) for (int i = a; i <= b; i++)
#define printA(A, n)                            \
    foreq(p, 0, n - 1) { cout << A[p] << " "; } \
    cout << endl;
#define print(s) cout << s << endl
#define scan(s) cin >> s
#define scanA(A, n) \
    foreq(p, 0, n - 1) { cin >> A[p]; }
#define sq(a) (a) * (a)

// ios::sync_with_stdio(0);
// cin.tie(0);

int main() {
    int h1, m1, h2, m2;
    char mid;
    scan(h1 >> mid >> m1);
    scan(h2 >> mid >> m2);

    int hgap = h2 - h1, mgap = m2 - m1;
    int hmid, mmid;

    if (mgap >= 0) {
        mmid = m1 + (mgap / 2);
        if (hgap % 2 == 1) {
            mmid += 30;
        }
    } else {
        mmid = m1 + ((60 + mgap) / 2);
    }

    hmid = h1 + (hgap / 2);

    if (mmid >= 60) {
        hmid++;
        mmid -= 60;
    }

    print(setw(2) << setfill('0') << hmid << ":" << setw(2) << setfill('0')
                  << mmid);
    return 0;
}