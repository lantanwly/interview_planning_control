#include<string>
#include<iostream>
using namespace std;
int main(){
    // cout<<int("}"-"{")<<endl;
    // cout<<int(")"-"(")<<endl;
    // cout<<int("]"-"[")<<endl;
    string s="()";
    cout<<boolalpha;
    int i=0;
    int j=s.size()-1;
    // cout<<s.size()-1<<endl;
    // cout<<s[0]<<endl;
    // cout<<s[j]<<endl;
    
    cout<<int(s[j]-s[i])<<endl;
    if(int(s[j]-s[i])!=2&&int(s[j]-s[i])!=1){
                cout<<false<<endl;
            }
            else{
                cout<<true<<endl;
            }
    return 0;
}