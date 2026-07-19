class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        if(start==end && nums[start]==target) return start;
        int mid;
        while(start<end){
            if(end-start+1==2){
                if(nums[end]==target) return end;
                else if(nums[start]==target) return start;
                else break;
            }
            mid = (int) (end+start)/2;
            if(nums[mid]==target) return mid;
            if(nums[start]<nums[mid]){
                if(target<nums[mid] && target>=nums[start]) end = mid;
                else start = mid;
            }
            else if(target>nums[mid] && target<=nums[end]) start = mid;
            else end = mid;
            
        }
        return -1;
    }
};
