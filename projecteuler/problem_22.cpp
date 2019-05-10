#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
#define foreq(i, a, b) for (int i = a; i <= b; i++)

#define swap(A, swapi, swapj)           \
    {                                   \
        A[swapi] = A[swapi] + A[swapj]; \
        A[swapj] = A[swapi] - A[swapj]; \
        A[swapi] = A[swapi] - A[swapj]; \
    }

#define printA(A, n) \
    foreq(p, 0, n - 1) { cout << p << ": " << A[p] << endl; }
#define print(s) cout << s << endl

#define sq(a) (a) * (a)

// ios::sync_with_stdio(0);
// cin.tie(0);

int main() {
    fstream namesfile("/home/vikasgola/Downloads/names.txt", ios::in);

    string names_string;
    getline(namesfile, names_string);

    regex namepatten("[a-zA-Z]+");
    smatch names_match;

    vector<string> names;

    while (regex_search(names_string, names_match, namepatten)) {
        names.push_back(names_match.str());
        names_string = names_match.suffix();
    }

    sort(names.begin(), names.end());

    long total_scores = 0;
    int tempscore;
    int index = 1;
    for (auto name : names) {
        tempscore = 0;
        foreq(i, 0, name.length() - 1) {
            tempscore += (name[i] - 65 + 1);
        }
        total_scores += tempscore * index;
        index++;
    }

    print(total_scores);

    return 0;
}