#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
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

int gcd(ll arr[], ll n) {
    ll result = arr[0];
    for (int i = 1; i < n; i++) {
        result = __gcd(arr[i], result);
    }
    return result;
}

ll countDistinctG(ll A[], ll n) {
    set<ll, greater<ll>> allg;

    ll last = A[0];
    allg.insert(last);

    foreq(i, 2, n) {
        last = __gcd(last, A[i - 1]);
        allg.insert(last);
    }

    return allg.size();
}

int main() {
    ll n;
    scan(n);

    ll A[n];
    foreq(i, 1, n) { A[i - 1] = i; }

    ll maxG = 0;
    ll curr = countDistinctG(A, n);

    if (maxG < curr) {
        maxG = curr;
    }

    vector<ll> allG;
    allG.push_back(curr);

    while (next_permutation(A, A + n)) {
        curr = countDistinctG(A, n);
        allG.push_back(curr);
        if (maxG < curr) {
            maxG = curr;
        }
    }

    print(count(allG.begin(), allG.end(), maxG) % 1000000007);

    return 0;
}