#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    
    vector<int> num={10,1,4,12,5,7,6,6,8,2};
    // cout<<num.size()<<endl;
    sort(num.begin(),num.begin()+4);
    // cout<<num<<endl;
    for(int x:num){
        cout<<x<<" ";
    }
    return 0;
}