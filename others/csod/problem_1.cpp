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

string correctText(string text) {
    size_t index = 0;

    while (true) {
        index = text.find("0", index);
        if (index == std::string::npos) break;
        text.replace(index, 1, "o");
        index += 1;
    }

    index = 0;
    while (true) {
        index = text.find("1", index);
        if (index == std::string::npos) break;
        text.replace(index, 1, "l");
        index += 1;
    }

    index = 0;
    while (true) {
        index = text.find("2", index);
        if (index == std::string::npos) break;
        text.replace(index, 1, "z");
        index += 1;
    }

    index = 0;
    while (true) {
        index = text.find("5", index);
        if (index == std::string::npos) break;
        text.replace(index, 1, "s");
        index += 1;
    }

    return text;
}

int countOccurences(string texts[], int numberOfLines, string pattern) {
    int count = 0, index = 0;

    foreq(i, 0, numberOfLines-1) {
        index=0;
        while (true) {
            index = texts[i].find(pattern, index);
            if (index == std::string::npos) break;
            index += 1;
            count++;
        }
    }

    return count;
}

int main() {

    int n;
    cin >> n;
    cin.ignore();
    string texts[n];
    foreq(i, 0, n-1) {
        getline(cin, texts[i]);
        texts[i] = correctText(texts[i]);
    }

    int m;
    cin >> m;
    string patterns[m];
    foreq(i, 1, m) {
        cin >> patterns[i - 1];
        print(countOccurences(texts, n, patterns[i - 1]));
    }

    return 0;
}