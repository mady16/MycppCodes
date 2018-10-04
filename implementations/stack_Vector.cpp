#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> v;
	string s;

	while(s!="exit"){
		cout<<"\nchoose\npop\npush\nlength\nprint\n exit\n --: ";
		cin>>s;
	if(s=="push"){
		cout<<"value u want to put : ";
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	else if(s=="pop"){
		v.pop_back();
		cout<<"Element has been poped."<<endl;
	}
	else if(s=="length"){
		cout<<"length :"<<v.size()<<endl;
	}
	else{
		cout<<"Current stack is: ";
		for(int i=0;i<v.size();i++)
			cout<<v[i]<<" ";
			cout<<endl;
		}
}


	cout<<"BaaBye...!"<<endl;
	return 0;
}