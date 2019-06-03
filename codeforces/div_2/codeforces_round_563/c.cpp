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

bool isCoprime(int a, int b) { return (__gcd(a, b) == 1); }

int main() {
    ll n;
    scan(n);
    ll A[n - 1] = {0};

    ll smallestP = 1;
    foreq(i, 2, n) {
        bool used = false;
        for (int j = i; j <= n; j += i) {
            if (A[j - 2] == 0) {
                used = true;
                A[j - 2] = smallestP;
            }
        }
        if (used) {
            smallestP++;
        }
    }

    printA(A, n - 1);

    return 0;
}