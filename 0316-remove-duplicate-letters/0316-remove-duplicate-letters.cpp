class Solution {
public:
    string removeDuplicateLetters(string s) {

        // 1. Store the last position of every character
        vector<int> last(26);

        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        // 2. To know whether a character is already in stack
        vector<bool> used(26, false);

        stack<char> st;

        // 3. Process every character
        for (int i = 0; i < s.size(); i++) {

            char ch = s[i];

            // Already present in stack
            if (used[ch - 'a']) {
                continue;
            }

            // Remove larger characters if they appear again later
            while (!st.empty() &&
                   st.top() > ch &&
                   last[st.top() - 'a'] > i) {

                used[st.top() - 'a'] = false;
                st.pop();
            }

            // Add current character
            st.push(ch);
            used[ch - 'a'] = true;
        }

        // 4. Convert stack into answer
        string ans;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // Stack gives reverse order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};