#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define foreq(i,a,b) for (int i = a; i <= b; i++)


bool comp(string a, string b){
    if(a.size() != a.size()) return a.size() < b.size();
    else a < b;
}

int main(){
 	// #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int k;
    cin>>k;
    string a[k],b[k];
    int len[5] = {0};

    foreq(i,0,k-1){
        cin>>a[i];
        len[a[i].size()]++;
    }
    foreq(i,0,k-1){
        cin>>b[i];
    }

    foreq(i,0,4){
        if(i > 0)
            len[i] += len[i-1];
    }

    sort(a,a+k,comp);
    sort(b,b+k,comp);

    foreq(i,0,4){
        cout<<len[i]<<" ";
    }

    return 0;
}