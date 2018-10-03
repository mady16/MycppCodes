#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<bitset>
#define ll long long int
#define m 1000000007
using namespace std;

int main(){
    int j=0;
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

ll t;
cin>>t;
while(t--)
{
    ll n,sum=0;
    cin>>n;
    for(ll i=2;i<n;i*=2)
    {
        for(ll j=1;j<i;j*=2)
        {
            if((i+j)<=n)
            {
                sum=(sum+i+j)%m;
            }
        }
    }
    cout<<sum%m<<"\n";
}
    return 0;
}