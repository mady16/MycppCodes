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

bool find(int a[], int n, int b){
    foreq(i,0,n-1){
        if(a[i] == b){
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    int a[n];
    int val[3] = {0};

    scanA(a, n);

    int index = 0;
    foreq(i, 0, n - 1) {
        if (find(val, 3, a[i])) {
            continue;
        }

        if (val[2] != 0) {
            print(-1);
            return 0;
        }
        val[index] = a[i];
        index++;
    }

    // printA(val, 3);

    if (val[2] == 0 && val[1] != 0) {
        int diff = abs(val[1] - val[0]);
        print((diff%2 == 0 ? diff/2 : diff));
    } else if (val[1] == 0) {
        print(0);
    } else {
        sort(val, val + 3);
        if (val[2] - val[1] == val[1] - val[0]) {
            print(val[1] - val[0]);
        } else {
            print(-1);
        }
    }

    return 0;
}