
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void selectionSort(int a[],int n){
    int min = 0;
    for(int i = 0; i < n; i++){
        min = i;

        for(int j=i+1;j<n;j++){
            if(a[min] > a[j]) min = j;
        }

        swap(a[min],a[i]);
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    int hash[100] = {0};

    for(int i=0;i<n;i++){
        cin>>a[i];
        hash[a[i]]++;
    }

    selectionSort(a,n);

    int max = 0;
    for(int i=0;i<n-1;i++){
        if(a[i] - a[i+1] == -1 && max < hash[a[i]] + hash[a[i+1]]){
            max = hash[a[i]] + hash[a[i+1]];
        }
    }

    for(int i=0;i<100;i++){
        if(hash[i] > max) max = hash[i];
    }

    cout<<max<<endl;

    return 0;
}