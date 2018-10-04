#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio (false);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int nodes,edges;
    cin>>nodes>>edges;

    bool A[nodes+1][nodes+1];
    for(int i = 0;i <= nodes;++i)
    for(int j = 0;j <= nodes;++j)
        A[i][j] = false;

    for(int i=0;i<edges;i++){
        int x,y;
        cin>>x>>y;
        A[x][y]=true;
    }

    for(int i=1;i<=nodes;i++){
        for(int j=1;j<=nodes;j++)
        cout<<(int)A[i][j]<<" ";
    cout<<endl;
    }
    return 0;
}