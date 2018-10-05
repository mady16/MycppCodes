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

bool comp(int a,int b){
    return a <= b;
}

int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif
    int n;
    cin>>n;
    int a[n];
    foreq(i,0,n-1) cin>>a[i];

    int maxi = distance(a,max_element(a,a+n));
    int mini = distance(a,min_element(a,a+n,comp));

    if(maxi == mini){
        print(0);
    }else if(maxi < mini){
        print(maxi+n-1-mini);
    }else{
        print(maxi+n-1-mini-1);
    }

    return 0;
}