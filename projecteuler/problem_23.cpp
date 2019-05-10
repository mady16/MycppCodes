#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
#define foreq(i,a,b) for (int i = a; i <= b; i++)

#define swap(A,swapi,swapj) {A[swapi] = A[swapi] + A[swapj]; A[swapj] = A[swapi]-A[swapj]; A[swapi] = A[swapi]-A[swapj];}

#define printA(A,n) foreq(p,0,n-1){cout<<p<<": "<<A[p]<<endl;}
#define print(s) cout<<s<<endl

#define sq(a) (a)*(a)


// ios::sync_with_stdio(0);
// cin.tie(0);

long sumOfDivisors(long num){
    long sum = 0;
    foreq(i,1,num/2){
        if(num%i == 0){
            sum += i;
        }
    }
    return sum;
}

bool isAbundant(long num){
    return sumOfDivisors(num) > num;
}

int main(){
    bool abundants[28124] = {false};

    foreq(i,12,28123){
        if(isAbundant(i)){
            abundants[i] = true;
        }
    }


    long sum = 0;
    foreq(i,1,28123){
        foreq(j,12,28123){
            if(j >= i){
                sum += i;
                break;
            }else if(abundants[i-j] && abundants[j]){
                break;               
            }
        }
    }

    print(sum);
    
    return 0;
}