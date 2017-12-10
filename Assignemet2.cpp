#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

string k[1000];
void heapify(int freq[], int n, int i)
{
    int t=0;
    string q;
    int max = i;  
    int l = 2*i + 1;  
    int r = 2*i + 2;  

    if (l < n && freq[l] > freq[max])
        max = l;

    if (r < n && freq[r] > freq[max])
        max = r;

    if (max != i)
    {
        t=freq[i];
        q=k[i];	

        freq[i]=freq[max];
        k[i]=k[max];
        freq[max]=t;
        k[max]=q;

        heapify(freq, n, max);
    }
}

// main function to sort
void mySort(int freq[])
{
    int t=0;
    string l;

    for (int i = 499; i >= 0; i--){
        heapify(freq, 499, i);

    }

    for (int i=999; i>=0; i--)
    {
        t=freq[0];
        l=k[0];
        freq[0]=freq[i];
        k[0]=k[i];
        freq[i]=t;
        k[i]=l;

        heapify(freq, i, 0);
    }
}


int forHashing(string s){
	int index=0;

	for (int i = 0; i <s.length() ; i++)
	{
		if(int(s[i])<91 && int(s[i])>64)
			s[i]=s[i]+32;
		
		index=index+(i+1)*int(s[i]);

	}
	index=index%499;
	return index;
}


int main(){


string s[100]={};
int freq[1000]={0},th;
cout<<"Enter the threshold:";
cin>>th;

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

for (int i = 0; i < 100; i++){
	cin>>s[i];
	int u=s[i].length();
	if(s[i][u-1]==',' || s[i][u-1]=='.' || s[i][u-1]=='"' || s[i][u-1]=='?'|| s[i][u-1]==';' || s[i][u-1]=='/')
	{
		s[i]=s[i].substr(0,u-1);
	}
	else if(s[i][0]=='"'){
		s[i]=s[i].substr(1,u-1);
	}
	if(s[i]!=""){
	freq[forHashing(s[i])]++;
	k[forHashing(s[i])]=s[i];
}
}

mySort(freq);

for (int i = 999; i>=0; i--){
	if(freq[i]>=th)
	cout<<k[i]<<":"<<freq[i]<<endl;
}



    return 0;
}