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

    ll n,l;
    cin>>n>>l;
    string s;
    cin>>s;
    string swle;
    float lerror = 100;
    while(n--){
        string c;
        cin>>c;
        float cerror = 0;
        foreq(i,0,l-1){
            if(c[i] != s[i]) cerror++;
        }
        cerror = cerror*100.0/s.size();
        if(cerror < lerror){ 
            lerror = cerror;
            swle = c;
        }
    }

    print(swle);

    return 0;
}