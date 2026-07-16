class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxW=0;
        for(int i=0;i<heights.size()-1;i++){
            for(int j=i+1;j<heights.size();j++){
                maxW = max(maxW, (j-i)*min(heights[i], heights[j]));
            }
        }
        return maxW;
    }
};
