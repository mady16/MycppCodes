#include<iostream>
using namespace std;

int main(){

    int n,p;
    cin>>n>>p;

    if(p/2 <= (n-p)/2){
        cout<<p/2<<endl;
    }else if(n%2 == 1){
        cout<<(n-p)/2<<endl;
    }else{
        cout<<(n-p+1)/2<<endl;
    }
    

    return 0;
}