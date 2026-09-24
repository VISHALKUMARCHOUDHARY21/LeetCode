class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        int m = s1.size();

        if (m > n) {
            return false;
        }

        unordered_map<char, int> need;
        unordered_map<char, int> windowMap;

        // Frequency of characters in s1
        for (int i = 0; i < m; i++) {
            need[s1[i]]++;
        }

        // First window
        int low = 0;
        int high = m - 1;

        for (int i = low; i <= high; i++) {
            windowMap[s2[i]]++;
        }

        if (windowMap == need) {
            return true;
        }

        // Sliding window
        while (high + 1 < n) {
            // Remove left character
            windowMap[s2[low]]--;

            if (windowMap[s2[low]] == 0) {
                windowMap.erase(s2[low]);
            }

            low++;

            // Add new right character
            high++;
            windowMap[s2[high]]++;

            if (windowMap == need) {
                return true;
            }
        }

        return false;
    }
};