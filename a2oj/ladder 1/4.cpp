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

bool comp(char i,char j){
    
}

int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif

    int num;
    cin>>num;
    while(num--){
        string s;
        cin>>s;
        int alpha[26]= {0},maxi = 0,max = 0;
        foreq(i,0,s.length()-1){
            alpha[s[i]-97]++;
        }
    
        max = *max_element(alpha,alpha+26);

        print(max<<" "<<char(97 + distance(alpha,max_element(alpha,alpha+26))));
    }

    return 0;
}