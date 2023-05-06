#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bucketsort(int *arr,int n , int k){
    int max_val=arr[0];

    for(int i=1;i<n;i++){
        max_val=max(max_val,arr[i]);
    }
    max_val++;
    vector<int> bkt[k];
    for(int i=0;i<n;i++){
        int bi=(k*arr[i])/max_val;
        bkt[bi].push_back(arr[i]);
    }
    for(int i=0;i<k;i++){
        sort(bkt[i].begin(),bkt[i].end());
    }
    int index=0;
    for(int i=0;i<k;i++){
        for(int j=0;j<bkt[i].size();j++)
          arr[index++]=bkt[i][j];
    }
}
int main(){
    int n,k;
    cout<<"Enter the size of the array to be sorted : ";
    cin>>n;
    cout<<endl;
    int *arr=new int[n];
    
    cout<<"Enter the bucket size  : ";
    cin>>k;
    cout<<endl;
    for(int i=0;i<n;i++){
      cout<<"arr["<<i<<"]";
      cin>>arr[i];
    }
    bucketsort(arr,n,k);
    cout<<"Sorted array is : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}