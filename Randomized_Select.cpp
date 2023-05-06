#include <bits/stdc++.h>

using namespace std;

int partition(int arr[], int l, int m)
{
    int pivot = arr[m];
    int i = l - 1;

    for (int j = l; j < m; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[m]);
    return i + 1;
}

int Random_partition(int arr[], int p, int q)
{

    srand(time(0));
    int random = p + rand() % (q - p);
    swap(arr[random], arr[q]);
    return partition(arr, p, q);
}

int RandomnizedSelect(int arr[] , int l , int m , int k){    

    int p , pos;

    p = Random_partition(arr , l , m);
    pos = p-l+1;

    if(pos==k){
        return arr[p];
    }
    else if(pos>k){
        return RandomnizedSelect(arr , l , p-1 , k);
    }
    else if(pos<k){
        return RandomnizedSelect(arr , p+1 , m , k-pos);
    }



}

int main()
{	
	int n, l, m, k;
	cout << "Enter size of array: ";
	cin >> n;
    int arr[n];
    cout << "Pass array input: \n";
    for(int i = 0; i<n; i++){
    	cin >> arr[i];
	}
    cout<< "l, m, k : ";
    cin >> l >> m >> k;

    cout<<RandomnizedSelect(arr , 0 , 4  , k);

}
