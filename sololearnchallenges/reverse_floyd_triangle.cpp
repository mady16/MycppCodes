
/*
    Reverse Floyd's Triangle
    one input:
        number of rows of Triangle

*/


#include<iostream>

using namespace std;

int main(){
    
    int n;
    cin>>n;

    int size=n,current = n*(n+1)/2;
    for(int i=0;i<n;i++){
        for(int j=0;j <size;j++){
            cout<<current - j<<" ";
        }
        cout<<endl;
        current -= size;        
        size--;
    }

    return 0;
}