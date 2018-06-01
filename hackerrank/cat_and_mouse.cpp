#include<iostream>


using namespace std;

int abs(int k){
    if(k > 0) return k;
    else return -k;
}

int main(){

    int q;
    cin>>q;

    while(q--){
        int a,b,m;
        cin>>a>>b>>m;
        if( abs(m-a) == abs(m-b) ){
            cout<<"Mouse C"<<endl;
        }else if( abs(m-a) < abs(m-b) ){
            cout<<"Cat A"<<endl;
        }else{
            cout<<"Cat B"<<endl;
        }
    }
    
    return 0;
}