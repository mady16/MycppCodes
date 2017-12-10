#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;

int main(){

//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    int test;
    cin>>test;

    while(test--){
        string first,second;
        cin>>first>>second;
        int pos,x=0;
        for(int i=0;i<second.length();i++){
            pos=first.find(second[i]);
            if(pos>=0){
                first.erase(first.begin()+pos);
                x++;
            }
        }
        if(x==second.length())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}