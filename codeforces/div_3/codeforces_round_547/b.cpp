#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
#define foreq(i,a,b) for (int i = a; i <= b; i++)

#define printA(A,n) foreq(p,0,n-1){cout<<p<<": "<<A[p]<<endl;}
#define print(s) cout<<s<<endl
#define scan(s) cin>>s
#define scanA(A, n) foreq(p,0,n-1){cin>>A[p];}
#define sq(a) (a)*(a)


// ios::sync_with_stdio(0);
// cin.tie(0);


int main(){
    ll n;
    scan(n);
    int A[n];
    scanA(A, n);

    ll max = 0;
    ll curr = 0;
    ll startmax = 0;
    bool first = true;
    foreq(i,0,n-1){
        if(A[i] == 1){
            curr++;
            if(max < curr){
                max = curr;
            }
            if(first){
                startmax++;
            }
        }else{
            first = false;
            curr = 0;
        }
    }

    if(curr != 0 && startmax > 0){
        if(curr+startmax > max){
            max = curr+startmax;
        }
    }

    print(max);
    return 0;
}