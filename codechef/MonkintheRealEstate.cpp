// #include<iostream>
// #include<algorithm>
// using namespace std;

// int main(){
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         int a[n]={0};
//         int j=0;
//         int k=2*n;
//         while(k--){
//             int x,*p;
//             cin>>x;
//             p=find(a,a+n,x);
//             if(p!=a+n){
//                 continue;
//             }
//             else{
//                 a[j]=x;
//                 j++;
//             }
//         }
//         //for(int i=0;i<n;i++)
//         //cout<<a[i]<<" ";
//         cout<<j<<endl;
//     }

//     return 0;
// }



//-------------------another code ---------------//
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
 
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T, E, X, Y;
    cin >> T;
 
    set<int> st;
    while (T--)
    {
        cin >> E;
        for (int i = 0; i < E; ++i)
        {
            cin >> X >> Y;
            st.insert(X);
            st.insert(Y);
        }
        cout << st.size() << endl;
        st.clear();
    }
}