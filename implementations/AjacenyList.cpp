#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int nodes,edges;
    cin>>nodes>>edges;

    vector<int> adj[nodes+1];

    for(int i=0;i<edges;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }

    for(int i=1;i<=nodes;i++){
        cout << "Adjacency list of node " << i << ": ";
        for(int j = 0;j < adj[i].size();++j)
            {
            if(j == adj[i].size() - 1)
                    cout << adj[i][j] << endl;
            else
                cout << adj[i][j] << " --> ";
    }
    //cout<<endl;
    }
    return 0;
}