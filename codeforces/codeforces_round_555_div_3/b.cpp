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
    ll n;
    cin>>n;

    string num;
    cin>>num;

    ll conversion[10];
    foreq(i,1,9){
        cin>>conversion[i];
    }

    int digit;
    bool used = false;
    foreq(i,0,n-1){
        digit = num[i] - '0';
        if(digit < conversion[digit] || (used && digit == conversion[digit])){
            num[i] = conversion[digit] + '0';
            used = true;
        }else if(used){
            break;
        }
    }

    print(num);
    return 0;
}