#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
#define foreq(i,a,b) for (int i = a; i <= b; i++)
#define printA(A,n) foreq(p,0,n-1){cout<<A[p]<<" ";} cout<<endl;
#define print(s) cout<<s<<endl
#define scan(s) cin>>s
#define scanA(A, n) foreq(p,0,n-1){cin>>A[p];}
#define sq(a) (a)*(a)


// ios::sync_with_stdio(0);
// cin.tie(0);

int fibonacci(int n){
    return n <= 1 ? n : fibonacci(n-1) + fibonacci(n-2);
}

ll binetsFormula(ll n){
    return (pow(1 + sqrt(5) , n) - pow( 1 - sqrt(5), n)) / ( pow(2,n)* sqrt(5));
}


int main(){
    
    //print(fibonacci(20));
    print(binetsFormula(50));
    return 0;
}