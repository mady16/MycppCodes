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

ll removeTrailingZeros(ll num) {
    string temp = to_string(num);

    for (int i = temp.length() - 1; i >= 0; i--) {
        if (temp[i] != '0') {
            break;
        } else {
            temp.pop_back();
        }
    }

    return temp.length() == 0 ? 0 : stol(temp);
}

int main() {
    ll num;
    cin >> num;

    vector<ll> past;
    ll count = 0;

    while (true) {
        if (find(past.begin(), past.end(), num) != past.end()) {
            break;
        }

        past.push_back(num);
        num++;
        num = removeTrailingZeros(num);
        count++;
    }

    print(count);
    return 0;
}