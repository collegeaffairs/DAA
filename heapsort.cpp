
#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

int count = 0;

void swap(int& a,int& b){
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int arr[],int i,int n){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i +2;
    if(left < n &&  arr[left]>arr[largest]){
    	largest = left;
    	count++;
	}
    else
    	largest = i;
    	count++;
    if(right < n && arr[right]>arr[largest]){
        largest = right; 
        count++;
    }
    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr,largest,n);
    }  
}

void buildHeap(int arr[],int n){
    for(int i= n/2 -1;i>=0;i--){
        heapify(arr,i,n);
    }
}

void heapSort(int arr[],int n){
    buildHeap(arr,n);
     for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,0,i);
    }
    
}

void printArray(int arr[],int n){
    for ( int i = 0; i<n;i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
//     int n ;
//     cout << "enter size of your array: " ;
//    cin >> n;
//    int arr[n];
//    cout << "Enter unsorted array: " << endl;
//
//    for (int i =0; i < n; i++){
//        cout << "Element no. " << i << " : ";
//        cin >> arr[i];
//}
//
//    cout << "your array: " ;
//    printArray(arr,n);
//    heapSort(arr,n);
//    printArray(arr,n);
	
	fstream fout;
	fout.open("heapsort.csv", ios::out | ios::app);
	
//	cout << "~~~~ RANDOM ARRAY ~~~~~~~" << endl;
    for(int i=0;i<100;i++){		// upto 100 run
    int *arr;
    int n = 30 + (rand()% (1000-30 + 1)); // random size b/w 30 to 1000
    arr=new int[n];
    for(int i = 0; i< n;i++){
    int rand_num = rand()%200;		//random value b/w 0 to 200
    arr[i] = rand_num; 
    }
    
    heapSort(arr,n);
//	cout << i << " "<< n << "   " << count << endl;
     fout << n << "," 
		 << count << "," 
		 <<"\n";
    count = 0;
	delete []arr;
}	
	fout.close();
	cout << "heapsort.csv file successfully generated." << endl;
}
