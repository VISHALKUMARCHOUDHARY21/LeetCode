class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int low = 0;
        int high = k -1;
        double ans = INT_MIN;
        int n = nums.size();
        int sum = 0;
        for(int i = low ;i<= high;i++){
            sum += nums[i];
        }
        double avg = (double)sum/k;
        ans = max(ans,avg);

        while(high +1<n){
            sum -= nums[low];
            low++;
            high++;
            sum += nums[high];
            avg = (double)sum/k;
            ans = max(ans,avg);

        }
        return ans;
    }
};