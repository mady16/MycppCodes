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

string multiply(string num1, string num2) { 
    int n1 = num1.size(); 
    int n2 = num2.size(); 
    if (n1 == 0 || n2 == 0) 
    return "0"; 
   
    vector<int> result(n1 + n2, 0); 
   
    int i_n1 = 0;  
    int i_n2 = 0;  
       
    for (int i=n1-1; i>=0; i--){ 
        int carry = 0; 
        int n1 = num1[i] - '0'; 
   
        i_n2 = 0;  
           
        for (int j=n2-1; j>=0; j--){ 
            int n2 = num2[j] - '0'; 
            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 

            carry = sum/10; 
            result[i_n1 + i_n2] = sum % 10; 
            i_n2++; 
        } 
   
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
   
        i_n1++; 
    } 
   
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--; 
   
    if (i == -1) 
        return "0"; 
   
    string s = ""; 
       
    while (i >= 0) 
        s += to_string(result[i--]); 
   
    return s; 
}

int main(){
    string ans = "1";

    foreq(i,1,1000){
        ans = multiply(ans, "2");
    }
    
    int res = 0;
    foreq(i,0,ans.length()-1){
        res = res + (int)ans[i]-48;
    }

    print("Result: "<<res);
    return 0;
}