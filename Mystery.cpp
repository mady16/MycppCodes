
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
unsigned long long int n;

while(cin>>n)
{
int c=0;
while(n)
{
n=n&(n-1);
c++;
}
cout<<c<<endl;
}

    return 0;
}