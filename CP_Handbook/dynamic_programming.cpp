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

int countCoins(int coins[], int *storage, int x, int n) {
    if (x < 0) return INT16_MAX;
    if (x == 0) return 0;
    // print(x);

    if (storage[x] != -1) return storage[x];

    int best = INT16_MAX;
    forless(i, 0, n) {
        best = min(best, countCoins(coins, storage, x - coins[i], n) + 1);
    }
    storage[x] = best;
    return best;
}

int maxPathinGrid(int grid[][6]) {
    int sum[6][6];

    forless(i, 0, 6) {
        sum[0][i] = 0;
        sum[i][0] = 0;
    }

    forless(i, 1, 6) {
        forless(j, 1, 6) {
            sum[i][j] = max(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
        }
    }

    return sum[5][5];
}

int editDistance(string str1, string str2, int m, int n) {
    if (m == 0) return n;
    if (n == 0) return m;

    if (str1[m-1] == str2[n-1]) return editDistance(str1, str2, m - 1, n - 1);

    return 1 + min(min(editDistance(str1, str2, m, n - 1),
                   editDistance(str1, str2, m - 1, n)),
                   editDistance(str1, str2, m - 1, n - 1));
}

int main() {
    int coins[] = {1, 3, 4};
    int storage[10020];
    forless(i, 0, 10020) storage[i] = -1;
    print(countCoins(coins, storage, 10012, 3));

    int grid[6][6] = {
        {0, 0, 0, 0, 0, 0}, {0, 2, 4, 5, 6, 1}, {0, 1, 3, 3, 6, 8},
        {0, 7, 1, 2, 3, 7}, {0, 2, 8, 4, 2, 2}, {0, 1, 7, 8, 6, 1},
    };

    print(maxPathinGrid(grid));

    print(editDistance("love", "movie", 4, 5));

    return 0;
}