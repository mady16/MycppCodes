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
    if(n%4==0 || n%7==0 || n%44==0 || n%47==0 || n%74==0 || n%77==0 || n%447==0 || n%477==0 || n%444==0 || n%474==0){
        print("YES");
        return 0;
    }
    string s = to_string(n);
    foreq(i,0,s.length()-1){
        if(s[i] != '4' && s[i] != '7'){
            print("NO");
            return 0;
        }
    }

    print("YES");

    return 0;
}