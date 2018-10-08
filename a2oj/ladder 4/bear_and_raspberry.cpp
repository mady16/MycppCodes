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
    int n,c;
    cin>>n>>c;
    int prev=-1,curr;
    int max = 0;

    foreq(i,0,n-1){
        cin>>curr;
        if(prev != -1){
            if(prev-curr-c > max) max = prev-curr-c;
        }
        prev = curr;
    }

    print(max);

    return 0;
}