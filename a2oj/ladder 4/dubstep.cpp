// correct problem and correct solution

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
    string s;
    cin>>s;
    string wub = "WUB";
    size_t f = s.find(wub);
    int previous = -1;
    while(f != string::npos){
        s.erase(f,3);
        if(f != 0 && previous+1 != f) s.insert(f," ");
        previous = f;
        f = s.find(wub);
    }

    print(s);

    return 0;
}



// ========= wrong problem correct solution ==============
#include <iostream>
#include <string>
using namespace std;
int main()
{
string S;
cin >> S;
string t = " ";
bool flag = true;
while (flag)
{
if (S.find("WUB") != string::npos)
{
S.replace(S.find("WUB"), 3, t);
// S.erase(S.find("WUB",3));
}
else
flag = false;
}
cout << S << endl;
}