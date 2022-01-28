#include<iostream>
using namespace std;
void selectionSort(int arr[],int n){
    int min,temp;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
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
    selectionSort(arr,n);
    cout<<"\nElements after sorting: \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}