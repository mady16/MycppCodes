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
    
int n;
cin>>n;
int a[n][100];
    for(int i=0;i<n;i++){
        long long int k;
        cin>>k;
        for(int j=99;j>=0;j--){
            a[i][j]=k%10;
            k=k/10;
        }
    }
    int sum[100]={0};

    for(int j=99;j>=0;j--){        
        for(int i=0;i<n;i++){
            sum[j]=sum[j]+a[i][j];
        }
        sum[j-1]=sum[j]/10;
        sum[j]=sum[j]%10;
        // cout<<sum[j]<<endl;
    }
    int flag=0;
   for(int i=0;i<100;i++){
       if(flag || sum[i]){
       cout<<sum[i];
        flag=1;
       }      
   }  

    return 0;
}