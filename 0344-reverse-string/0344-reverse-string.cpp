class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int n = s.size();
        int right = n-1;
        while(left < right){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
        for(int i = 0;i<n;i++){
            cout<<s[i]<<" ";
        }
    }
};