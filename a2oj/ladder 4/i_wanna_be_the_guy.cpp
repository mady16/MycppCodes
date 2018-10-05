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
    int n,a,b,t;
    cin>>n;
    
    cin>>a;
    vector<bool> level(n+1,false);
    level[0] = true;
    foreq(i,0,a-1){
        cin>>t;
        level[t] = true;
    }
    cin>>b;

    foreq(i,0,b-1){
        cin>>t;
        level[t] = true;
    }

    all_of(level.begin(),level.end(),[](bool z){return z;}) ? print("I become the guy.") : print("Oh, my keyboard!");

    return 0;
}