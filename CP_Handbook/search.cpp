#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
#define foreq(i, a, b) for (int i = a; i <= b; i++)
#define forless(i, a, b) for (int i = a; i < b; i++)
#define rforeq(i, a, b) for (int i = a; i >= b; i--)
#define rforless(i, a, b) for (int i = a; i > b; i--)
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

int search1(vector<int> num, int s) {
    foreq(i, 0, num.size() - 1) {
        if (num[i] == s) return i;
    }
    return -1;
}

int search2(vector<int> num, int s) {
    int a = 0, b = num.size(), c;
    while (a <= b) {
        c = (a + b) / 2;
        if (num[c] == s) {
            return c;
        } else if (num[c] < s) {
            a = c + 1;
        } else {
            b = c - 1;
        }
    }
    return num[c] == s ? c : -1;
}

int search3(vector<int> num, int s) {
    int k = 0;
    for (int b = num.size() / 2; b >= 1; b /= 2) {
        while (k + b < num.size() && num[k + b] <= s) k += b;
    }
    return num[k] == s ? k : -1;
}

int main() {
    vector<int> num = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    print(search2(num, 2));
    return 0;
}