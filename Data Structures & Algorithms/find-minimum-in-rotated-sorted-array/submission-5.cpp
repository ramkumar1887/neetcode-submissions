class Solution {
public:
    int findMin(vector<int> &nums) {
        int start=0,end=nums.size()-1;
        if(nums[start]<nums[end]||start==end) return nums[start];
        int mid;
        while(start<end){
            if(end-start+1==2) return nums[end];
            mid = (int) (end+start)/2;
            if(nums[mid-1]>nums[mid]){
                return nums[mid];
            }
            if(nums[mid]<nums[end]) end = mid;
            else start = mid;
        }
        return nums[start];
    }
};
