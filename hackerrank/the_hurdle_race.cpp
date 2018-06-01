

#include<iostream>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    int a[n];

    int max = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(max < a[i]) max = a[i];
    }

    if(max - k <= 0) cout<<0<<endl;
    else cout<<max - k<<endl;

    return 0;
}