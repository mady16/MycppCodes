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
    ll n;
    cin>>n;
    if(n >= 0) print(n);
    else{
        string s = to_string(n);
        string s1 = to_string(n);
        if(s.length() > 2){
            ll n1 = stol(s.erase(s.length()-1,1));
            ll n2 = stol(s1.erase(s1.length()-2,1));
            print(max(n1,max(n2,n)));
        }else{
            print(0);
        }

    }

    return 0;
}