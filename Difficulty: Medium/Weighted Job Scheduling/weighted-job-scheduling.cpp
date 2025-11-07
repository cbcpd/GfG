
class Solution {
  public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1]; // sort by end time
    }
    int maxProfit(vector<vector<int>> &jobs) {
        // code here
         int n = jobs.size();
        sort(jobs.begin(), jobs.end(), cmp);

        vector<int> dp(n);
        dp[0] = jobs[0][2]; // profit of first job

        for (int i = 1; i < n; i++) {
            int include = jobs[i][2];
            
            // Find last job that doesn't conflict using binary search
            int l = 0, r = i - 1, last = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (jobs[mid][1] <= jobs[i][0]) {
                    last = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if (last != -1)
                include += dp[last];
            
            dp[i] = max(dp[i - 1], include);
        }

        return dp[n - 1];
    }
};