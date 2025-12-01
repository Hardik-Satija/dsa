#include<iostream>
using namespace std;
void sorting(int *ptr,int n){
    for(int i=n;i>=0;i--){
        for(int j=0;j<i;j++){
            if(ptr[j]>ptr[j+1]){
                int temp = ptr[j];
                ptr[j] = ptr[j+1];
                ptr[j+1] = temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<"arr["<<i<<"]:"<<ptr[i]<<endl;
    }
}
int main(){
    int arr[100],n;
    cout<<"Enter the number of Elements:"<<endl;
    cin>>n;
    cout<<"Enter the elements in an array:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sorting(arr,n);
}