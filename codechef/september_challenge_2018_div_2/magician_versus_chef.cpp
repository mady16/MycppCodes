#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
#define foreq(i,a,b) for (int i = a; i <= b; i++)

#define swap(A,swapi,swapj) {A[swapi] = A[swapi] + A[swapj]; A[swapj] = A[swapi]-A[swapj]; A[swapi] = A[swapi]-A[swapj];}

#define printA(A,n) foreq(p,0,n-1){cout<<p<<": "<<A[p]<<endl;}
#define print(s) cout<<s<<endl;

#define sq(a) (a)*(a)

// ios::sync_with_stdio(0);
// cin.tie(0);

int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif
    int t;
    cin>>t;
    while(t--){
        ll n,s,x;
        cin>>n>>x>>s;
        int a[n+1]={0};
        a[x] = 1;
        foreq(i,0,s-1){
            int p,q;
            cin>>p>>q;
            swap(a,p,q);
        }

        foreq(i,0,n){
            if(a[i]){
                print(i);
                break;
            }
        }
    }

    return 0;
}