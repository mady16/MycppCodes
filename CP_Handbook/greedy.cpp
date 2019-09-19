#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

typedef long long ll;
#define foreq(i,a,b) for (int i = a; i <= b; i++)
#define forless(i,a,b) for (int i = a; i < b; i++)
#define rforeq(i,a,b) for (int i = a; i >= b; i--)
#define rforless(i,a,b) for (int i = a; i > b; i--)
#define printA(A,n) foreq(p,0,n-1){cout<<A[p]<<" ";} cout<<endl;
#define print(s) cout<<s<<endl
#define scan(s) cin>>s
#define scanA(A, n) foreq(p,0,n-1){cin>>A[p];}
#define sq(a) (a)*(a)


// ios::sync_with_stdio(0);
// cin.tie(0);

int minimumCoins(vector<int> coins, int value){
    int n = 0;
    while(value > 0){
        auto a = equal_range(coins.begin(), coins.end(), value);
        if(a.first == coins.end()){
            value = value - *(a.first-1);
        }else if(*a.first > value){
            a.first--;
            value = value - *a.first;
        }else{
            value = value - *a.first;
        }
        n++;
    }
    return n;
}


struct Node{
    int count;
    struct Node *left;
    struct Node *right;
    char chr;
};

struct NodeGreater{
    bool operator()(struct Node const *n1, struct Node const *n2){
        return n1->count >= n2->count;
    }
};

void printPaths(struct Node* node, char path[], int pathLen){  
    if (node == NULL)  
        return;
      
    if (node->left == NULL && node->right == NULL){  
        print(node->chr);
        printA(path, pathLen);
    }else{
        path[pathLen] = '0';
        pathLen++;
        printPaths(node->left, path, pathLen);  
        path[pathLen-1] = '1';
        printPaths(node->right, path, pathLen);  
    }  
}  
  
  


int main(){
    print(minimumCoins(vector<int>{1,2,5,10}, 123));

    string message = "ABCDCDABAE";
    unordered_multiset<char> counts;

    for(auto a: message){
        counts.insert(a);
    }

    priority_queue<struct Node*, vector<struct Node*>, NodeGreater > minq;

    for(auto a: counts){
        struct Node *temp = new Node;
        temp->chr = a;
        temp->count = counts.count(a);
        temp->left = NULL;
        temp->right = NULL;
        minq.push(temp);
    }

    struct Node *root = new Node;

    while(!minq.empty()){
        struct Node *n1 = minq.top();
        minq.pop();
        if(minq.empty()){
            root = n1;
            break;
        }
        struct Node *n2 = minq.top();
        minq.pop();
        struct Node *temp = new Node;
        temp->count = n1->count + n2->count;
        temp->left = n1;
        temp->right = n2;
        minq.push(temp);
    }

    char path[10] = {'_'};
    printPaths(root, path, 0);



    return 0;
}