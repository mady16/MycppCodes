#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

string strprint[1000];
void heapify(int frequency_count[], int n, int j)
{
    int t=0;
    string q;
    int max = j;  
    int l = 2*j + 1;  
    int r = 2*j + 2;  

    if (l < n && frequency_count[l] > frequency_count[max])
        max = l;

    if (r < n && frequency_count[r] > frequency_count[max])
        max = r;

    if (max != j)
    {
        t=frequency_count[j];
        q=strprint[j];	

        frequency_count[j]=frequency_count[max];
        strprint[j]=strprint[max];
        frequency_count[max]=t;
        strprint[max]=q;

        heapify(frequency_count, n, max);
    }
}

// main function to sort
void mySort(int frequency_count[])
{
    int t=0;
    string l;

    for (int j = 499; j >= 0; j--){
        heapify(frequency_count, 499, j);

    }

    for (int j=999; j>=0; j--)
    {
        t=frequency_count[0];
        l=strprint[0];
        frequency_count[0]=frequency_count[j];
        strprint[0]=strprint[j];
        frequency_count[j]=t;
        strprint[j]=l;

        heapify(frequency_count, j, 0);
    }
}


int forHashing(string s){
	int index=0;

	for (int j = 0; j <s.length() ; j++)
	{
		if(int(s[j])<91 && int(s[j])>64)
			s[j]=s[j]+32;
		
		index=index+(j+1)*int(s[j]);

	}
	index=index%499;
	return index;
}


int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w",stdout);
#endif


string s[1000]={};
int frequency_count[1000]={0},th;

cin>>th;


for (int j = 0; j < 1000; j++){
	cin>>s[j];
	int u=s[j].length();
	if(s[j][u-1]==',' || s[j][u-1]=='.' || s[j][u-1]=='!' || s[j][u-1]=='?'|| s[j][u-1]==';' || s[j][u-1]=='/')
	{
		s[j]=s[j].substr(0,u-1);
	}
	else if(s[j][0]=='"'){
		s[j]=s[j].substr(1,u-1);
	}
	if(s[j]!=""){
	frequency_count[forHashing(s[j])]++;
	strprint[forHashing(s[j])]=s[j];
}
}

mySort(frequency_count);

for (int j = 999; j>=0; j--){
	if(frequency_count[j]>=th)
	cout<<strprint[j]<<":"<<frequency_count[j]<<endl;
}



    return 0;
}
