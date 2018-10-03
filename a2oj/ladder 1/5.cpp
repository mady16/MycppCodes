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
#define print(s) cout<<s<<endl;

#define sq(a) (a)*(a)


// ios::sync_with_stdio(0);
// cin.tie(0);


int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif
    int testcases;
    cin>>testcases;
    while(testcases--){
        int number_of_words;
        cin>>number_of_words;
        string words[number_of_words];
        string cwords[number_of_words];

        int indexofenglish = -1,allenglish = 1;
        foreq(i,0,number_of_words-1){
            cin>>words[i];
            if(words[i][0] != '#') indexofenglish = i;
            else allenglish = 0;
        }

        if(allenglish || indexofenglish == -1){
            foreq(i,0,number_of_words-1){
                cout<<words[i]<<" ";
            }
        }else{
            int k = 0;
            foreq(i,indexofenglish+1,number_of_words-1){
                cwords[k] = words[i];
                k++;
            }


            cwords[k] = words[indexofenglish];
            k++;

            // print("ASdas");
            foreq(i,0,indexofenglish-1){
                cwords[k] = words[i];
                k++;
            }

            foreq(i,0,number_of_words-1){
                cout<<cwords[i]<<" ";
            }
  

        }



        
        cout<<"\n";
    }

    return 0;
}