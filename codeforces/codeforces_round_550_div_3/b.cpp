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

ll addAll(ll a[], int s){
    ll sum = 0;
    foreq(i,0,s-1){
        sum += a[i];
    }

    return sum;
}

int main() {
    int n;
    scan(n);

    ll a[n];
    scanA(a, n);

    sort(a, a + n);

    ll minsum = INT32_MAX;

    ll b[n];
    copy(a, a + n, b);

    foreq(j,0,1){
        if(j == 1){
            copy(b, b + n, a);
        }
        bool even = j;
        int bigEven = n - 1;
        int bigOdd = n - 1;
        while (true) {
            int i;
            for (i = (!even ? bigEven : bigOdd); i >= 0; i--) {
                if (a[i] % 2 == even && !even) {
                    a[i] = 0;
                    bigEven = i-1;
                    break;
                }

                if (even && a[i] % 2 == !even) {
                    a[i] = 0;
                    bigOdd = i-1;
                    break;
                }
            }
            even = !even;
            if(i == -1){
                break;
            }
        }

        printA(a,n);
        ll temp;
        if(j == 0){
            temp = addAll(a, n);
        }else{
            temp = addAll(b, n);
        }
        if(minsum > temp){
            minsum = temp;
        }
    }

    print(minsum);
    return 0;
}