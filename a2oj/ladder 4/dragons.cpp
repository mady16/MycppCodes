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

struct dragons{
    int s,b;
};

int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif
    int s,n;
    cin>>s>>n;
    dragons d[n];
    foreq(i,0,n-1){
        cin>>d[i].s>>d[i].b;
    }

    sort(d,d+n,[](dragons a,dragons b){return a.s < b.s;});

    foreq(i,0,n-1){
        if(d[i].s < s){
            s += d[i].b;
        }else{
            print("NO");
            return 0;
        }
    }
    print("YES");
    return 0;
}