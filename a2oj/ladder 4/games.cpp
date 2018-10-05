#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
#define foreq(i,a,b) for (int i = a; i < b; i++)

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
    int a[n][2];

    foreq(i,0,n){
        cin>>a[i][0]>>a[i][1];
    }

    int result = 0;

    foreq(i,0,n){
        foreq(j,i+1,n){
            if(a[i][0] == a[j][1]) result++;
            if(a[i][1] == a[j][0]) result++;
        }
    }

    print(result);

    return 0;
}