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
    ll ans = 1;
    ll diff = 2;
    ll num = 1;

    foreq(i, 0, S / 2 - 1) {
        foreq(j, 0, 3) {
            num += diff;
            ans += num;
        }
        diff+=2;
    }

    print(ans);
    return 0;
}