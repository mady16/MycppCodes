#include <iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h> 
using namespace std;

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

}


int lenNode(){

	return 0;
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
	if(temp->next==NULL)
	cout<<"There is 'NO' node which have Value: "<<value<<endl;
	else
		cout<<"Delete succed!"<<endl;
}

int main(){

	/*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif*/

//cout<<"We should start with something\n first input:";

//cin>>head->data;
int value,pos=0;

string exit;

while(exit!="exit"){
	cout<<"For exit,type 'exit'\nYou want to delete or add or print?(delete/add/print): ";
	cin>>exit;

	if(exit=="delete"){
		cout<<"Which value u want to delete: ";
		cin>>value;
		delNode(value);
	}
	else if(exit=="add"){
		cout<<"Which value u want to add: ";
		cin>>value;
		cout<<"at which position(int): ";
		cin>>pos;
		adNode(value,pos);
	}
	else
		printNode();
}    

cout<<"BaBye..!"<<endl;
    return 0;
}