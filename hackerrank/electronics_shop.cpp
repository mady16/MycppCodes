
#include<iostream>

using namespace std;

int main(){
    int b,n,m;
    cin>>b>>n>>m;

    int a[n];
    int c[m];

    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    for(int i = 0; i < m; i++){
        cin>>c[i];
    }

    int max = -1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i] + c[j] > max && a[i] + c[j] <= b ) max = a[i] + c[j];
        }
    }

    cout<<max<<endl;

    
    return 0;
}