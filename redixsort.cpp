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

void redixCountSort(int arr[],int n,int digitpos){
    int sortarr[n];
    int count[10]={0};
    for(int i=0;i<n;i++){
        ++count[(arr[i]/digitpos)%10];
    }
    for(int i=0;i<10;i++){
        count[i]=count[i]+count[i-1];
    } 
    for(int i=n-1;i>=0;i--){
        int index;
        index=--count[(arr[i]/digitpos)%10];
        sortarr[index]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=sortarr[i];
    }
}

void redixSort(int arr[], int n){
    int max=getMax(arr,n);
    for(int digitpos=1;max/digitpos>0;digitpos*=10){
        redixCountSort(arr,n,digitpos);
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
    redixSort(arr,n);
    cout<<"\nElements after sorting: \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}