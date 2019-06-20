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

struct days{
    long a;
    long b;
    long c;
};

vector<days> bestSort(vector<days> day,ll n){
    vector<days> newd;
    bool flag = true;
    foreq(i,0,n-2){
        if(flag){
            if( day[i].c > day[n-1].c || (day[i].c == day[n-1].c && day[i].b > day[n-1].b) ){
                newd.push_back(day[n-1]);
                i--;
                flag = false;
            }else newd.push_back(day[i]);
        }else{
            newd.push_back(day[i]);
        }
    }
    if(flag == true) newd.push_back(day[n-1]);

    return newd;
}


int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int n;
    ll m,sum = 0;
    cin>>n>>m;
    vector<days> day(n);

    foreq(i,0,n-1) cin>>day[i].a;
    foreq(i,0,n-1){
        cin>>day[i].b;
        day[i].c = day[i].a*day[i].b;
        sum += day[i].a;
    }
    if(sum <= m ){
        print(0);
        return 0;
    }

    sort(day.begin(),day.end(),[](days a, days b){ if(a.c == b.c) return (a.b < b.b); else return (a.c < b.c); });

    // print("Sorting done!");

    // foreq(i,0,n-1) cout<<day[i].c <<" ";
    // cout<<endl;

    for(ll i = m;i > 0;){
        ll temp = ceil(float(day[n-1].c - day[n-2].c)/float(day[n-1].b));

        if(temp <= 0) temp = 1;
        day[n-1].a -= temp;
        day[n-1].c = max(long(0),day[n-1].a)*day[n-1].b;
        i = i-temp;
        day = bestSort(day,n);

        // foreq(j,0,n-1) cout<<day[j].a <<" ";
        // cout<<endl;
    }
    // foreq(i,0,n-1) cout<<day[i].c <<" ";
    // cout<<endl;

    // ll maxi = distance(day.begin(),max_element(day.begin(),day.end(),[](days a, days b){ if(a.c == b.c) return (a.b < b.b); else return (a.c < b.c); } ));

    print(day[n-1].c);

    return 0;
}