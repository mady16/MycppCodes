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
    int n;
    cin>>n;

    string s[n];

    foreq(i,0,n-1) cin>>s[i];

    foreq(i,0,n-1){
        foreq(j,0,n-1){
            int t = 0;
            if(j-1 >= 0 && s[i][j-1] == 'o') t++;
            if(j+1 < n  && s[i][j+1] == 'o') t++;
            if(i-1 >= 0 && s[i-1][j] == 'o') t++;
            if(i+1 < n && s[i+1][j] == 'o') t++;

            if(t%2 == 1){
                print("NO");
                return 0;
            }
        }
    }

    print("YES");

    return 0;
}