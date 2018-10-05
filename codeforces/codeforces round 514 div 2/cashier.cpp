#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
#define foreq(i,a,b) for (long long i = a; i <= b; i++)

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
    ll n,L,a;
    cin>>n>>L>>a;
    ll res = 0;
    
    if(n != 0){
        ll t[n],l[n];
        foreq(i,0,n-1) cin>>t[i]>>l[i];

        res += t[0]/a;
        foreq(i,0,n-2){
            res += (t[i+1] - t[i]-l[i])/a;
        }
        res += (L - t[n-1] - l[n-1])/a;
    }else{
        res = L/a;
    }
    print(res);
    return 0;
}