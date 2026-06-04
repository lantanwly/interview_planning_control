#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twosum(vector<int>& num,int target){
        for(int i=0;i<num.size();i++){
            for(int j=i+1;j<num.size();j++){
                if(num[i]+num[j]==target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};

int main(){
    vector<int> num={2,3,5,7};
    int target=11;
    Solution sol;
    vector<int> res=sol.twosum(num,target);
    //打印结果
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}