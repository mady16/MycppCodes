#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
#define foreqInc(i,a,b) for (int i = a; i <= b; i++)
#define foreqDec(i,a,b) for (int i = a; i >= b; i--)

#define swap(A,swapi,swapj) {A[swapi] = A[swapi] + A[swapj]; A[swapj] = A[swapi]-A[swapj]; A[swapi] = A[swapi]-A[swapj];}

#define printA(A,n) foreq(p,0,n-1){cout<<p<<": "<<A[p]<<endl;}
#define print(s) cout<<s<<endl

#define sq(a) (a)*(a)


// ios::sync_with_stdio(0);
// cin.tie(0);

int main(){
    int grid_size = 20;
    long grid[grid_size+1][grid_size+1] = {0};

    foreqInc(i,0,grid_size-1){
        grid[i][grid_size] = 1;
        grid[grid_size][i] = 1;
    }

    foreqDec(i,grid_size-1, 0){
        foreqDec(j,grid_size-1,0){
            grid[i][j] = grid[i+1][j] + grid[i][j+1];
        }
    }

    print("Number of routes: "<<grid[0][0]);
    return 0;
}