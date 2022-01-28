#include<iostream>
using namespace std;
int getMax(int arr[] ,int n){
    int max;
    max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
void countSort(int arr[], int n){
    int sortarr[n];
    int key;
    
    key=getMax(arr,n);
    int count[key+1]={0};

    for(int i=0;i<n;i++){
        ++count[arr[i]];
    }
    
    for(int i=1;i<=key;i++){
        count[i]=count[i]+count[i-1];
    }

    for (int i=n-1;i>=0;i--){
        int index;
        index=--count[arr[i]];
        sortarr[index]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=sortarr[i];
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
    countSort(arr,n);
    cout<<"\nElements after sorting: \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}