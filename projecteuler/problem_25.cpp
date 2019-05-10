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

string add(string str1, string str2) {
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length()) swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate lenght of both string
    int n1 = str1.length(), n2 = str2.length();

    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i = 0; i < n1; i++) {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');

        // Calculate carry for next step
        carry = sum / 10;
    }

    // Add remaining digits of larger number
    for (int i = n1; i < n2; i++) {
        int sum = ((str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // Add remaining carry
    if (carry) str.push_back(carry + '0');

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}

int main() {
    string last = "1", last2 = "1";
    string curr = "";

    int index = 2;

    while (last.length() != 1000) {
        // print((float)last.length()/10<<"%");
        curr = add(last, last2);
        last2 = last;
        last = curr;
        index++;
    }

    print(last);

    print(last.length());
    print(index);

    return 0;
}