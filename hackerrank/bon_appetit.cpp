
#include<iostream>
using namespace std;

int main(){

    int n,k;
    cin>>n>>k;

    int a[n],total = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        total += a[i];
    }
    int bill;
    cin>>bill;

    total = total;

    if(bill == (total - a[k])/2 ){
        cout<<"Bon Appetit"<<endl;
    }else{
        cout<<bill-(total - a[k])/2<<endl;
    }


    return 0;
}