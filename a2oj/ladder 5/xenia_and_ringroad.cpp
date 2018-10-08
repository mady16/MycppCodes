#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
#define foreq(i,a,b) for (ll i = a; i <= b; i++)

#define printA(A,n) foreq(p,0,n-1){cout<<p<<": "<<A[p]<<endl;}
#define print(s) cout<<s<<endl

#define sq(a) (a)*(a)


// ios::sync_with_stdio(0);
// cin.tie(0);
// cout.tie(0);


int main(){
    ll n,m,x = 1,count=0;
    cin>>n>>m;
    int a;
    foreq(i,0,m-1){
        cin>>a;
        if( a > x){
            count += a - x;
        }
        if( a < x){
            count += n - x + a;
        }
        x = a;
    }

    print(count);

    return 0;
}