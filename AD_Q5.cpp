#include<iostream>
using namespace std;

void duplicate_0s(int *ptr,int n){
    int i=0;
    while(i<n){
        if(ptr[i]==0){
            for(int j=n-1;j>i+1;j--){
                ptr[j]=ptr[j-1];
            }
            ptr[i+1]=0;
            i++;
        }
        i++;
    }
}

int main(){
    int arr[20],t,n;
    cout<<"Enter the number of test:";
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<"Enter the number of terms in "<<i+1<<" array:";
        cin>>n;
        cout<<"Enter the "<<i+1<<" array: [";
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        cout<<"]"<<endl;
        duplicate_0s(arr,n);
        cout<<"Updated Array: [";
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"]"<<endl;
    }
    
}