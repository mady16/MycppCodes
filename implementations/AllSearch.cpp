

#include <iostream>
#include <algorithm>
using namespace std;

int BinarySearch(int binary[],int search,int low,int high){
	int mid=(low+high+1)/2;

	if(search>binary[high] || search<binary[low] || mid<0){
		return -1;
	}
	else if(search==binary[mid]){
		return mid;
	}
	else if(search<binary[mid]){
			return BinarySearch(binary,search,low,mid-1);
		}
	else if(search>binary[mid]){
			return BinarySearch(binary,search,mid+1,high);
		}
}


int interpolationSearch(int arr[], int n, int x)
{
    int lo = 0, hi = (n - 1);
 
    while (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        int pos = lo + (((double)(hi-lo) /
              (arr[hi]-arr[lo]))*(x - arr[lo]));
 
        if (arr[pos] == x)
            return pos;
 
        if (arr[pos] < x)
            lo = pos + 1;

        else
            hi = pos - 1;
    }
    return -1;
}


int main(){
	int n;
	cout<<"NO. of values u r gona Enter: ";
	cin>>n;
	int array[n];
	cout<<"Start Entering: "<<endl;
	for(int i=0;i<n;i++){
		cout<<"array["<<i<<"]: ";
		cin>>array[i];
	}

	string exit;

	while(exit!="exit"){
	int search;
	cout<<endl<<"If you don't want to Search type 'exit', otherwise type Continue hit Enter: ";
	cin>>exit;
	if(exit=="exit")
		break;
	cout<<"Which item you want to search: ";
	cin>>search;
	int position;
	position=interpolationSearch(array,n,search);
	if(position!=-1){
		cout<<"Founded succesfully, with position: "<<position+1<<endl;
	}
	else
		cout<<"Not Found"<<endl;
}

cout<<"BaaBye..!"<<endl;
	return 0;
}