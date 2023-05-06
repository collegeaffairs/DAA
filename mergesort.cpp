#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

	int count = 0;

void merge(int arr[],int k,int m,int n){
    int size = n-k+1;
    int *c = new int[size];
    int index1=k ;
    int index2 = m+1 ;
    int index3 = 0;
    while(index1 <= m && index2 <= n){
        if(arr[index1]<arr[index2]){
            c[index3] = arr[index1];
            index1++;
            count++;
        }
        else{
            c[index3] = arr[index2];
            index2++;
            count++;
        }
        index3++;
    }
    while(index1 <= m){
        c[index3++]=arr[index1++];
        
    }
    while(index2 <= n){
        c[index3++] = arr[index2++];
        
    }

    int j=k;
    for(int i =0; i<size; i++){
        arr[j++]=c[i];
    }
    delete []c;
}

void mergeSort(int arr[],int f, int l){

    if(f < l){
        int mid = (l+f)/2;
        mergeSort(arr,f,mid);
        mergeSort(arr,mid+1,l);
        merge(arr,f,mid,l);
    }
}

int main(){
//    int arr[]={2,1,6,7,4,5};
//    mergeSort(arr,0,5);
//    for(int i=0; i<6 ; i++)
//        cout << arr[i] << " ";
//        cout << endl;
//    cout << "no of compare: " << count << "\nsorted array" << endl;

     
    fstream fout;
    fout.open("mergesort.csv", ios::out | ios::app);

//	cout << "~~~~ RANDOM ARRAY ~~~~~~~" << endl;
    for(int i=0;i<100;i++){		// upto 100 run
    int *arr;
    int n = 30 + (rand()% (1000-30 + 1)); // random size b/w 30 to 1000
    arr=new int[n];
    for(int i = 0; i< n;i++){
    int rand_num = rand()%200;		//random value b/w 0 to 200
    arr[i] = rand_num; 
    }

    mergeSort(arr,0,n);
//	    for(int i=0; i<n ; i++)
//        cout << arr[i] << " ";
//        cout << endl;
//    cout << i << " "<< n << "   " << count << endl;
    fout << n << "," 
		 << count << "," 
		 <<"\n";
    count = 0;
	delete []arr;
}
	fout.close();
}
