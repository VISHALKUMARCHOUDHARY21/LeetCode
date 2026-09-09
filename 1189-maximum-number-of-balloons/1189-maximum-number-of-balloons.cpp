class Solution {
public:
    int maxNumberOfBalloons(string text) {

        unordered_map<char,int> freq;

        // Count characters in text
        for(char c : text) {
            freq[c]++;
        }

        // Characters required for one "balloon"
        unordered_map<char,int> required;
        required['b'] = 1;
        required['a'] = 1;
        required['l'] = 2;
        required['o'] = 2;
        required['n'] = 1;

        int res = INT_MAX;

        // Check how many balloons each character can make
        for(auto i : required) {

            char c = i.first;
            int need = i.second;
            int have = freq[c];

            int times = have / need;

            res = min(res, times);
        }

        return res;
    }
};