#include<iostream>
using namespace std;

void sorting(int *ptr,int n){
    for(int i=n;i>0;i--){
        for(int j=0;j<i;j++){
            if(ptr[j]>ptr[j+1]){
                int temp = ptr[j];
                ptr[j]=ptr[j+1];
                ptr[j+1]=temp;
            }
        }
    }
}
void linearsearch(int *arr,int n,int number){
    for(int i=0;i<n;i++){
        if(arr[i]==number){
            cout<<"Found at index "<<i<<endl;
            break;
        }
    }
    
}

int binarysearch(int *arr,int n,int number){
    int s = 1;
    int e = n;
    
    
    while (1){
        int m = (s+e)/2;
        if(arr[m]==number){
            cout<<"Found at index "<<m<<endl;
            break;
        }
        else if(arr[m]<number){
            s = m + 1;
        }
        else{
            e = m - 1;
        }
    }
}

int main(){
    int arr[20],n,t;
    cout<<"Enter the number of element in array:";
    cin>>n;
    cout<<"Enter the array:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sorting(arr,n);
    cout<<"Enter the number which you have to find:";
    cin>>t;
    linearsearch(arr,n,t);
    binarysearch(arr,n,t);
}