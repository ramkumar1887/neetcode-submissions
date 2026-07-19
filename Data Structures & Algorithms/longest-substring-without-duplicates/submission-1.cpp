class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result=0, max=0;
        int l=0;
        unordered_map<char, int> count;
        for(int r=0;r<s.size();r++){
            if(++count[s[r]]==2){
                while(count[s[r]]==2){
                    count[s[l]]--;
                    l++;
                }
            }
            max = max<r-l+1 ? r-l+1 : max;
        }
        return max;
    }
};
