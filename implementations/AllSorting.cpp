//Written by Mental

#include <iostream>
#include <math.h>

using namespace std;

void Bubble_Sort(int sort[],int n){
	while(n--){
		for(int i=0;i<=n-1;i++){
			if(sort[i]>sort[i+1]){
				int temp=sort[i];
				sort[i]=sort[i+1];
				sort[i+1]=temp;
			}
		}
	}
}

void Selection_Sort(int sort[],int n){
	int z=0;
	while(z<n){
		for(int i=0;i<n;i++){
			if(sort[z]<sort[i]){
				int temp=sort[z];
				sort[z]=sort[i];
				sort[i]=temp;
			}
		}
		z++;
	}

}

void Merge_Sort(int sort[],int n){
	int x=1;
	while((int)pow(2.0,x)<=n){
			int temp_array[(int)pow(2.0,x)]={0};
			for(int i=0;i<n;i+=pow(2.0,x)){
				int temp_i=0;

				for(int j=i,k=i;temp_i<pow(2.0,x);){
					if(j==pow(2.0,x-1)+i){
						while(temp_i<pow(2.0,x)){
							temp_array[temp_i]=sort[k+(int)pow(2.0,x-1)];
							k++;
							temp_i++;
						}
					}
					else if(k==pow(2.0,x-1)+i){
						while(temp_i<pow(2.0,x)){
							temp_array[temp_i]=sort[j];
							j++;
							temp_i++;

						}
					}
					else if(sort[j]>=sort[k+(int)pow(2.0,x-1)]){
						temp_array[temp_i]=sort[k+(int)pow(2.0,x-1)];
						k++;temp_i++;	
					}
					else if(sort[j]<sort[k+(int)pow(2.0,x-1)]){
						temp_array[temp_i]=sort[j];
						j++;temp_i++;
					}
				}

				int temp_2=0;
				for (temp_i = i; temp_i-i < pow(2.0,x); temp_i++)
				{
					sort[temp_i]=temp_array[temp_2];
					temp_2++;
				}
		}
		x++;
	}
}


void Insertion_Sort(int sort[],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(sort[i]<sort[j]){
				int temp=sort[i];
				sort[i]=sort[j];
				sort[j]=temp;
				break;
			}
		}
	}
}

int partition ( int A[],int start ,int end) {
    int i = start + 1;
    int piv = A[start] ;            //make the first element as pivot element.
    for(int j =start + 1; j <= end ; j++ )  {
    /*rearrange the array by putting elements which are less than pivot
       on one side and which are greater that on other. */

          if ( A[ j ] < piv) {
                 swap (A[ i ],A [ j ]);
            i += 1;
        }
   }
   swap ( A[ start ] ,A[ i-1 ] ) ;  //put the pivot element in its proper place.
   return i-1;                      //return the position of the pivot
}

void Quick_sort ( int A[ ] ,int start , int end ) {
   if( start < end ) {
        //stores the position of pivot element
         int piv_pos = partition (A,start , end ) ;     
         Quick_sort (A,start , piv_pos -1);    //sorts the left side of pivot.
         Quick_sort ( A,piv_pos +1 , end) ; //sorts the right side of pivot.
   }
}

int main(){
		int n;
	cout<<"NO. of values u r gona Enter for Sorting: ";
	cin>>n;
	int sort[n];
	cout<<"Start Entering: "<<endl;
	for(int i=0;i<n;i++){
		cout<<"To_sort_array["<<i<<"]: ";
		cin>>sort[i];
	}

	string exit;

	cout<<endl<<":-)Choose: \nBubble sort\nSelection sort\nInsertion sort\nMerge sort\nQuick Sort\nYour Choice: ";
	cin>>exit;
	if(exit=="bubble"){
		Bubble_Sort(sort,n);
	}
	else if(exit=="selection"){
		Selection_Sort(sort,n);
	}
	else if(exit=="merge"){
		Merge_Sort(sort,n);
	}
	else if(exit=="insertion"){
		Insertion_Sort(sort,n);
	}
	else if(exit=="quick"){
		Quick_sort(sort,0,n);
	}
	else{
		cout<<"\'First learn typing\""<<endl;
		return 0;
	}
	cout<<"Sorting Completed!"<<endl;
	cout<<"Your Sorted array: ";
	for(int i=0;i<n;i++)
		cout<<sort[i]<<" ";
	cout<<endl;
	cout<<"BaaBye..!"<<endl;
	return 0;
}