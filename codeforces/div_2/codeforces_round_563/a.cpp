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

    ll A[2*n];
    scanA(A,2*n);

    sort(A,A+2*n);

    ll sum1 = 0,sum2 = 0;

    foreq(i,0,n-1){
        sum1 += A[i];
        sum2 += A[i+n];
    }

    if(sum1 == sum2){
        print(-1);
    }else{
        printA(A,2*n);
    }
    

    return 0;
}