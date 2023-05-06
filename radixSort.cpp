
#include<iostream>
using namespace std;

class radix_sort
{
  public:
    int *arr;
   int length;

    radix_sort(int l)
    {
        length=l;
    }
    ~radix_sort()
    {
        delete []arr;
    }
    void display()
    {
        for(int i=0; i<length; i++)
        {
            cout<<arr[i]<<"  ";
        }
        cout<<endl;

    }


   void input()
    {

        arr = new  int [length];
        cout<<"Enter the elements : ";
       for( int i=0; i<length; i++)
       {
         cin>>arr[i];
       }

       cout<<endl;
    }


    void RadixSort()
    {
        int large = GetMax();
        for(int place=1;large/place>0;place*=10)
        {
            CountingSort(place);
        }
    }
    int GetMax()
    {
        int Max =arr[0];
        for(int i=1;i<length;i++)
        {
            if(arr[i]>Max)
            {
                Max=arr[i];
            }

        }
        return Max;
    }

    void CountingSort(int place)
    {
        int B[length];
        int C[10]={0};        
        for(int i =0;i<length;i++)
        {
            C[(arr[i]/place)%10]++;
        }
        for(int i=1;i<10;i++)
        {
            C[i]+=C[i-1];
        }
        for(int i=length-1;i>=0;i--)
        {
            B[C[(arr[i]/place)%10]-1]=arr[i];
            C[(arr[i]/place)%10]--;
        }
        for(int i=0;i<length;i++)
        {
            arr[i]=B[i];
        }

    }

};
int main()
{
    int ch=1;
    while(ch==1){
    int n;
    cout<<"Enter Size  : ";
    cin>>n;
    radix_sort r(n);
    r.input();
	r.RadixSort();
    cout<<"************************** SORTED ARRAY******************************* "<<endl;
    r.display();
    cout<<endl<<"\nEnter 1 to continue :  ";
    cin>>ch;
    }
}



