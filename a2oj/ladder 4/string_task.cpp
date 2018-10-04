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
    string s;
    cin>>s;
    for(int i = s.length()-1;i>=0;i--){
        if(s[i] == 97 || s[i] == 101 || s[i] == 105 || s[i] == 111 || s[i] == 117 || s[i] == 65 || 
            s[i] == 69 || s[i] == 73 || s[i] == 79 || s[i] == 85 || s[i] == 121 || s[i] == 89)
            s.erase(s.begin()+i);
        else if(s[i] > 65 && s[i] < 91)
            s[i] = s[i]+32;
    }
    int k = s.length()-1;
    foreq(i,0,k){
        s.insert(2*i,".");
    }

    print(s);

    return 0;
}