// wrong
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
#define foreq(i, a, b) for (int i = a; i <= b; i++)

#define printA(A, n) \
    foreq(p, 0, n - 1) { cout << p << ": " << A[p] << endl; }
#define print(s) cout << s << endl
#define scan(s) cin >> s
#define scanA(A, n) \
    foreq(p, 0, n - 1) { cin >> A[p]; }
#define sq(a) (a) * (a)

// ios::sync_with_stdio(0);
// cin.tie(0);

int main() {
    ll n, k;
    scan(n);
    scan(k);

    ll skills[n];
    ll location[n];

    foreq(i, 0, n - 1) {
        cin >> skills[i];
        location[skills[i]] = i;
    }

    bool booked[n] = {false};
    char booker[n] = {'0'};
    ll topunbooked = n, newtopunbooked;
    char currbooker = '1';
    while (true) {
        foreq(i, -k, k) {
            if (location[topunbooked - 1] + i > n)
                break;
            else if (i < 0)
                i = -1;
            else {
                int temp = location[topunbooked - 1] + i - 1;
                booked[temp] = true;
                booker[temp] = currbooker;

                if (temp < topunbooked) {
                    newtopunbooked = temp;
                }
            }
        }
        topunbooked = newtopunbooked;
    }

    return 0;
}