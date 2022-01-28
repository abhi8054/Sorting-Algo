#include<iostream>
using namespace std;

int quickPartition(int arr[],int lb,int ub){
    int pivot=arr[lb];
    int start=lb;
    int end=ub;
    int temp;
    while(start<end){
        while (arr[start]<=pivot && start<ub)
        {
            start++;
        }
        while (arr[end]>pivot && end>lb)
        {
            end--;
        }
        if(start<end){
            int temp;
            temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
        }
    }
    temp=arr[lb];
    arr[lb]=arr[end];
    arr[end]=temp;
    return end;
}

void quickSort(int arr[],int lb,int ub){
    int loc;
    if(lb<ub){
        loc=quickPartition(arr,lb,ub);
        quickSort(arr,lb,loc-1);
        quickSort(arr,loc+1,ub); 
    }
}

int main(){
    int arr[100],n;
    cout<<"Enter the length of an array: ";
    cin>>n;
    cout<<"Enter all the array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Elements before sorting: \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    quickSort(arr,0,n-1);
    cout<<"\nElements after sorting: \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}