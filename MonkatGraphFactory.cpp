#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin>>n;
    int a[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }

    int mx=*max_element(a,a+n);
    if(sum>=mx && *min_element(a,a+n)==1){
        cout<<"Yes"<<endl;
    }
    else
        cout<<"No"<<endl;
    return 0;
}