class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int min = INT_MAX;
        int max = INT_MIN;
        int res = 1;
        for(int i = 0;i<n;i++){
            if(nums[i] < min){
                min = nums[i];
            }
        }
        for(int i = 0;i<n;i++){
            if(nums[i] > max){
                max = nums[i];
            }
        }
        for(int i = 2;i <= min;i++){
            if(min % i ==0  && max % i == 0){
                res = i;
            }
        }
        return res;
    }
};