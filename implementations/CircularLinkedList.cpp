
/--------------------------NOT CLEARED-------------------/




#include <iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h> 

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
struct node *last=createNode();

void adNode(int value,int pos){
	struct node *temp=createNode();
	temp->data=value;

	if(!length){
		head->next=temp;
		temp->next=temp;
		last=temp;
	}
	else{
		if(pos==0){
			temp->next=head->next;
			head->next=temp;
			last->next=temp;
		}
		else if(pos==length){
			last=temp;
			temp->next=head->next;
		}
		else{
			struct node *temp2,*temp3;
			temp2=head->next;
			for(int i=0;i<pos-1;i++){
				temp2=temp2->next;
			}
			temp3=temp2->next;
			temp2->next=temp;
			temp->next=temp3;	
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
	if(head->next!=NULL){
	while((temp->next)!=last->next){
		cout<<temp->data<<", ";
		temp=temp->next;
	}
	cout<<temp->data;
	cout<<endl;
}
}

void delNode(int value){
	struct node *temp,*temp2;
	temp=head->next;
	temp2=last->next;
	if(length!=1){
	while((temp->next)!=temp2){
		if(temp->data==value){
			length--;
			if(temp->next==head->next){
				last->next=temp->next;
				head->next=temp->next;
				break;
			}
			else{
				temp2->next=temp->next;
			}
			break;
			}
			temp2=temp;
			temp=temp->next;
		}

		if(temp==last->next)
		cout<<"There is 'NO' node which have Value: "<<value<<endl;
		else
			cout<<"Delete succed!"<<endl;
	}
	else{
		head->next=NULL;
		cout<<"Delete succed!"<<endl;
	}

}

int main(){

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