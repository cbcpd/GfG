
class Solution {
public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n = arr.size();
        if (n < 3) return {};

        vector<int> smaller(n, -1);
        vector<int> greater(n, -1);

        // Step 1: Fill smaller[]
        int min_idx = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] <= arr[min_idx]) {
                min_idx = i;
            } else {
                smaller[i] = min_idx;
            }
        }

        // Step 2: Fill greater[]
        int max_idx = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= arr[max_idx]) {
                max_idx = i;
            } else {
                greater[i] = max_idx;
            }
        }

        // Step 3: Find valid subsequence
        for (int i = 0; i < n; i++) {
            if (smaller[i] != -1 && greater[i] != -1) {
                return {arr[smaller[i]], arr[i], arr[greater[i]]};
            }
        }

        return {};
    }
};