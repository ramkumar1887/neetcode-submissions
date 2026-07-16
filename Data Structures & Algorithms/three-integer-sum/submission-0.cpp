class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int temp;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size()-i-1;j++){
                if(nums[j]>nums[j+1]){
                    temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
            }
        }
        set<vector<int>> r1;
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                for(int k=j+1;k<nums.size();k++){
                    if(0==nums[i]+nums[j]+nums[k])
                    r1.insert({nums[i],nums[j],nums[k]});
                }
            }
        }
        vector<vector<int>> result(r1.begin(),r1.end());
        return result;
    }
};
