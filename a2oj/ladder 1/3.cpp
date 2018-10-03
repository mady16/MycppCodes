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
    ll no;
    cin>>no;
    while(no--){
        ll n,x,y;
        cin>>n>>x>>y;
        int a;
        ll result = 0;
        cin>>a;
        if(a == x) result = 1;
        foreq(i,1,n-2){
            cin>>a;
        }
        cin>>a;
        if(a == y && result == 1) result = 2;
        if(a == y && result == 0) result = -1;
        
        switch(result){
            case 0: print("OKAY"); break;
            case -1: print("HARD"); break;
            case 1: print("EASY"); break;
            case 2: print("BOTH"); break;
        }

    }

    return 0;
}