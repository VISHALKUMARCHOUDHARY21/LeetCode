class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;

        int n = s.size();
        int m = p.size();

        if (m > n) {
            return res;
        }

        unordered_map<char, int> need;
        unordered_map<char, int> wmap;

        // Frequency of p
        for (int i = 0; i < m; i++) {
            need[p[i]]++;
        }

        int low = 0;
        int high = m - 1;

        // First window
        for (int i = low; i <= high; i++) {
            wmap[s[i]]++;
        }

        // Check first window
        if (wmap == need) {
            res.push_back(low);
        }

        // Slide the window
        while (high + 1 < n) {

            // Remove left character
            wmap[s[low]]--;

            if (wmap[s[low]] == 0) {
                wmap.erase(s[low]);
            }

            low++;

            // Add new right character
            high++;
            wmap[s[high]]++;

            // Check current window
            if (wmap == need) {
                res.push_back(low);
            }
        }

        return res;
    }
};