#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        n = n-1;
        ll bits = pow(2,n/26);
        ll nibble = 0;
        ll bytes = 0;
        
        int r = n%26;

        if(r != 0 && r/10 > 0){
            bytes = bits;
            bits = 0;
        }else if(r != 0 && r/2 > 0){
            nibble = bits;
            bits = 0;
        }

        print(bits<<" "<<nibble<<" "<<bytes);
    }

    return 0;
}