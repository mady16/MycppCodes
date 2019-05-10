#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
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
    string number;
    int number_of_letters = 0;

    string single_digits[] = {"zero", "one", "two",   "three", "four",
                              "five", "six", "seven", "eight", "nine"};

    /* The first string is not used, it is to make
        array indexing simple */
    string two_digits[] = {"",          "ten",      "eleven",  "twelve",
                           "thirteen",  "fourteen", "fifteen", "sixteen",
                           "seventeen", "eighteen", "nineteen"};

    /* The first two string are not used, they are to make
        array indexing simple*/
    string tens_multiple[] = {"",      "",      "twenty",  "thirty", "forty",
                              "fifty", "sixty", "seventy", "eighty", "ninety"};

    string tens_power[] = {"hundred", "thousand"};

    foreq(i, 1, 1000) {
        number = to_string(i);
        reverse(number.begin(), number.end());
        switch (number.length()) {
            case 3:
            case 4:
                if (number.length() == 3) {
                    number_of_letters += single_digits[number[2] - 48].length();
                    number_of_letters += tens_power[0].length();
                    if(number[1] != '0' || number[0] != '0'){
                        number_of_letters += 3;
                    }
                } else {
                    number_of_letters += single_digits[number[3] - 48].length();
                    number_of_letters += tens_power[1].length();
                }
            case 2:
                number_of_letters += tens_multiple[number[1] - 48].length();
                if (number[1] == '1'){
                    number_of_letters += two_digits[number[0] - 48 + 1].length();
                }else if(number[0] != '0') {
                    number_of_letters += single_digits[number[0] - 48].length();
                }
                break;
            case 1:
                number_of_letters += single_digits[number[0] - 48].length();
                break;
        }
    }
    print(number_of_letters);
    return 0;
}