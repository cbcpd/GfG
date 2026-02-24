
class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
      int n = a1.size();
        
        // The prefix sum can range from -n to +n. 
        // We use an array of size 2n + 1 to map sums to indices.
        // Initialize with -2 to indicate "unseen" sums.
        vector<int> first_occurrence(2 * n + 1, -2);
        
        int max_len = 0;
        int prefix_sum = 0;
        
        // Base case: A prefix sum of 0 is conceptually seen at index -1 
        // (before the array starts). The + n is our index offset.
        first_occurrence[0 + n] = -1;
        
        for (int i = 0; i < n; i++) {
            // Update the running prefix difference
            prefix_sum += (a1[i] - a2[i]);
            
            // Apply the offset to handle negative prefix sums safely in an array
            int target_index = prefix_sum + n;
            
            // If we have seen this prefix sum before
            if (first_occurrence[target_index] != -2) {
                // Calculate the span length and update the maximum
                int current_len = i - first_occurrence[target_index];
                max_len = max(max_len, current_len);
            } else {
                // Otherwise, record the first time we've seen this sum
                first_occurrence[target_index] = i;
            }
        }
        
        return max_len;
        
    }
};
//GFG POTD solution for 24 February