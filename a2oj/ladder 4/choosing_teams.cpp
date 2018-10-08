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
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif

    int n,k;
    cin>>n>>k;
    int a[n];
    foreq(i,0,n-1) cin>>a[i];

    sort(a,a+n);

    int total = 0;
    foreq(i,0,n-3){
        int t = max(a[i],max(a[i+1],a[i+2]));
        if(5 - t < k){
            break;
        }else{
            total++;
        }
        i += 2;
    }

    print(total);
    return 0;
}