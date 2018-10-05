#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;

typedef long long ll;
#define foreq(i,a,b) for (int i = a; i <= b; i++)

#define swap(A,swapi,swapj) {A[swapi] = A[swapi] + A[swapj]; A[swapj] = A[swapi]-A[swapj]; A[swapi] = A[swapi]-A[swapj];}

#define printA(A,n) foreq(p,0,n-1){cout<<p<<": "<<A[p]<<endl;}
#define print(s) cout<<s<<endl

#define sq(a) (a)*(a)


// ios::sync_with_stdio(0);
// cin.tie(0);


int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif
    int n, m;
    cin>>n>>m;
    int a[m];
    foreq(i,0,m-1) cin>>a[i];

    sort(a,a+m);
    int min = INT_MAX; 
    foreq(i,0,m-n){
        if((a[i+n-1] - a[i]) < min ) min = a[i+n-1] - a[i];
    }

    print(min);


    return 0;
}