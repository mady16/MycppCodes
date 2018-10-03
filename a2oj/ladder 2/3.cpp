#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<limits.h>
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
    int t;
    cin>>t;
    while(t--){
        int c,v;
        cin>>c>>v;
        int voters[v][c];
        int first[c+1];

        foreq(i,0,c){
            first[i] = 0;
        }

        foreq(i,0,v-1){
            foreq(j,0,c-1){
                cin>>voters[i][j];

            }
            first[voters[i][0]]++;
        }

        int max1 = distance(first,max_element(first,first+c+1));
        int temp1 = first[max1];
        first[max1] = INT_MIN;
        int max2 = distance(first,max_element(first,first+c+1));
        int temp2 = first[max2];
        first[max1] = temp1;

        int c1 = 0,c2 = 0;

        if( float(temp1) > float(v)/2.0){
            print(max1<<" 1");
        }else{
            foreq(i,0,v-1){
               foreq(j,0,c-1){
                   if(voters[i][j] == max1){
                       c1++;
                       break;
                   }else if(voters[i][j] == max2){
                       c2++;
                       break;
                   }
                }
            }

            if(c1 > c2){
                print(max1<<" 2");
            }else{
                print(max2<<" 2");
            }
        }



    }

    return 0;
}