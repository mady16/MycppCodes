#include <iostream>
using namespace std;

int top=-1;

void push(int stack[],int temp){
	stack[++top]=temp;
}

void pop(){
	top--;
}

void length(){
	cout<<"Current length of stack is :"<<top+1<<endl;
}
int main(){
	int stack[100];
	string exit;
	while(exit!="exit"){
		cout<<endl<<"Choose ur action\npop\npush\nexit\nprint\nlength:->";
		if(exit=="push"){
			cout<<"Value to Be pushed: ";
			int temp;
			cin>>temp;
			push(stack,temp);

			cout<<"Operation Succesfull"<<endl;
		}
		else if(exit=="pop"){
			pop();
		}
		else if(exit=="length"){
			length();
		}
		else{
			cout<<"Current stack is : ";
			for(int i=0;i<=top;i++)
				cout<<stack[i]<<" ";
			cout<<endl;
		}
	}

	return 0;
}