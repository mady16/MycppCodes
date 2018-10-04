#include <iostream>
#include <deque>

using namespace std;

int main(){
	deque<int> Queue;
	string s;

	while(s!="exit"){
		cout<<"\nchoose\ndequeue\nenqueue\nlength\nprint\n exit\n --: ";
		cin>>s;
	if(s=="enqueue"){
		cout<<"value u want to put : ";
		int temp;
		cin>>temp;
		Queue.push_back(temp);
	}
	else if(s=="dequeue"){
		Queue.pop_front();
		cout<<"Element has been dequeued."<<endl;
	}
	else if(s=="length"){
		cout<<"length :"<<Queue.size()<<endl;
	}
	else{
		cout<<"Current stack is: ";
		for(int i=0;i<Queue.size();i++)
			cout<<Queue[i]<<" ";
			cout<<endl;
		}
}


	cout<<"BaaBye...!"<<endl;
	return 0;
}