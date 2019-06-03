#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

typedef long long ll;
#define foreq(i,a,b) for (int i = a; i <= b; i++)

#define printA(A,n) foreq(p,0,n-1){cout<<p<<": "<<A[p]<<endl;}
#define print(s) cout<<s<<endl
#define scan(s) cin>>s
#define scanA(A, n) foreq(p,0,n-1){cin>>A[p];}
#define sq(a) (a)*(a)


// ios::sync_with_stdio(0);
// cin.tie(0);

char smallest_alphabet(string a) 
{ 
    // initializing smallest alphabet to 'z' 
    char min = 'z'; 
  
    // find smallest alphabet 
    for (int i=0; i<a.length(); i++)     
        if (a[i] < min) 
            min = a[i];     
  
    // returning smallest alphabet 
    return min; 
} 

int main(){
    int t;
    scan(t);

    while(t--){
        string s;
        scan(s);

        set<char> letters(s.begin(), s.end());
        if(letters.size() != s.length()){
            print("No");
        }else{
            bool alphabets[26] = {false};
            foreq(i,0,s.length()-1){
                alphabets[s[i] - 'a'] = true;
            }
            int mini = smallest_alphabet(s) - 'a';

            int index = 0;
            while(true){
                if(alphabets[mini+index] && mini+index < 26){
                    index++;
                }else{
                    break;
                }
            }

            if(index == s.length()){
                print("Yes");
            }else{
                print("No");
            }
        }
    }
    return 0;
}