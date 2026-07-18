class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_count, s_count, a_count;
        for (char n : t) t_count[n]++;
        int minLen = INT_MAX;
        string minString;
        int l = 0, r;

        while (l < (int)s.size() && !t_count.contains(s[l])) l++;

        for (r = l; r < (int)s.size(); r++) {
            if (!t_count.contains(s[r])) continue;
            a_count[s[r]]++;
            s_count[s[r]] = min(a_count[s[r]], t_count[s[r]]);

            while (t_count == s_count) {
                if (minLen > r - l + 1) {
                    minLen = r - l + 1;
                    minString = s.substr(l, minLen);
                }
                char c = s[l];
                int newCount = a_count[c] - 1;
                if (newCount == 0) a_count.erase(c);
                else a_count[c] = newCount;

                int capped = min(newCount, t_count[c]);
                if (capped <= 0) s_count.erase(c);
                else s_count[c] = capped;

                do { l++; } while (l < (int)s.size() && !t_count.contains(s[l]));
            }
        }
        return minLen == INT_MAX ? "" : minString;
    }
};