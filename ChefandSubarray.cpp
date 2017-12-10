#include<iostream>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

long long sum(long long a[],long long q,long long w){
    long long sumn=0;
    for(int i=q;i<=w;i++){
        sumn=sumn+a[i];
    }
    return sumn;
}

long long mul(long long a[],long long q,long long w){
    long long mult=1;
    for(int i=q;i<=w;i++){
        mult=mult*a[i];
    }
    return mult;
}

int main(){
// 	#ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    long long test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        long long a[n],a1[n]={0},counter=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        for(int i=n-1;i>=0;i--){
            if(a[i]==1){       
                if(i!=n-1){
                    a1[i]=a1[i+1]+1;
                    // cout<<a1[i]<<"<-";
                }
                else
                    a1[n-1]=1;
            }
            // cout<<a1[i];
        }
        // cout<<endl;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                long long int s=sum(a,i,j);
                long long int m=mul(a,i,j);
                // cout<<"sum-"<<s<<" mult-"<<m<<" "<<j<<endl;
                if(m<s){
                    continue;
                }
                else if(m>s){

                    if(j!=n-1){
                        if(a[j+1]==1)
                        // if(j!=n-1)
                        continue;
                    }
                    else{
                        if(a1[j]<m-s)
                        // cout<<"------"<<a1[j]<<endl;
                            break;
                    }
                }
                else if(m==s){
                    counter++;
                }
            }
        }
    cout<<counter<<endl;
    }
    return 0;
}