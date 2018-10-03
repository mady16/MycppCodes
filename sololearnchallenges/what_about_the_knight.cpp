

/*

    input specifies the location of knight:
        first should be a character between a-h
        second integer between 1-8

*/

#include<iostream>

using namespace std;

int main(){
    
    char a;
    int bj;

    int ai;
    cin>>a>>bj;

    ai = (int)a - 96;
    bj;

    if(ai > 8 || bj > 8){
        cout<<"Invalid input!!!"<<endl;
        return 0;
    }

    int total= 0;

    if( 0 < ai+2 && ai+2 < 9 && 0 < bj+1 && bj+1 < 9 ) total++;
    if(0 < ai+2 && ai+2 < 9 &&  0 < bj-1 && bj-1 < 9) total++;
    if(0 < ai-2 && ai-2 < 9 &&  0 < bj+1 && bj+1 < 9) total++;
    if(0 < ai-2 && ai-2 < 9 &&  0 < bj-1 && bj-1 < 9) total++;
    if(0 < ai + 1  && ai+1 < 9 &&  0 < bj+1 && bj+1 < 9 ) total++;
    if(0 < ai + 1  && ai+1 < 9  &&  0 < bj-1 && bj-1 < 9) total++;
    if(0 < ai - 1  && ai-1 < 9  &&  0 < bj-1 && bj-1 < 9) total++;
    if(0 < ai - 1  && ai-1 < 9  &&  0 < bj+1 && bj+1 < 9) total++;


    cout<<total<<endl;

    return 0;
}