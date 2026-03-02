
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        if (n < 3) return 0;

        int l = 0, r = n - 1;
        int left_max=arr[0],right_max=arr[n-1];
        long long ans = 0;

        while (l <= r) {
            if (left_max <= right_max) {
                left_max = max(left_max, arr[l]);
                ans += (long long)(left_max - arr[l]);
                ++l;
            } else {
                right_max = max(right_max, arr[r]);
                ans += (long long)(right_max - arr[r]);
                --r;
            }
        }
        return ans;
    }
};