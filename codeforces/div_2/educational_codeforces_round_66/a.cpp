#include <algorithm>
#include <cmath>
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
    int t;
    scan(t);
    while (t--) {
        ll n, k;
        scan(n);
        scan(k);

        ll count = 0;
        while (n != 0) {
            if (n % k == 0) {
                n = n / k;
                count++;
            } else {
                count += n % k;
                n = n - n % k;
            }
        }

        print(count);
    }
    return 0;
}