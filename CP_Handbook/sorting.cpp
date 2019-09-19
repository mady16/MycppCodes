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

void sort1(vector<int> &num) {
    int n = num.size();
    forless(i, 0, n) {
        forless(j, i + 1, n) {
            if (num[i] > num[j]) iter_swap(num.begin() + i, num.begin() + j);
        }
    }
}

// merge sort
vector<int> sort2(vector<int> num) {
    if (num.size() == 1) return num;

    int mid = num.size() / 2;

    vector<int> left = sort2(vector<int>(num.begin(), num.begin() + mid));
    vector<int> right = sort2(vector<int>(num.begin() + mid, num.end()));

    vector<int> result;

    vector<int>::iterator a = left.begin();
    vector<int>::iterator b = right.begin();

    while (a != left.end() || b != right.end()) {
        if (a != left.end() && (b == right.end() || *a <= *b)) {
            result.push_back(*a);
            a++;
        } else {
            result.push_back(*b);
            b++;
        }
    }

    return result;
}

int main() {
    vector<int> num = {1, 2, 2, 6, 3, 5, 9, 8};
    num = sort2(num);
    printA(num, num.size());
    return 0;
}