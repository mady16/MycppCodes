#include <iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h> 

using namespace std;

int length=0;

struct node{
	int data;
	struct node *next;
	struct node *prev;
};


struct node *createNode(){
    node *temp=new node; 
    temp->next = NULL;
    temp->prev=NULL;
    return temp;
}

struct node *head=createNode();
struct node *tail=createNode();

void adNode(int value,int pos){
	struct node *temp=createNode();
	
	if(pos==0){
		temp->prev=head;
		temp->next=head->next;
		head->next=temp;
		temp->data=value;
		/*
		temp->next=head->next;
		(head->next)->prev=temp;
		head->next=temp;
		temp->prev=head;*/
	}
	else if(pos==length){
		temp->next=tail;
		temp->prev=tail->prev;
		tail->prev=temp;
		temp->data=value;
		/*
		(tail->prev)->next=temp;
		temp->prev=tail->prev;
		temp->next=tail;
		tail->prev=temp;*/
	}
	else{
		struct node *temp2;

		temp2=((length-pos)<=length/2)? head : tail;
		if(temp2==head){
			for(int i=0;i<pos;i++){
				temp2=temp2->next;
			}
			temp->next=temp2->next;
			(temp2->next)->prev=temp;
			temp->prev=temp2;
			temp2->next=temp;
			temp->data=value;
		}
		else{
			for(int i=length;i>=pos;i--){
				temp2=temp2->prev;
			}
			temp->next=temp2->next;
			(temp2->next)->prev=temp;
			temp->prev=temp2;
			temp2->next=temp;
			temp->data=value;
		}
	}
	length++;
}


void lenNode(){
	cout<<"Length: "<<length<<endl;
	//return 0;
}

void printNode(){
	struct node *temp;
	temp=head->next;
	cout<<"Current list is: ";
	while((temp->next)!=NULL){
		cout<<temp->data<<", ";
		temp=temp->next;
	}
	cout<<endl;
}

void delNode(int value){
	struct node *temp,*temp2;
	temp=head;
	while((temp->next)!=NULL){
		if(temp->data==value){
			temp2->next=temp->next;
			(temp->next)->prev=temp2;
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
	//In starting only head and tail should point to each other
head->next=tail;
tail->prev=head;

int value,pos=0;

string exit;

while(exit!="exit"){
	cout<<endl;
	cout<<"For exit,type 'exit'\nFor length, type 'length'\nSimilarly, You want to delete or add or print?(delete/add/print): ";
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
	else if(exit=="length"){
		lenNode();
	}
	else 
		printNode();
	
}    

cout<<"BaBye..!"<<endl;
    return 0;
}