#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;

typedef long long ll;
#define foreq(i,a,b) for (int i = a; i <= b; i++)
#define forless(i,a,b) for (int i = a; i < b; i++)
#define rforeq(i,a,b) for (int i = a; i >= b; i--)
#define rforless(i,a,b) for (int i = a; i > b; i--)
#define printA(A,n) { foreq(p,0,n-1){cout<<A[p]<<" ";} cout<<endl;}
#define print(s) cout<<s<<endl
#define scan(s) cin>>s
#define scanA(A, n) foreq(p,0,n-1){cin>>A[p];}
#define sq(a) (a)*(a)


// ios::sync_with_stdio(0);
// cin.tie(0);

void generate_subsets1(vector<int> num, vector<int> subset, int n){
    if(n == num.size()){
        if(subset.size() != 0)
            printA(subset, subset.size());
        return;
    }
    generate_subsets1(num, subset , n+1);
    subset.push_back(num[n]);
    generate_subsets1(num, subset , n+1);
    subset.pop_back();
}

template<size_t bitsetsize>
void generate_subsets2(vector<int> num, bitset<bitsetsize> subset){
    foreq(i, 0, (1 << num.size())){
        subset = i;
        foreq(j, 0, num.size()){
            if(subset[j]) cout<<num[j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<int> num{1, 2, 3, 4, 5};
    generate_subsets2(num, bitset<5>(0));
    return 0;
}