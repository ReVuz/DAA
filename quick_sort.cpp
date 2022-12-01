#include<iostream>
using namespace std;

int partition(int A[],int lower,int upper){
    int pivot = lower;
    int i=lower;
    int j=upper;

    while(i<j){
        do{
            i++;
        }while(A[i]<=A[pivot]);
        do{
            j--;
        }while(A[j]>=A[pivot]);
        if(i<j){
            //swap
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    //swap
    int temp=A[j];
    A[j]=A[pivot];
    A[pivot]=temp;
return j+1;
}
void quicksort(int A[],int lower,int upper){
    if(lower<upper){
        int pivot = partition(A,lower,upper);
        quicksort(A,lower,pivot-1);
        quicksort(A,pivot+1,upper);
    }
}

int main(void){
    int n;
    cout<<" Enter the number of elements needed in the array : ";cin>>n;
    int* A = new int(n);
    int lower,upper;
    lower=0;upper=n;
    cout<<"Enter the initial array of numbers : ";
    for(int i=0;i<upper;i++){
        cin>>A[i];
    }
    cout<<endl;
    
    //to sort
    quicksort(A,lower+1,upper);

    cout<<"The final array of numbers : ";
    for(int i=0;i<upper;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}
