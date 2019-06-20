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


// ios::sync_with_stdio(0);
// cin.tie(0);

struct circle{
    int x,y,r;
};


int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    circle c[n];
    float d[n][n];

    foreq(i,0,n-1){
        cin>>c[i].x>>c[i].y>>c[i].r;
    }

    foreq(i,0,n-1){
        foreq(j,i+1,n-1){
            float td=sqrt(pow(c[i].x - c[j].x,2) + pow(c[i].y - c[j].y,2));
            d[i][j] = td - c[i].r - c[j].r;
            if( td == 0 )
                d[j][i] = 2*max(c[i].r,c[j].r);
            else
                d[j][i] = td + c[i].r + c[j].r;
        }
    }
    int k;
    foreq(p,0,q-1){
        cin>>k;
        int count = 0;
        foreq(i,0,n-1){
            foreq(j,i+1,n-1){
                if(max(d[i][j],d[j][i]) >= float(k) && float(k) >= min(d[i][j],d[j][i]) ) count++;
            }
        }
        print(count);
    }

    return 0;
}