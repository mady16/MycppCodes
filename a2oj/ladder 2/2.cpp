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
        int n,m;
        cin>>n>>m;
        int a[n+2][m+2], total = 0;
        bool teams[101] = {false};
        foreq(i,0,n+1){
            foreq(j,0,m+1){
                if(i == 0 || j == 0 || i == n+1 || j == m+1) a[i][j] = -100;
                else cin>>a[i][j];
            }
        }

        foreq(i,1,n){
            foreq(j,1,m){
                int p = a[i][j];
                if(p != -1)
                if(teams[p] == false && (p == a[i-1][j-1] || p == a[i-1][j+1] || p == a[i-1][j] || p == a[i][j-1] ||
                    p == a[i][j+1] || p == a[i+1][j-1] || p == a[i+1][j] || p == a[i+1][j+1])){
                        teams[p] = true;
                        total++;
                }
            }
        }

        print(total);


    }

    return 0;
}