class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int total = 0;
        for(int x : cardPoints)
            total += x;

        int windowSize = n - k;

        int windowSum = 0;

        for(int i = 0; i < windowSize; i++)
            windowSum += cardPoints[i];

        int minSum = windowSum;

        int low = 0;

        for(int high = windowSize; high < n; high++) {
            windowSum += cardPoints[high];
            windowSum -= cardPoints[low];
            low++;

            minSum = min(minSum, windowSum);
        }

        return total - minSum;
    }
};