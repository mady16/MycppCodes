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

#define sq(a) (a)*(a)


// ios::sync_with_stdio(0);
// cin.tie(0);


int main(){
    ll n,x,y;
    cin>>n>>x>>y;

    string num;
    cin>>num;

    ll count = 0;

    for(int i=n-1;i>=n-x;i--){
        if((num[i] == '1' && i != n-y-1) || (num[i] == '0' && i == n-y-1)){
            count++;
        }
    }

    print(count);

    return 0;
}