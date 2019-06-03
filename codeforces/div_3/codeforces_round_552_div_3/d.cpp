#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
#define foreq(i,a,b) for (int i = a; i <= b; i++)

#define printA(A,n) foreq(p,0,n-1){cout<<p<<": "<<A[p]<<endl;}
#define print(s) cout<<s<<endl
#define scan(s) cin>>s
#define scanA(A, n) foreq(p,0,n-1){cin>>A[p];}
#define sq(a) (a)*(a)


// ios::sync_with_stdio(0);
// cin.tie(0);


int main(){
    ll n,b,a;
    scan(n);
    scan(b);
    scan(a);

    ll maxb = b;
    ll maxa = a;

    bool path[n];
    scanA(path, n);

    ll count = 0;
    foreq(i,0,n-1){
        if(!path[i] && a > 0 || (b == 0 && a > 0)){
            a--;
        }else if( !path[i] && b > 0){
            b--;
        }else if(path[i] && a < maxa && b > 0){
            b--;
            a++;
        }else if(path[i] && a == maxa && b <= maxb){
            a--;
        }else{
            break;
        }
        count++;
    }

    print(count);

    return 0;
}