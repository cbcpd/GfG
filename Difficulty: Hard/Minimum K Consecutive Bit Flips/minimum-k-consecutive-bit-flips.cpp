
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> flipped(n, 0);  
        int flip = 0;                
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (i >= k) {
                flip ^= flipped[i - k]; 
            }
            if ((arr[i] ^ flip) == 0) { 
                if (i + k > n) return -1; 
                ans++;
                flip ^= 1;          
                flipped[i] = 1;     
            }
        }
        return ans;
    }
};