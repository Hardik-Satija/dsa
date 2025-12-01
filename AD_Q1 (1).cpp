#include<iostream>
using namespace std;

void countnumber(int *prr,int n,int k){
    int count=0;
    cout<<"Pairs of array in which k is the difference:";
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(abs(prr[i]-prr[j])==k){
                cout<<"["<<prr[i]<<","<<prr[j]<<"] ";
                count++;
            }
        }
    }

    cout<<"\nTotal number of pairs in k is difference: "<<count<<endl;
}
int main(){
    int arr[20],n;
    int k;
    cout<<"Enter the number of elements in array:";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"arr["<<i<<"]:";
        cin>>arr[i];
    }
    cout<<"Enter the difference you have to find:";
    cin>>k;
    countnumber(arr,n,k);
}