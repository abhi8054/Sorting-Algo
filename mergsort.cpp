#include<iostream>
using namespace std;

void mergPartition(int arr[],int lb,int mid,int ub){
    int sortarr[100];
    int i,j,k;
    i=lb;
    j=mid+1;
    k=lb;  
    while(i<=mid && j<=ub){
        if(arr[i]<arr[j]){
            sortarr[k]=arr[i];
            i++;
        }else{
            sortarr[k]=arr[j];
            j++;
        }
        k++;
    }

    if(i>mid){
        while(j<=ub){
            sortarr[k]=arr[j];
            j++;
            k++;
        }
    }else{
        while(i<=mid){
            sortarr[k]=arr[i];
            i++;
            k++;
        }        
    }
    for (int p = lb; p <= ub; p++){
        arr[p]=sortarr[p]; 
    }
    
}

void mergSort(int arr[],int lb,int ub){
    if(lb<ub){
        int mid;
        mid=(lb+ub)/2;
        mergSort(arr,lb,mid);
        mergSort(arr,mid+1,ub);
        mergPartition(arr,lb,mid,ub);
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
    mergSort(arr,0,n-1);
    cout<<"\nElements after sorting: \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}