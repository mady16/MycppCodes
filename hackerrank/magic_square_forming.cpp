
#include<iostream>

using namespace std;

int abs(int k){
    if(k > 0) return k;
    else return -k;
}

int main(){
    int a[3][3];

    int sol[][3][3] = {

            {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
            {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
            {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
            {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}}, 
            {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
            {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}}, 
            {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}}, 
            {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}},
    };

    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
        cin>>a[i][j];
    
    int current = 0,min = 100;

    for(int i=0;i<8;i++){
        current = 0;
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                current += abs(sol[i][j][k] - a[j][k]);
            }
        }
        if(current < min) min = current;
    }


    cout<<min<<endl;

    
    return 0;
}