#include<iostream>
#include<cstring>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
//typedef pair<int,int> pi;
#define foreqi(i,a,b) for (int i = a; i <= b; i++)
#define sq(a) (a)*(a)


typedef struct {
    long long x;
    long long y;
    vector<long long> xpdosi;
    vector<long long> ypdosi;
} Point;


int main(){

    int n;
    cin>>n;

    Point p[n];


    foreqi(j,0,n-1){
        cin>>p[j].x>>p[j].y;
    }

    foreqi(j,0,n-1){
        foreqi(i,j+1,n-1){
            if(p[j].x == p[i].x){
                p[j].xpdosi.push_back(i);
            }
            if(p[j].y == p[i].y){
                p[j].ypdosi.push_back(i);
            }
        }
    }

    foreqi(i,0,n-1){
        foreqi(l,0,p[i].xpdosi.size()-1){
            foreqi(m,0,p[i].ypdosi.size()-1){
                int a = p[i].xpdosi[l];
                int b = p[i].ypdosi[m];

                if( (p[i].x - p[a].x) == (p[i].y - p[b].y)){
                    foreqi(j,0,n-1){

                        if( (p[a].x == p[j].x) && (p[b].y == p[j].y) ){
                            cout<<"found!\n";
                            // cout<<p[i].x + " " + p[i].y<<endl;
                            // cout<<p[p[i].xpdosi[l]].x + " " + p[p[i].xpdosi[l]].y<<endl;
                            // cout<<p[p[i].xpdosi[m]].x + " " + p[p[i].xpdosi[m]].y<<endl;
                            // cout<<p[j].x + " " + p[j].y<<endl;
                        }            
                    }        
                }
                
            }
        }       
    }

    return 0;
}