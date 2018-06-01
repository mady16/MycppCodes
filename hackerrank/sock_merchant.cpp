#include<iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    /* code */
    int n;
    cin>>n;

    int a[n];
    int hash[101] = {0};
    
    for(int i = 0; i < n; i++){
        cin>>a[i];
        hash[a[i]]++;
    }

    int result = 0;
    for(int i=0;i<101;i++){
        if(hash[i] != 0){
            result = result + (hash[i]/2);
        }
    }

    cout<<result<<endl;
    
    return 0;
}
