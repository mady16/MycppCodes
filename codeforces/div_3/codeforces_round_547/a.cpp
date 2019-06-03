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
    ll n,m;
    scan(n);scan(m);

    if(m%n != 0){
        print(-1);
    }else{
        ll div = m/n;
        ll count = 0;
        while(div != 1){
            if(div%2 == 0){
                div /= 2;
                count++;
            }else if(div%3 == 0){
                div /= 3;
                count++;
            }else{
                print(-1);
                return 0;
            }
        }
        print(count);
    }
    return 0;
}