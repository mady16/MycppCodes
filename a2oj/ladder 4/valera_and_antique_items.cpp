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


int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif
    int n,v;
    cin>>n>>v;
    int total = 0;

    int items,price;
    vector<int> sellers;
    foreq(i,0,n-1){
        cin>>items;
        bool flag = true;
        foreq(j,0,items-1){
            cin>>price;
            if(price < v && flag){
                total++;
                flag = false;
                sellers.push_back(i+1);
            }
        }
    }

    print(total);

    foreq(i,0,total-1){
        cout<<sellers[i]<<" ";
    }

    cout<<"\n";

    return 0;
}