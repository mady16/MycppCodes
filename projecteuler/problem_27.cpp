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

#define sq(a) (a) * (a)

// ios::sync_with_stdio(0);
// cin.tie(0);

bool isPrime(ll num) {
    if (num <= 1) return false;
    if (num <= 3) return true;

    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i * i <= num; i = i + 6)
        if (num % i == 0 || num % (i + 2) == 0) return false;

    return true;
}

int main() {
    ll maxprimes = 0;
    int ma, mb;
    foreq(a, -999, 999) {
        foreq(b, -1000, 1000) {
            int n = 0;
            ll temp = n * n + n * a + b;
            while (isPrime(temp)) {
                n++;
                temp = n * n + n * a + b;
            }
            if (n > maxprimes) {
                maxprimes = n;
                ma = a;
                mb = b;
            }
        }
    }

    print(ma*mb);
    return 0;
}