#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    long long int n;
    cin>>n;
    long long int sum[n];
    for (int j = 0; j <n ; ++j) {
        string s;
        cin>>s;
        sum[j]=s[0]-48;
        for(long long int i=2;i<s.length();i+=2) {
            if (s[i - 1] == '+') {
                sum[j] = sum[j] + (int) s[i]-48;
            } else if (s[i - 1] == '-') {
                sum[j] = sum[j] - (int) s[i]+48;
            }
        }
    }
    cout<<*max_element(sum,sum+n);
    return 0;
}
