
#include<iostream>
#include<string>

using namespace std;

int main(){
    int n = 26;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    string s;
    cin>>s;
    int max = 0;
    for(int i=0;i<s.length();i++){
        if( max < a[((int)s[i] - 97)] ) max  = a[((int)s[i] - 97)];
    }

    cout<<s.length()*max<<endl;
    return 0;
}