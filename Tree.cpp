#include <iostream>
#include<stdio.h>

using namespace std;
int length=0;
int height=0;

struct node{
    int data;
    int key;
    struct node *child[1000];
    struct node *parent; 
};

struct node *CreateNode(){
	node *temp=new node;
    for(int i=0;i<1000;i++)
        temp->child[i]=NULL;
	// temp->data;
	return temp;
}

struct node *root=CreateNode();

void addNode(int value){
	node *temp=CreateNode();
	temp->data=value;
	node *temp2=root;
	int height_canbe=0;
	while(1){	
		if(length==0){
			temp2=temp;
			break;
		}
		else if(temp->data>temp2->data ){
			height_canbe++;
			if(temp2->right!=NULL)
				temp2=temp2->right;
			else{
				temp2->right=temp;
				break;
			}
		}
		else if(temp->data<temp2->data){
			height_canbe++;
			if(temp2->left!=NULL)
				temp2=temp2->left;
			else{
				temp2->left=temp;
				break;
			}
		}
	}
	length++;
	if(height_canbe>height)
		height=height_canbe;
}


node *maxTree(node *root_this){
	if(root_this->right==NULL)
		return root_this;
	else
		maxTree(root_this->right);
}


void checkNode(node *temp3,node *temp4,int value){
	//------------first case no child-----------//
	if(temp4->left==NULL && temp4->right==NULL){
		if((temp3->left)->data==value)
			temp3->left=NULL;
		else
			temp3->right=NULL;
	}
	//----second case ---one child----//
	else if(temp4->left==NULL){
		if((temp3->left)->data==temp4->data){
			temp3->left=temp4->right;
		}
		else{
			temp3->right=temp4->right;
		}
	}
	else if(temp4->right==NULL){
		if((temp3->left)->data==temp4->data){
			temp3->left=temp4->left;
		}
		else{
			temp3->right=temp4->left;
		}
	}
	//--------------------third case-----two child-----------//
	else{
		node *max_left=maxTree(temp4->left);
		temp3->data=max_left->data;
		checkNode(temp4,max_left,max_left->data);
	}
}

void delNode(int value){
	node *temp2=root;
	node *temp=root;
//--------------------finding the node-----//
	int x=1;
	if(root->data==value){
		///=----------------------------edit--------------------------------------------------
		checkNode(temp,temp2,value);
		x=-1;
	}

	while(x){
		if(temp2->data<value){
			if(temp2->right!=NULL){
				temp=temp2;
				temp2=temp2->right;
				if(temp2->data==value){
					checkNode(temp,temp2,value);
					break;
				}
			}
			else
				x=0;
		}
		else if(temp2->data>value){
			if(temp2->left!=NULL){
				temp=temp2;
				temp2=temp2->left;
				if(temp2->data==value){
					checkNode(temp,temp2,value);
					break;
				}
			}
			else
				x=0;
		}
	}

	if(x==0)
		cout<<"There is no: "<<value<<endl;
	else{
		length--;
		cout<<"Deletion Successful!"<<endl;
	}

}

void printNode(){
	cout<<"height: "<<height;
	cout<<"\n\n"<<"\t\t  "<<root->data;
	node *temp=root;
	node *temp_left=root->left;
	node *temp_right=root->right;
	int t=1;
	while(t--){
		cout<<"\n\t\t"<<"/"<<" \\";
		cout<<"\n\t\t"<<temp_left->data<<" "<<temp_right->data;
		//temp_left=temp_left->left;
		//temp_right=temp_right->right;
		//cout<<"\n\t\t"<<temp_left->data<<" "<<temp_right->data;
		//temp_left=temp_right->left;
		//temp_right=temp_right->right;
		//cout<<"  "<<temp_left->data<<" "<<temp_right->data;
	}
}

void inOrder(struct node *rt)
{
    if(rt)
    {
        inOrder(rt->left);    //Go to left subtree
        cout<<rt->data<<" ";    //Printf root->data
        inOrder(rt->right);     //Go to right subtree
    }
}

void preOrder(struct node*rt)
{
    if(rt)
    {
        cout<<rt->data<<" ";     //Printf root->data
        preOrder(rt->left);    //Go to left subtree
        preOrder(rt->right);     //Go to right subtree
    }
}

void postOrder(struct node*rt)
{
    if(rt)
    {
        postOrder(rt->left);    //Go to left sub tree
        postOrder(rt->right);     //Go to right sub tree
        cout<<rt->data<<" ";    //Printf root->data
    }
}

bool searchNode(int value){
	node *temp2=root;
	while(1){
		if(temp2->data<value){
			if(temp2->right!=NULL)
				temp2=temp2->right;
			else
				break;
		}
		else if(temp2->data>value){
			if(temp2->left!=NULL)
				temp2=temp2->left;
			else
				break;
		}
		else if(temp2->data==value){
			return true;
		}
		else
			break;
	}
	return false;
}

int main(){
	int value;

string exit;

while(exit!="exit"){
	cout<<endl<<"Choose: exit\nOR\n(delete/add/printtree/printorder): ";
	cin>>exit;

	if(exit=="delete"){
		cout<<"Which value u want to delete: ";
		cin>>value;
		delNode(value);
	}
	else if(exit=="add"){
		cout<<"Which value u want to add: ";
		cin>>value;
		if(length==0){
			root->data=value;
			length++;
		}
		else 
			addNode(value);
	}
	else if(exit=="search"){
		cout<<"Which value u want to search: ";
		cin>>value;
		if(searchNode(value)){
			cout<<"Founded..!"<<endl;
		}
		else{
			cout<<"Not Found!"<<endl;
		}
	} else if(exit=="printorder"){
		string Order;
		struct node* te=root;
		cout<<"Order (inorder/preorder/postorder): ";
		cin>>Order;

		if(Order=="inorder") {
			inOrder(te);
		}
        else if(Order=="preorder") {
			preOrder(te);
		}
        else if(Order=="postorder")
				postOrder(te);

		cout<<endl;
	}
}
	cout<<endl<<"BaaBye...!"<<endl;
	return 0;
}