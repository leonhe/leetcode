#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target);
};
vector<int> Solution::twoSum(vector<int>& nums, int target){
    vector<int> result(0,0);
    for(vector<int>::size_type i=0;i<nums.size();++i)
        {
            int current_num = nums[i];
            int j=i;
            while(j--)
                {
                    int last_num = nums[j];
                    if(last_num+current_num==target){
                        result[0]=j+1;
                        result[1]=i+1;
                        break;
                    }
                }
            if(result[0]>0 && result[1]>0){
                break;
            }
        }
    return result;
}

