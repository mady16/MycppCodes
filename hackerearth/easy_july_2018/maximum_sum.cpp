#include<iostream>
#include<cstring>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
//typedef pair<int,int> pi;
#define foreqi(i,a,b) for (int i = a; i <= b; i++)
#define sq(a) (a)*(a)



int main(){

    int n;
    cin>>n;

    long long sum = 0 ,numbers = 0,k = 0,biggest = -INFINITY;

    foreqi(i,0,n-1){
        cin>>numbers;
        if(numbers >= 0){
            sum += numbers;
            k++;
        }
        if(!biggest && biggest < numbers){
            biggest = numbers;
        }
    }   

    if(k)
        cout<<sum<<" "<<k;
    else
        cout<<biggest<<" "<<1;
    return 0;
}