#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    string s;
    cin>>s;
    long long int n,k;
    cin>>k;
    for(int i=0;i<s.length();i++){
        if((s[i]>=65 && s[i]<=90)) {
            n=k%26;
                s[i] = (s[i] + n)%90;
            if(s[i]==0)
                s[i]=s[i]+90;
            if(s[i]<65)
                s[i]=s[i]+64;
        }
        else if((s[i]>=97 && s[i]<=122)) {
            n=k%26;
            s[i] = (s[i] + n)%122;
            if(s[i]==0)
                s[i]=s[i]+122;
            if(s[i]<97)
                s[i]=s[i]+96;
        }
        else if((s[i]>=48 && s[i]<=57)) {
            n=k%10;
            s[i] = (s[i] + n)%57;
            if(s[i]==0)
                s[i]=s[i]+57;
            if(s[i]<48)
                s[i]=s[i]+47;
        }
    }

    cout<<s;
    return 0;
}
