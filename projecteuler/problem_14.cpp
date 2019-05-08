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


int main(){
    long highest_chain_length = 0;
    long highest_producer = 1;
    bool isChecked[1000001] = {false};
    long curr_producer;
    long curr_chain_length;

    foreq(i,1,1000000){
        curr_producer = i;
        curr_chain_length = 0;
        if(isChecked[curr_producer] == true)
            continue;
        
        isChecked[curr_producer] = true;
        while(curr_producer != 1){
            if(curr_producer%2 == 0){
                curr_producer = curr_producer/2;
            }else{
                curr_producer = curr_producer*3 + 1;
            }

            if(curr_producer < 1000001)
                isChecked[curr_producer] = true;
            curr_chain_length++;
        }
        if(curr_chain_length > highest_chain_length){
            highest_producer = i;
            highest_chain_length = curr_chain_length;
            // print("Current Highest Producer: "<<highest_producer);
        }
    }

    print("Highest Producer: "<<highest_producer);

    return 0;
}