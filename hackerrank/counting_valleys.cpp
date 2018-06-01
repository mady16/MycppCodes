
#include<iostream>

using namespace std;

int main(){
    int n ;
    cin>>n;

    string k;
    cin>>k;

    int u =0, d =0,t = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(k[i] == 'U') u++;
        else d++;

        if( u-d == 0 && k[i] == 'U' ) t++;
    }

    cout<<t<<endl;
    
    return 0;
}