class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();

        int targetSum = k * threshold;

        int low = 0;
        int high = k - 1;
        int sum = 0;
        int res = 0;

        // First window
        for (int i = low; i <= high; i++) {
            sum += arr[i];
        }

        if (sum >= targetSum) {
            res++;
        }

        // Sliding window
        while (high + 1 < n) {

            sum -= arr[low];
            low++;

            high++;
            sum += arr[high];

            if (sum >= targetSum) {
                res++;
            }
        }

        return res;
    }
};