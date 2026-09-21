class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            // If character appeared before
            if (mp.find(s[right]) != mp.end()) {
                left = max(left, mp[s[right]] + 1);
            }

            // Store current character's index
            mp[s[right]] = right;

            // Calculate window length
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};