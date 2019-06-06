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

int main() {
    ll t;
    scan(t);
    vector<ll> forloop;
    string command;
    bool isOverflow = false;

    ll insideAddCount = 0;
    ll x = 0;
    vector<ll> addcount;

    while (t--) {
        cin >> command;

        if (command == "end") {
            ll loopadd = 1;
            if (insideAddCount) {
                foreq(i, 0, forloop.size() - 1) {
                    loopadd *= forloop[i];
                    if ((loopadd > 4294967295 || loopadd < 0)) {
                        print("OVERFLOW!!!");
                        return 0;
                    }
                }
                x += loopadd * insideAddCount;
            }
            if (x > 4294967295 || x < 0) {
                print("OVERFLOW!!!");
                return 0;
            }
            insideAddCount = addcount[addcount.size() - 1];
            forloop.pop_back();
            addcount.pop_back();
        } else if (command == "add") {
            insideAddCount++;
        } else if (command == "for") {
            ll loop;
            scan(loop);
            forloop.push_back(loop);
            addcount.push_back(insideAddCount);
            insideAddCount = 0;
        }

        if (x > 4294967295 || x < 0) {
            print("OVERFLOW!!!");
            return 0;
        }
    }

    x += insideAddCount;
    if (x > 4294967295 || x < 0) {
        print("OVERFLOW!!!");
        return 0;
    }
    print(x);

    return 0;
}