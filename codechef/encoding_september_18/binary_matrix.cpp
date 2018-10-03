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


// ios::sync_with_stdio(0);
// cin.tie(0);


int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        short a[n][n];

        int ies[n];
        int jes[n];
        foreq(i,0,n-1){
            foreq(j,0,n-1){
                cin>>a[i][j];
                if(!a[i][j]){
                    ies[i] = 1;
                    jes[j] = 1;
                }
            }
        }

        foreq(i,0,n-1){
            foreq(j,0,n-1){
                if(ies[i] == 1 || jes[j] == 1){
                    cout<<"0 ";
                }else
                    cout<<"1 ";
            }
            cout<<"\n";
        }

    }

    return 0;
}