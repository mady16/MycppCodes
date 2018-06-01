
/*

    two inputs:
        n:  fibnocci number
        m:  mth term of sequence
*/

#include<iostream>
#include<vector>
using namespace std;

void bonacciseries(long n, int m){
    // Assuming m > n.
    int a[m] = { 0 };
    a[n - 1] = 1;
    a[n] = 1;
  
    for (int i = n + 1; i < m; i++)
        a[i] = 2 * a[i - 1] - a[i - n - 1];
 
    // Printing result
    for (int i = 0; i < m; i++)
        cout << a[i] << " ";

    cout<<endl;
}
 

int main(){
    int N,M;
    cin>>N>>M;

    bonacciseries(N, M);
    return 0;
}
