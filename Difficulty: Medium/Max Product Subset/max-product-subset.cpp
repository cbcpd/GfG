const int mod = 1e9 + 7;

class Solution {
  public:
    int findMaxProduct(vector<int>& arr) {
        int n = arr.size();
        
        // Edge case: If there is only one element, we must return it directly.
        if (n == 1) return arr[0]; 

        int ans = *max_element(arr.begin(), arr.end());
        long long temp = 1; // Good practice to declare temp as long long initially
        bool pos = false;
        vector<int> neg;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] > 0) {
                temp = (temp * arr[i]) % mod;
                pos = true;
            }
            else if(arr[i] < 0) {
                neg.push_back(arr[i]);
            }
        }
        
        sort(neg.begin(), neg.end());
        
        // If there's an odd number of negatives, remove the one closest to 0
        while(neg.size() % 2 != 0) {
            neg.pop_back(); 
        }
        
        // If we have any positive numbers OR pairs of negative numbers, 
        // the computed product is our final answer.
        if(pos || neg.size() > 0) {
            for(int x : neg) {
                temp = (temp * abs(x)) % mod;
            }
            return temp; 
        }
        
        // Fallback: This only hits if the array has no positives and 
        // 1 or 0 negatives (e.g., [0, 0, 0] or [0, -5]). 
        // The raw max_element is the correct answer here.
        return ans;
    }
};

