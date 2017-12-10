#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long int n,q;
    cin>>n>>q;
    long long int a[n],sum[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum[i]=0;
        if(i!=0)
            sum[i]=sum[i-1]+a[i];
        else 
            sum[0]=a[0];
        // cout<<sum[i]<<" ";
    }

    while(q--){
        int decider,l,r,mean;
        cin>>decider>>l>>r;
        // cout<<mean<<endl;
        if(l<0 && r>=n){
            cout<<"-1"<<endl;
        }
        else if(decider==2){
            if(l!=0)
                mean=(sum[r]-sum[l-1]);
            else
                mean=(sum[r]);
            cout<<mean<<endl;
        }
        else if(decider==1){
            a[l]=r;
            for(int i=0;i<n;i++){
                sum[i]=0;
            if(i!=0)
                sum[i]=sum[i-1]+a[i];
            else 
                sum[0]=a[0];
            }
        }
    }
    return 0;
}