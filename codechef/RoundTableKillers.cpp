#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

int length=0;
struct node{
	int data;
	struct node *next;
};

struct node *createNode(){
    node *temp=new node; 
    temp->next = NULL;
    return temp;
}

struct node *head=createNode();

void adNode(int value,int pos){
	struct node *temp=createNode();
	temp->data=value;

	if(pos==0){
		temp->next=head->next;
		head->next=temp;
	}
	else{
		
		struct node *temp2,*temp3;
		temp2=head;
		for(int i=0;i<pos;i++){
			temp2=temp2->next;
			//temp=temp->next;
		}
		temp3=temp2->next;
		temp2->next=temp;
		temp->next=temp3;
    }
    length++;
}

void delNode(int value){
	struct node *temp,*temp2;
	temp=head;
	while((temp->next)!=NULL){
		if(temp->data==value){
			temp2->next=temp->next;
			break;
		}
		temp2=temp;
		temp=temp->next;
    }
    length--;
    // if(temp->next==NULL){
    //      length++;
    //      delNode(value+1);
    //  }
    cout<<temp->data<<" "<<length<<endl;    
    
}

void printNode(){
	struct node *temp;
	temp=head->next;
	cout<<"Current list is: ";
	while((temp->next)!=NULL){
		cout<<temp->data<<", ";
		temp=temp->next;
	}
	cout<<temp->data;
	cout<<endl;
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,k,x;
    cin>>n>>k>>x;
    for(int i=0;i<n;i++){
        adNode(i+1,i);
    }
    int dl[n],j=0;
    while(1){
    if(length<=x%k){
        break;
        int i=0;
    }
    if(x>=n){
        x=x%n;
    }
    int i=1;
    for(;i<=x%k;i++){
       
        while(1){
        if(find(dl,dl+n,x+i)!=dl+n)
            x++;
        else
            break;
        }
        delNode(i+x);
        dl[j]=i+x;
        j++;
    }
    x=x+i;
}
    cout<<x<<endl;
    return 0;
}