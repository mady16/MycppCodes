#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
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

int maxSubarraySum1(vector<int> num){
    int msum = INT32_MIN, csum;
    forless(i, 0, num.size()){
        forless(j, i+1, num.size()){
            csum = 0;
            forless(k, i, j){
                csum += num[k];
            }
            msum = max(csum, msum);
        }
    }

    return msum;
}

int maxSubarraySum2(vector<int> num){
    int msum = INT32_MIN, csum = 0;
    forless(i, 0, num.size()){
        csum = 0;
        forless(j, i, num.size()){
            csum = csum + num[j];
            msum = max(csum, msum);
        }
    }

    return msum;
}

int maxSubarraySum3(vector<int> num){
    if(num.size() == 1) return num[0];

    int mid = num.size()/2;
    
    int left_sum = maxSubarraySum3(vector<int>(num.begin(), num.begin() + mid));
    int right_sum = maxSubarraySum3(vector<int>(num.begin() + mid, num.end()));

    int csum = 0, mlsum = INT16_MIN, mrsum = INT16_MIN;
    
    rforeq(i, mid-1, 0){
        csum += num[i];
        mlsum = max(csum, mlsum);
    }
    
    csum = 0;
    forless(i, mid, num.size()){
        csum += num[i];
        mrsum = max(csum, mrsum);
    }

    return max(max(left_sum, right_sum), mlsum+mrsum);
}

int maxSubarraySum4(vector<int> num){
    int msum = INT32_MIN, csum = 0;
    forless(i, 0, num.size()){
        csum = max(csum + num[i], 0);
        msum = max(csum, msum);
    }

    return msum;
}

int main(){
    vector<int> num = {-1, 2, 4, -3, 5, 2, -5, 2};
    print(maxSubarraySum3(num));
    return 0;
}