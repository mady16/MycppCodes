#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
#define foreq(i,a,b) for (int i = a; i <= b; i++)
#define forless(i,a,b) for (int i = a; i < b; i++)
#define rforeq(i,a,b) for (int i = a; i >= b; i--)
#define rforless(i,a,b) for (int i = a; i > b; i--)
#define printA(A,n) foreq(p,0,n-1){cout<<A[p]<<" ";} cout<<endl;
#define print(s) cout<<s<<endl
#define scan(s) cin>>s
#define scanA(A, n) foreq(p,0,n-1){cin>>A[p];}
#define sq(a) (a)*(a)


// ios::sync_with_stdio(0);
// cin.tie(0);

int minimumCoins(vector<int> coins, int value){
    int n = 0;
    while(value > 0){
        auto a = equal_range(coins.begin(), coins.end(), value);
        if(a.first == coins.end()){
            value = value - *(a.first-1);
        }else if(*a.first > value){
            a.first--;
            value = value - *a.first;
        }else{
            value = value - *a.first;
        }
        n++;
    }
    return n;
}


int main(){
    print(minimumCoins(vector<int>{1,2,5,10}, 123));
    return 0;
}