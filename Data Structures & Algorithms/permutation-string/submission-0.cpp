class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1_count;
        unordered_map<char, int> s2_count;
        for(char n: s1) s1_count[n]++;
        for(int i=0;i<s1.size();i++) s2_count[s2[i]]++;
        if(s1_count==s2_count) return true;
        for(int i=s1.size();i<s2.size();i++){
            s2_count[s2[i]]++;
            s2_count[s2[i-s1.size()]]--;
            if(s2_count[s2[i-s1.size()]]==0) s2_count.erase(s2[i-s1.size()]);
            if(s1_count==s2_count) return true;
        }
        return false;
    }
};
