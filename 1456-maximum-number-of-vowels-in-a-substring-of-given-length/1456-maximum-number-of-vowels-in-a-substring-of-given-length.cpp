class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int n = s.length();

        int low = 0;
        int high = k - 1;
        int count = 0;
        int res = 0;

        // Count vowels in the first window
        for (int i = low; i <= high; i++) {
            if (isVowel(s[i])) {
                count++;
            }
        }

        res = count;

        // Slide the window
        while (high + 1 < n) {
            // Remove the character leaving the window
            low++;
            if (isVowel(s[low - 1])) {
                count--;
            }

            // Add the new character entering the window
            high++;
            if (isVowel(s[high])) {
                count++;
            }

            res = max(res, count);
        }

        return res;
    }
};