class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        int n = ransomNote.size();
        int m = magazine.size();

        unordered_map<char, int> need;
        unordered_map<char, int> have;

        // Count required characters
        for(int i = 0; i < n; i++){
            need[ransomNote[i]]++;
        }

        // Count available characters
        for(int i = 0; i < m; i++){
            have[magazine[i]]++;
        }

        // Check whether magazine has enough characters
        for(auto i : need){

            char c = i.first;
            int fneed = i.second;
            int fhave = have[c];

            if(fhave < fneed){
                return false;
            }
        }

        return true;
    }
};