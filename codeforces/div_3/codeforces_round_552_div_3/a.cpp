#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
#define foreq(i,a,b) for (int i = a; i <= b; i++)

#define printA(A,n) foreq(p,0,n-1){cout<<p<<": "<<A[p]<<endl;}
#define print(s) cout<<s<<" "
#define scan(s) cin>>s
#define scanA(A, n) foreq(p,0,n-1){cin>>A[p];}
#define sq(a) (a)*(a)


// ios::sync_with_stdio(0);
// cin.tie(0);


int main(){
    ll a,b,c,sum;
    ll *maxp;
    *maxp = 0;

    scan(a);
    if(*maxp < a) maxp = &a;
    scan(b);
    if(*maxp < b) maxp = &b;
    scan(c);
    if(*maxp < c) maxp = &c;
    scan(sum);
    if(*maxp < sum) maxp = &sum;

    swap(*maxp, sum);
    print((sum-a));
    print((sum-b));
    print((sum-c));
    cout<<endl;
    return 0;
}