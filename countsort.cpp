#include<iostream>
using namespace std;

// "k" is range of number "size" is Array size
void countSort(int A[], int k,int size){
	int *C = new int[k];
	int *B;
	
	B = new int[size];
	
		for(int i=0; i < k; i++){
			C[i] = 0;
		}
		cout << size << endl;
	  
		for(int j=0; j<size; j++){
			C[A[j]] = C[A[j]] + 1;
		}
		  
    	
		for(int i=0; i<k; i++){
			if(i==0)
				C[i] = C[i];
			else
				C[i] = C[i] + C[i-1];
		}
	
	
		for(int j=0; j<size; j++){
			B[C[A[j]]-1] = A[j];
			C[A[j]] = C[A[j]] -1;
		}
	
	//copying from B to A
		for(int i=0; i<size; i++){
			A[i] = B[i];
		}
	// printing 
    for(int i = 0; i< size;i++){
    	cout << A[i] << " ";
}
	
		delete []B;
		delete []C;
	
}

int main(){
	int arr[] = {4,5,3,4,2,4,5,3,1,2};
	cout << sizeof(arr)/sizeof(arr[0]) << endl;
	int n= sizeof(arr)/sizeof(arr[0]) ;
    countSort(arr, 6,n);



	return 0;
}
