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

    int n;
    cin>>n;
    int a[n];
    foreq(i,0,n-1) cin>>a[i];

    sort(a,a+n);

    foreq(j,0,n){
        int sumB = 0,sumL = 0;
        foreq(k,0,n-1){
            if(k < j)
                sumB += a[n-1-k];
            else 
                sumL += a[k-j];
        }
        if(sumB > sumL){
            print(j);
            break;
        }
    }

    return 0;
}