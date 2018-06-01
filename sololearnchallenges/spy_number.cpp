/*
        Print spy numbers in a range [a,b)
        two inputs-->
        first(a): starting number.
        second(b): last number.


*/



#include<iostream>

using namespace std;

int main(){
    
    cout<<"Print Spy numbers from, \n Start: ";

    int n,m;
    cin>>n;
    
    cout<<"to : ";
    cin>>m;

    for(int i=n;i<m;i++){
        int sum = 0,mutiply = 1,num = i;
        while(num%10 != 0 || num/10 != 0){
            int t = num%10;
            sum += t;
            mutiply *= t;
            num /= 10;
        }
        if(sum == mutiply){
            cout<<i<<endl;
        }
    }

    return 0;
}