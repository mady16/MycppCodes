/*

    Input the size of square: n

*/


#include<iostream>
#include<iomanip> 
using namespace std;

int main(){
    int n;
    cout<<"Input the size of square:";
    cin>>n;


    int a[n][n];

    int t =0 , b = n - 1,l = 0,r = n -1;

    int current = n*n;

    while(t <= b ){
        for(int i =l;i<=r;i++){
            a[t][i] = current;
            current--;
        }
            t++;
        
        for(int i=t;i<=b;i++){
            a[i][r] = current;
            current--;
        }
            r--;

        for(int i=r;i>=l;i--){
            a[b][i] = current;
            current--;
        }
            b--;
        for(int i=b;i>=t;i--){
            a[i][l] = current;
            current--;
        }
            l++;
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<setw(3)<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}