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

int main() {
    ll n;
    cin >> n;
    vector<char> str;
    char temp;
    foreq(i, 0, n - 1) {
        cin >> temp;
        str.push_back(temp);
    }


    if (n % 2 == 1) {
        str.pop_back();
    }

    int i = 0;
    while (i < (int)str.size() - 1) {
        if (str[i] == str[i + 1]) {
            str.erase(str.begin() + i);
            str.erase(str.begin() + i);
        } else {
            i += 2;
        }
    }

    string good(str.begin(), str.end());
    print(n - good.length());
    print(good);
    return 0;
}