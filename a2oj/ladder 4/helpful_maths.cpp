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
    string s;
    cin>>s;
    int arrlen = int(s.length()/2)+1;
    
    if(arrlen != 0){
        int a[arrlen];
        foreq(i,0,arrlen-1){
            a[i] = int(s[2*i]);
        }

        sort(a,a+arrlen);
        int k = 0;
        foreq(i,0,s.length()-1){
            if(i%2 == 0){
                s[i] = char(a[k]);
                k++;
            }else
                s[i] = '+';
        }
    }
        print(s);


    return 0;
}