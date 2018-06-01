
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> a;

    int last;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        if( i == 0) {
            last = t;
            a.push_back(t);
        }else{
            if(last != t)
                a.push_back(t);            
        }

        last = t;
    }
    int k;
    cin>>k;

    int score;
    int rank = a.size()+1;

    int i = a.size() -1;
    while(k--){
        cin>>score;
        for(;i >=0;i--){
            if(a[i] <= score) rank--;
            else {
                break;
            }
        }
        cout<<rank<<endl;
    }
    
    return 0;
}