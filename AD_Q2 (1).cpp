#include<iostream>
using namespace std;

bool issubstring(string str1,string str2){
    if(str1.length()>str2.length()){
        return false;
    }
    for(int i=0;i<=(str2.length() - str1.length());i++){
        for(int j=0;j<str1.length();j++){
            if(str2[i+j]==str1[j]){
                return true;
                break;
            }
            else{
                return false;
            }
        }
    }
}
bool checkpossible(string str){
    int n = str.length();

    for(int i=1;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            string str_part1 = str.substr(0,i);
            string str_part2 = str.substr(i,j-i);
            string str_part3 = str.substr(j);

            if(issubstring(str_part1,str_part2) && issubstring(str_part1,str_part3)){
                cout<<"After spliting: "<<str_part1<<" "<<str_part2<<" "<<str_part3<<endl;
                return true;
            }
            if(issubstring(str_part2,str_part1) && issubstring(str_part2,str_part3)){
                cout<<"After spliting: "<<str_part1<<" "<<str_part2<<" "<<str_part3<<endl;
                return true;
            }
            if(issubstring(str_part3,str_part1) && issubstring(str_part3,str_part2)){
                cout<<"After spliting: "<<str_part1<<" "<<str_part2<<" "<<str_part3<<endl;
                return true;
            }
        }
    }
    return false;

    
}
int main(){
    int n;
    cout<<"Enter the number of strings:";
    cin>>n;
    string str;
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<" string:";
        cin>>str;
        if(checkpossible(str)){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}