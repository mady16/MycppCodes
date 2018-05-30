#include<iostream>
#include<string>
#include<climits>
#include<cmath>
using namespace std;


// 4    <-array size
// 1 2 3 4 <- array for checking pair
// 4 <- sum which want to be check
// numbers should be less than 100000


string findPair(int a[], int sum,int n){

    short int hashtable[100000] = {0};

    for(int i=0;i<n;i++){
        if(hashtable[abs(a[i])] == 0){
            if(a[i] >= 0) hashtable[abs(a[i])] = 1;
            else hashtable[abs(a[i])] = -1;
        }
        else if(hashtable[abs(a[i])] == 1 && a[i] < 0 || hashtable[abs(a[i])] == -1 && a[i] > 0)
            hashtable[abs(a[i])] = -11;
        else if(hashtable[abs(a[i])] == 1)
            hashtable[abs(a[i])] = 2;
        else
            hashtable[abs(a[i])] == -2;            
    }

    for(int i=0;i<n;i++){
        int t = (sum - a[i]);

        if(t == a[i]){
            if(hashtable[abs(t)] == 2 || hashtable[abs(t)] == -2) return "True";
            else continue;
        }

        if(hashtable[abs(t)] == -11) return "True";
        
        if(t < 0){ 
            if(hashtable[abs(t)] == -1 ) return "True";
        }else{ 
            if(hashtable[t] == 1) return "True";
        }
    }


    // only for sorted array
    // int start = 0,end = n-1,current;
    // current = a[start] + a[end];
    // while(start < end){
    //      if(current == sum) return "True";
    //     if(sum <= a[end]) {
    //         end--;
    //         current = a[start]+a[end];
    //     }
    //     if(sum > current){
    //         start++;
    //         current = a[start] + a[end];
    //     }
    // }

    return "False";
}

int main(){

    cout<<"Input array size: ";
    int n;
    cin>>n;
    int a[n];
    cout<<"Your array: ";
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int pairSum;

    while(true){
        cout<<"PairSum: ";
        cin>>pairSum;
        cout<<findPair(a , pairSum,n)<<endl;
    }
}