class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    unordered_map<int,int> len; // key: number, value: length of streak this number is an endpoint of
    int maxLen = 0;

    for (int n : nums) {
        if (len.count(n)) continue; // duplicate, skip

        int leftLen  = len.count(n - 1) ? len[n - 1] : 0;
        int rightLen = len.count(n + 1) ? len[n + 1] : 0;
        int curLen = leftLen + rightLen + 1;

        len[n] = curLen;
        len[n - leftLen]  = curLen; // update far-left endpoint
        len[n + rightLen] = curLen; // update far-right endpoint

        maxLen = max(maxLen, curLen);
    }
    return maxLen;
}
};
