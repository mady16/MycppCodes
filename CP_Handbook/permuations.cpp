#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;

typedef long long ll;
#define foreq(i,a,b) for (int i = a; i <= b; i++)
#define forless(i,a,b) for (int i = a; i < b; i++)
#define rforeq(i,a,b) for (int i = a; i >= b; i--)
#define rforless(i,a,b) for (int i = a; i > b; i--)
#define printA(A,n) foreq(printi,0,n-1){cout<<A[printi]<<" ";} cout<<endl;
#define print(s) cout<<s<<endl
#define scan(s) cin>>s
#define scanA(A, n) foreq(p,0,n-1){cin>>A[p];}
#define sq(a) (a)*(a)


// ios::sync_with_stdio(0);
// cin.tie(0);

void permuation1(vector<int> num, unordered_set<int> p, int n){
    if(n == num.size()){
        for(auto t = p.begin(); t != p.end(); ++t){
            cout<<*t<<" ";
        }
        cout<<endl;
        return;
    }

    foreq(i, 0, num.size()-1){
        if(!p.count(num[i])){
            p.insert(num[i]);
            permuation1(num, p , n+1);
            p.erase(num[i]);
        }
    }
}

void permuation2(vector<int> num){
    do{
        printA(num, num.size());
    }while(next_permutation(num.begin(), num.end()));
}

int main(){
    vector<int> num{1, 2, 3};

    permuation2(num);
    return 0;
}