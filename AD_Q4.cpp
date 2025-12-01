#include<iostream>
using namespace std;

void sort012(int *ptr,int n){
    int count0=0,count1=0,count2=0;
    for(int i=0;i<n;i++){
        if(ptr[i]==0){
            count0+=1;
        }
        else if(ptr[i]==1){
            count1+=1;
        }
        else{
            count2+=1;
        }
    }
    int index=0;

    for(int i=0;i<count0;i++){
        ptr[index++]=0;
    }
    for(int i=0;i<count1;i++){
        ptr[index++]=1;
    }
    for(int i=0;i<count2;i++){
        ptr[index++]=2;
    }
}

int main(){
    int arr[20],n;
    cout<<"Enter the number of elements in array:";
    cin>>n;
    cout<<"Enter the array:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort012(arr,n);
    cout<<"[";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
}