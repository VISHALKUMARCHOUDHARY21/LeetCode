class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        int low = 0;
        int high = 0;

        long long sum = 0;
        long long maxSum = 0;

        while (high < n) {

            // Add current element
            mp[nums[high]]++;
            sum += nums[high];

            // If duplicate exists, shrink window
            while (mp[nums[high]] > 1) {
                mp[nums[low]]--;
                sum -= nums[low];
                low++;
            }

            // Window size is k
            if (high - low + 1 == k) {
                maxSum = max(maxSum, sum);

                // Move window forward
                mp[nums[low]]--;
                sum -= nums[low];
                low++;
            }

            high++;
        }

        return maxSum;
    }
};