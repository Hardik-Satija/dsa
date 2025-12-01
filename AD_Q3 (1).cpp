#include<iostream>
using namespace std;

string sorting(string str){
    for(int i=str.length();i>0;i--){
        for(int j=0;j<i-1;j++){
            int a = str[j];
            int b = str[j+1];
            if(a>b){
                char temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }

    }

    return str;
}
bool checkanagram(string str1,string str2){
    if(str1.length()!=str2.length()){
        return false;
    }
    
    string a = sorting(str1);
    
    string b = sorting(str2);
    
    if(a==b){
        return true;
        
    }
    return false;
    
    
}
int main(){
    int n;
    string str1,str2;
    cout<<"Enter the number of tests:";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the strings of "<<i+1<<" case:";
        cin>>str1>>str2;
        cout<<endl;
        
        
        cout<<checkanagram(str1,str2)<<endl;
    }
}