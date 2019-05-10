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
    
    int sum[10001] = {0};

    foreq(i,2,9999){
        foreq(j,1,i/2){
            if(i%j == 0){
                sum[i] += j;
            }
        }
    }

    int ans = 0;
    foreq(i,2,10000){
        if(i < sum[i] && sum[i] < 10001 && sum[sum[i]] == i){
            ans += sum[i] + i;
        }
    }

    print(ans);
    return 0;
}