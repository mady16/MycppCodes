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
#define w 7
#define h 7

bool col[h] = {false};
bool diag1[2 * h - 1] = {false};
bool diag2[2 * h - 1] = {false};

void findQueens(int a, bool queen[h][w]) {
    if (a == w) {
        print("=======================");
        forless(i, 0, h) { printA(queen[i], w); }
        print("=======================");
        return;
    }
    forless(i, 0, w) {
        if (col[i] || diag1[i + a] || diag2[h - 1 + i - a]) continue;
        col[i] = diag1[i + a] = diag2[h - 1 + i - a] = true;
        queen[a][i] = true;
        findQueens(a + 1, queen);
        col[i] = diag1[i + a] = diag2[h - 1 + i - a] = false;
        queen[a][i] = false;
    }
}

int count1 = 0;
int canGo[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
bool visited[h][w];
void paths(int i, int j, int k) {
    if (k == w * h) {
        if (i == h - 1 && j == w - 1) {
            count1++;
        }
        return;
    }

    if (i == h - 1 && j == w - 1) {
        return;
    }

    foreq(l, 0, 3) {
        int p = canGo[l][0];
        int q = canGo[l][1];
        if (i + p > -1 && i + p < h && j + q < w && j + q > -1 &&
            !visited[i + p][j + q]) {
            visited[i + p][j + q] = true;
            paths(i + p, j + q, k + 1);
            visited[i + p][j + q] = false;
        }
    }
}

int main(int argc, char *argv[]) {
    bool queen[h][w];

    forless(i, 0, h) {
        forless(j, 0, w) {
            queen[i][j] = false;
            visited[i][j] = false;
        }
    }
    // findQueens(0, queen);

    visited[0][0] = true;
    visited[0][1] = true;

    paths(0, 1, 2);
    count1 = count1*2;
    print(count1);

    return 0;
}