#include <algorithm>
#include <cmath>
#include <iostream>
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
    int day = 0;
    int total_mondays = 0;

    foreq(year, 0, 100) {
        foreq(month, 1, 12) {
            int ndays;
            switch (month) {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    ndays = 31;
                    break;
                case 2:
                    if(year%4 == 0 ){
                        ndays = 29;
                    }else{
                        ndays = 28;
                    }

                default:
                    ndays = 30;
                    break;
            }

            foreq(dates, 1, ndays) {
                if(day == 0 && dates == 1 && year > 0){
                    total_mondays++;
                }
                day++;
                day = day%7;
            }
        }
    }


    print(total_mondays);

    return 0;
}