#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
#define foreq(i,a,b) for (int i = a; i <= b; i++)
#define printA(A,n) foreq(p,0,n-1){cout<<A[p]<<" ";} cout<<endl;
#define print(s) cout<<s<<endl
#define scan(s) cin>>s
#define scanA(A, n) foreq(p,0,n-1){cin>>A[p];}
#define sq(a) (a)*(a)


// ios::sync_with_stdio(0);
// cin.tie(0);


int main(){
    ll n;
    scan(n);

    ll A[n];
    scanA(A,n);

    bool checkAll = false;
    bool even = false;
    bool odd = false;
    foreq(i,0,n-1){
        if(A[i]%2 == 0 && odd == false){
            even = true;
        }else if(A[i]%2 == 1 && even == false){
            odd = true;
        }else{
            checkAll = true;
            break;
        }
    }

    if(checkAll){
        sort(A, A+n);
        printA(A, n);
    }else{
        printA(A, n);
    }

    return 0;
}