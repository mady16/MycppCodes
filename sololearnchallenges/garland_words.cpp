
/*
    Programme will tel u the garland degree of string.
    input :
        a string

*/


#include<iostream>
#include<string>
#include<ctime>
using namespace std;

int main(){
  clock_t begin = clock();
   
    string n;

    cin>>n;

    int maxDeg = 0;

    for(int i=0;i<n.length()-1;i++){
        int current = maxDeg;
        for(int j=i;j>=maxDeg;j--){
            if(n[j] == n[n.length()-1 - (i - j)]) current++;
            else break;
        }
        if(maxDeg < current) maxDeg = current;
    }


    cout<< maxDeg <<endl;
    
    
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout<<elapsed_secs<<"s"<<endl;
    return 0;
}