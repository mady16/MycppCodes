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



int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif

    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n,m,x,y;
        cin>>n>>m>>x>>y;
        ll p=1,q=1;
        ll nx = n/x;
        if(nx > 2){
            p += (nx-2)*x;
        }
        ll my = m/y;
        if(my > 2){
            q += (my-2)*y;
        }
        while(n != p || m != q){
            if(p+x == n && q+y == m){
                p += x;
                q += y;
                break;
            }else if(p == n-1 && q == m-1) {
                p += 1; q += 1;
                break;
            }else if(x+p > n && y+q > m){
                break;
            }else{
                if(x+p < n ) p += x;
                if(y+q < m ) q += y;
            }
        }
        // print("p: "<<p<<" q: "<<q);
        if(n == p && m == q){ 
            print("Chefirnemo");
        }else{ 
            print("Pofik");
        }
    }

    return 0;
}