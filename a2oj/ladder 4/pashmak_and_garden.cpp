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

    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    if(x1 == x2){
        print(x1+abs(y2-y1)<<" "<<y1<<" "<<x2+abs(y2-y1)<<" "<<y2);
    }else if(y1 == y2){
        print(x1<<" "<<y1+abs(x2-x1)<<" "<<x2<<" "<<y2+abs(x2-x1));
    }else if( abs(x2-x1) == abs(y2-y1) ){
        if( (x1 < x2 && y1 < y2) || (x1 > x2 && y1 > y2) )
            print(max(x1,x2)<<" "<<min(y1,y2)<<" "<<min(x1,x2)<<" "<<max(y2,y1));
        else
            print(min(x1,x2)<<" "<<min(y1,y2)<<" "<<max(x1,x2)<<" "<<max(y2,y1));
    }else{
        print(-1);
    }

    return 0;
}