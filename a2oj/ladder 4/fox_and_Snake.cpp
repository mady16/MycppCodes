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
    int n,m;
    cin>>n>>m;

    foreq(i,0,n-1){
        foreq(j,0,m-1){
            if(i%2 == 0) cout<<"#";
            else{
                if(i%4 == 1){
                    if(j != m-1) cout<<".";
                    else cout<<"#";
                }else{
                    if(j != 0) cout<<".";
                    else cout<<"#";
                }
            }
        }
        cout<<"\n";
    }

    return 0;
}