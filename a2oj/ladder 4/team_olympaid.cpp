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

struct students{
    int s,index;
};


int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif
    int n;
    cin>>n;
    vector<students> s1,s2,s3;

    foreq(i,0,n-1){
        students t;
        t.index = i+1;
        cin>>t.s;
        switch(t.s){
            case 1: s1.push_back(t);
                break;
            case 2: s2.push_back(t);
                break;
            case 3: s3.push_back(t);
                break;
        }
    }
    
    int total = min(s1.size(),min(s2.size(),s3.size()));

    print(total);

    foreq(i,0,total-1){
        print(s1[i].index<<" "<<s2[i].index<<" "<<s3[i].index);
    }


    return 0;
}