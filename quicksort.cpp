#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cmath>
using namespace std;

	int Count = 0;
		
	void swap(int& a,int& b){
    int temp = a;
    a = b;
    b = temp;
} 


// randomized quick sort

	int partition(int A[], int p, int r){
		int n = p + (rand() %(r- p + 1));
		swap(A[r], A[n]);
		int x = A[r];
		int i = p-1;
		for(int j=p; j<= r-1; j++){
			if(A[j] <= x){
				i=i+1;
				swap(A[i],A[j]);
				Count++;
			}
		}
		int temp = A[i+1];
		A[i+1]  = A[r];
		A[r] = temp;
		return i+1;
	}
	
	void quickSort(int A[], int p, int r){
		if(p<r){
		int q = partition(A, p, r);
		quickSort(A, p, q-1);
		quickSort(A, q+1, r);
	}	
	}
	
int main(){
	
	ofstream myfile;
	myfile.open("sample.txt");
	
	
// 	cout << "~~~~ RANDOM ARRAY ~~~~~~~" << endl;
    for(int i=0;i<100;i++){		// upto 100 run
    int *arr;
    int n = 30 + (rand()% (1000-30 + 1)); // random size b/w 30 to 1000
    arr=new int[n];
    for(int i = 0; i< n;i++){
    int rand_num = rand()%200;		//random value b/w 0 to 200
    arr[i] = rand_num; 
    }
    quickSort(arr, 0, n-1);
    cout << n << "    "<< Count <<endl;
    myfile << n << "    " << Count << endl;
    Count=0;
    delete []arr;
}
    
//
//	int arr[] = {2,8,7,1,3,5,6,4};
//	int n = 8;
//    quickSort(arr, 0, n-1);
//    for(int i = 0; i< n;i++){
//    	cout << arr[i] << " ";

//	}
//myfile.close("sample.txt");

	return 0;
}
