#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
// 	#ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int test;
    cin>>test;

    while(test--){
        int s;
        cin>>s;

        switch(s%12){
            case 0:{cout<<s-11<<" WS"<<endl;
                break;
            }
            case 1:{cout<<s+11<<" WS"<<endl;
                break;
            }
            case 2:{cout<<s+9<<" MS"<<endl;
            break;
            }
            case 3:{cout<<s+7<<" AS"<<endl;
            break;
            }
            case 4:{cout<<s+5<<" AS"<<endl;
            break;
            }
            case 5:{cout<<s+3<<" MS"<<endl;
            break;
            }
            case 6:{cout<<s+1<<" WS"<<endl;
            break;
            }
            case 7:{cout<<s-1<<" WS"<<endl;
            break;
            }
            case 8:{cout<<s-3<<" MS"<<endl;
            break;
            }
            case 9:{cout<<s-5<<" AS"<<endl;
            break;
            }
            case 10:{cout<<s-7<<" AS"<<endl;
            break;
            }
            case 11:{cout<<s-9<<" MS"<<endl;
            break;
            }
        }
    }
    return 0;
}